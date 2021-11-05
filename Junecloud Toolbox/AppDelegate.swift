//
//  AppDelegate.swift
//  Junecloud Toolbox
//
//  Created by Mike Piontek on 1/18/17.
//  Copyright © 2017 Junecloud LLC. All rights reserved.
//

import Cocoa
import SafariServices.SFSafariApplication
import os.log

@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate {

	public static let automatorIdentifier = "com.apple.Automator"

	public static let safariIdentifier = "com.apple.Safari"

	public static let safariExtensionIdentifier = "com.junecloud.Toolbox.CopyShortLink"

	private static let log: OSLog = {
	 	return OSLog(subsystem: "com.junecloud.Toolbox", category: "Application")
	}()

	var mainWindowController: WindowController? {
		return NSApplication.shared.mainWindow?.windowController as? WindowController
	}

	var aboutWindowController: JUNAboutWindowController?

	func applicationDidFinishLaunching(_ aNotification: Notification) {
		checkForOldVersions()
	}

	func applicationShouldTerminateAfterLastWindowClosed(_ sender: NSApplication) -> Bool {
		return true
	}

	static func openAutomator() {
		let workspace = NSWorkspace.shared
		workspace.launchApplication(withBundleIdentifier: AppDelegate.automatorIdentifier, options: NSWorkspace.LaunchOptions.default, additionalEventParamDescriptor: nil, launchIdentifier: nil)
	}

	static func showServicesFolder() {
		let workspace = NSWorkspace.shared
		guard let url = URL.userServicesFolder else { return }
		workspace.open(url)
	}

	static func showFinderExtensions() {
		let url = URL(fileURLWithPath: "/System/Library/PreferencePanes/Extensions.prefPane")
		NSWorkspace.shared.open(url)

	}

	static func openSafari() {
		let workspace = NSWorkspace.shared
		workspace.launchApplication(withBundleIdentifier: AppDelegate.safariIdentifier, options: NSWorkspace.LaunchOptions.default, additionalEventParamDescriptor: nil, launchIdentifier: nil)
	}

	static func openSafariPreferences() {
		SFSafariApplication.showPreferencesForExtension(withIdentifier: AppDelegate.safariExtensionIdentifier) { error in
			if let error = error {
				os_log("Error opening Safari preferences: %@", log: AppDelegate.log, type: .error, error as CVarArg)
			}
		}
	}

	@IBAction func showAbout(_ sender: Any?) {
		let controller = JUNAboutWindowController.instantiate()
		aboutWindowController = controller
		controller?.showWindow(sender)
	}

	@IBAction func openAutomator(_ sender: Any?) {
		AppDelegate.openAutomator()
	}

	@IBAction func showServicesFolder(_ sender: Any?) {
		AppDelegate.showServicesFolder()
	}

	@IBAction func showFinderExtensions(_ sender: Any?) {
		AppDelegate.showFinderExtensions()
	}

	@IBAction func openSafari(_ sender: Any?) {
		AppDelegate.openSafari()
	}

	@IBAction func openSafariPreferences(_ sender: Any?) {
		AppDelegate.openSafariPreferences()
	}

	@IBAction func showHelp(_ sender: Any?) {
		let workspace = NSWorkspace.shared
		let urlString = "https://junecloud.com/support/junecloud-toolbox/"
		guard let url = URL(string: urlString) else { return }
		workspace.open(url)
	}

	private func checkForOldVersions() {

		guard let homeURL = URL.userHomeFolder else { return }
		let automatorURL = homeURL.appendingPathComponents("Library","Automator")
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

extension AppDelegate: NSMenuDelegate {

	func menuNeedsUpdate(_ menu: NSMenu) {
		let selectedIndex = mainWindowController?.selectedSectionIndex ?? 0
		let items = menu.items
		for item in items {
			guard item.action == #selector(WindowController.showSection(_:)) else { continue }
			item.state = (selectedIndex == item.tag) ? .on : .off
		}
	}

}
