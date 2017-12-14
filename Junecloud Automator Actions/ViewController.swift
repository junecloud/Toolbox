//
//  ViewController.swift
//  Junecloud Automator Actions
//
//  Created by Mike Piontek on 1/18/17.
//  Copyright © 2017 Junecloud LLC. All rights reserved.
//

import Cocoa

class ViewController: NSViewController {

	@IBOutlet public var saveForWebStack: NSStackView?
	@IBOutlet public var makeNamesStack: NSStackView?
	@IBOutlet public var cleanArchiveStack: NSStackView?
	@IBOutlet public var symbolicLinkStack: NSStackView?
	@IBOutlet public var hideExtensionsStack: NSStackView?

	private var servicesURL: URL? {
		guard let homeURL = URL.actualHomeFolderURL else { return nil }
		return homeURL.appendingPathComponents("Library","Services")
	}

	override func viewWillAppear() {
		updateServices()
		NotificationCenter.default.addObserver(self, selector: #selector(applicationWillBecomeActive(_:)), name: NSApplication.willBecomeActiveNotification, object: nil)
	}

	override func viewDidDisappear() {
		NotificationCenter.default.removeObserver(self, name: NSApplication.willBecomeActiveNotification, object: nil)
	}

	@objc func applicationWillBecomeActive(_ notification: Notification) {
		updateServices()
	}

	@IBAction func openAutomator(_ sender: NSButton) {
		let workspace = NSWorkspace.shared
		workspace.launchApplication(withBundleIdentifier: "com.apple.Automator", options: NSWorkspace.LaunchOptions.default, additionalEventParamDescriptor: nil, launchIdentifier: nil)
	}

	@IBAction func installService(_ sender: NSButton) {
		let tag = sender.tag
		if let name = serviceNameForTag(tag) {
			installService(named: name)
		} else {
			NSLog("Unrecognized tag \(tag)")
		}
	}

	private func serviceNameForTag(_ tag: Int) -> String? {
		switch (tag) {
			case 0: return "Save for Web"
			case 1: return "Make Names Web-Friendly"
			case 2: return "Create Clean Archive"
			case 3: return "Create Symbolic Link"
			case 4: return "Hide Extensions"
			default: return nil
		}
	}

	private func updateServices() {

		let stacks = [
			saveForWebStack,
			makeNamesStack,
			cleanArchiveStack,
			symbolicLinkStack,
			hideExtensionsStack
		]

		guard let servicesURL = self.servicesURL else { return }
		let fileManager = FileManager.default
		let controlSize = NSControl.ControlSize.small
		let fontSize = NSFont.systemFontSize(for: controlSize)
		let font = NSFont.systemFont(ofSize: fontSize)

		for (tag, stack) in stacks.enumerated() {
			guard let stack = stack else { return }
			guard let name = serviceNameForTag(tag) else { continue }
			let url = servicesURL.appendingPathComponent(name+".workflow")
			if let subview = stack.views.last {
				stack.removeView(subview)
			}
			let installed = fileManager.fileExists(atPath: url.path)
			let verified = verifyInstalledService(named: name, url: url)
			if verified && installed {
				let title = NSLocalizedString("✓ Installed", comment: "")
				let label = NSTextField(labelWithString: title)
				label.font = font
				label.textColor = NSColor.disabledControlTextColor
				stack.addView(label, in: .trailing)
			} else {
				let title = (installed) ? NSLocalizedString("Update", comment: "") :  NSLocalizedString("Install", comment: "")
				let button = NSButton(title: title, target: self, action: #selector(installService(_:)))
				button.font = font
				button.controlSize = controlSize
				button.tag = tag
				button.setContentHuggingPriority(.defaultHigh, for: .horizontal)
				stack.addView(button, in: .trailing)
			}
		}
	}

	private func urlForService(named name: String) -> URL? {
		return Bundle.main.url(forResource: name, withExtension: "workflow")
	}

	private func installService(named name: String) {
		do {
			guard let url = urlForService(named: name) else { return }
			let fileManager = FileManager.default
			let tempFolderURL = try? fileManager.url(for: .itemReplacementDirectory, in: .userDomainMask, appropriateFor: servicesURL, create: true)
			guard let tempURL = tempFolderURL?.appendingPathComponent(url.lastPathComponent) else { return }
			try fileManager.copyItem(at: url, to: tempURL)
			NSWorkspace.shared.openFile(tempURL.path)
		} catch {
			NSLog("Error installing service: \(error)")
			return
		}
	}

	private func verifyInstalledService(named name: String, url: URL) -> Bool {
		guard let bundledURL = urlForService(named: name) else { return false }
		guard let bundledSHA1 = hashForService(at: bundledURL) else { return false }
		let installedSHA1 = hashForService(at: url)
		return (bundledSHA1 == installedSHA1)
	}

	private func hashForService(at url: URL) -> String? {
		do {
			let fileURL = url.appendingPathComponents("Contents","document.wflow")
			let data = try Data(contentsOf: fileURL)
			return data.sha1
		} catch {
			return nil
		}
	}

}
