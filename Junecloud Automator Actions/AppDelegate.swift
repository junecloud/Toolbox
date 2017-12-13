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

}

