//
//  AutomatorViewController.swift
//  Junecloud Automator Actions
//
//  Created by Mike Piontek on 1/18/17.
//  Copyright © 2017 Junecloud LLC. All rights reserved.
//

import Cocoa

class AutomatorViewController: NSViewController {

	@IBOutlet public var gridView: NSGridView?

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
		AppDelegate.openAutomator()
	}

	@IBAction func showServices(_ sender: Any?) {
		AppDelegate.showServices()
	}

	@IBAction func installService(_ sender: NSButton) {
		let index = sender.tag
		if let name = serviceNameForIndex(index) {
			installService(named: name)
		} else {
			NSLog("Unrecognized index \(index)")
		}
	}

	private func serviceNameForIndex(_ index: Int) -> String? {
		switch index {
			case 0: return "Save for Web"
			case 1: return "Make Names Web-Friendly"
			case 2: return "Create Clean Archive"
			case 3: return "Create Symbolic Link"
			case 4: return "Hide Extensions"
			default: return nil
		}
	}

	private func sourceURLForService(named name: String) -> URL? {
		return Bundle.main.url(forResource: name, withExtension: "workflow")
	}

	private func installURLForService(named name: String) -> URL? {
		guard let servicesURL = URL.servicesFolder else { return nil }
		return servicesURL.appendingPathComponent(name).appendingPathExtension("workflow")
	}

	private func updateServices() {

		guard let gridView = gridView else { return }

		let fileManager = FileManager.default
		let controlSize = NSControl.ControlSize.small
		let fontSize = NSFont.systemFontSize(for: controlSize)
		let font = NSFont.systemFont(ofSize: fontSize)

		var statusViews: [NSView] = []

		for index in 0..<gridView.numberOfRows {

			// For some reason removing a column doesn't remove its subviews
			let cell = gridView.cell(atColumnIndex: 1, rowIndex: index)
			cell.contentView?.removeFromSuperview()

			guard let name = serviceNameForIndex(index),
			 	let url = installURLForService(named: name) else {
				statusViews.append(NSGridCell.emptyContentView)
				continue
			}

			let isInstalled = fileManager.fileExists(atPath: url.path)
			let isVerified = verifyInstalledService(named: name, url: url)
			if isVerified && isInstalled {

				let title = NSLocalizedString("✓ Installed ", comment: "")
				let label = NSTextField(labelWithString: title)
				label.font = font
				label.textColor = NSColor.disabledControlTextColor
				statusViews.append(label)

			} else {

				let title = isInstalled ? NSLocalizedString("Update", comment: "") :  NSLocalizedString("Install", comment: "")
				let button = NSButton(title: title, target: self, action: #selector(installService(_:)))
				button.font = font
				button.controlSize = controlSize
				button.tag = index
				button.setContentHuggingPriority(.defaultHigh - 5, for: .horizontal)
				button.setContentCompressionResistancePriority(.defaultHigh + 5, for: .vertical)
				statusViews.append(button)

			}

		}

		gridView.removeColumn(at: 1)
		gridView.insertColumn(at: 1, with: statusViews)

	}

	private func installService(named name: String) {

		guard let sourceURL = sourceURLForService(named: name) else { return }
		guard let installURL = installURLForService(named: name) else { return }
		let fileManager = FileManager.default

		if fileManager.fileExists(atPath: installURL.path) {
			let alert = NSAlert()
			alert.alertStyle = .critical
			alert.messageText = String(format: NSLocalizedString("Replace the service named “%@”?", comment: ""), name)
			alert.informativeText = NSLocalizedString("If you modified the service then your changes will be lost. The old service will be moved to the Trash.", comment: "")
			alert.addButton(withTitle: NSLocalizedString("Replace", comment: ""))
			alert.addButton(withTitle: NSLocalizedString("Cancel", comment: ""))
			let response = alert.runModal()
			if response == .alertFirstButtonReturn {
				do {
					try fileManager.trashItem(at: installURL, resultingItemURL: nil)
				} catch {
					NSLog("Error trashing existing service: \(error)")
					let alert = NSAlert(error: error)
					alert.runModal()
					return
				}
			} else {
				NSLog("Installation was cancelled by the user")
				return
			}
		}

		do {
			try fileManager.copyItem(at: sourceURL, to: installURL)
		} catch {
			NSLog("Error installing service: \(error)")
			let alert = NSAlert(error: error)
			alert.runModal()
		}
		updateServices()

	}

	private func verifyInstalledService(named name: String, url: URL) -> Bool {
		guard let bundledURL = sourceURLForService(named: name) else { return false }
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
