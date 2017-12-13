//
//  AppDelegate.swift
//  Junecloud Automator Actions
//
//  Created by Mike Piontek on 1/18/17.
//  Copyright © 2017 Junecloud LLC. All rights reserved.
//

import Cocoa

@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate {

	var instructionsWindowController: NSWindowController?

	func applicationDidFinishLaunching(_ aNotification: Notification) {
		checkForOldVersions()
		showInstructions(nil)
	}

	@IBAction func showInstructions(_ sender: Any?) {
		if (self.instructionsWindowController == nil) {
			let storyboard = NSStoryboard(name: NSStoryboard.Name(rawValue: "Main"), bundle: nil)
			let controller = storyboard.instantiateController(withIdentifier: NSStoryboard.SceneIdentifier(rawValue: "instructionsWindow")) as? NSWindowController
			controller?.window?.center()
			self.instructionsWindowController = controller
		}
		self.instructionsWindowController?.showWindow(sender)
	}

	@IBAction func openAutomator(_ sender: Any?) {
		let workspace = NSWorkspace.shared
		workspace.launchApplication(withBundleIdentifier: "com.apple.Automator", options: NSWorkspace.LaunchOptions.default, additionalEventParamDescriptor: nil, launchIdentifier: nil)
	}

	@IBAction func showHelp(_ sender: Any?) {
		let workspace = NSWorkspace.shared
		let urlString = "https://junecloud.com/support/junecloud-automator-actions/"
		guard let url = URL(string: urlString) else { return }
		workspace.open(url)
	}

	private func checkForOldVersions() {

		guard let homeURL = URL.actualHomeFolderURL else { return }
		let libraryURL = homeURL.appendingPathComponent("Library")
		let automatorURL = libraryURL.appendingPathComponent("Automator")
		let actionNames = [
			"Create Clean Archive.action",
			"Create Symbolic Link.action",
			"Hide or Show Extensions.action",
			"Make Names Web-Friendly.action",
			"Save for Web.action"
		]
		var installedNames: [String] = []
		let fileManager = FileManager.default
		for name in actionNames	{
			let url = automatorURL.appendingPathComponent(name)
			if fileManager.fileExists(atPath: url.path) {
				installedNames.append(name)
			}
		}
		guard installedNames.count > 0 else { return }

		let alert = NSAlert()
		alert.messageText = NSLocalizedString("Remove old versions?", comment: "")
		let messageStart = NSLocalizedString("Older versions of some of the actions were found in your ~/Library/Automator/ folder:", comment: "")
		let messageEnd = NSLocalizedString("Removing them is recommended.", comment: "")
		var message = messageStart
		message.append("\n\n")
		message.append(installedNames.joined(separator: "\n"))
		message.append("\n\n")
		message.append(messageEnd)
		alert.informativeText = message
		alert.addButton(withTitle: NSLocalizedString("Move to Trash", comment: ""))
		alert.addButton(withTitle: NSLocalizedString("Cancel", comment: ""))
		let response = alert.runModal()

		if response == .alertFirstButtonReturn {
			for name in installedNames {
				let url = automatorURL.appendingPathComponent(name)
				try? fileManager.trashItem(at: url, resultingItemURL: nil)
			}
		}

	}

}

