//
//  ViewController.swift
//  Junecloud Automator Actions
//
//  Created by Mike Piontek on 1/18/17.
//  Copyright © 2017 Junecloud LLC. All rights reserved.
//

import Cocoa

class ViewController: NSViewController {

	@IBAction func openAutomator(_ sender: NSButton) {
		let workspace = NSWorkspace.shared
		workspace.launchApplication(withBundleIdentifier: "com.apple.Automator", options: NSWorkspace.LaunchOptions.default, additionalEventParamDescriptor: nil, launchIdentifier: nil)
	}

	@IBAction func installService(_ sender: NSButton) {
		let identifier: String
		switch (sender.tag) {
			case 0: identifier = "Save for Web"
				break
			case 1: identifier = "Make Names Web-Friendly"
				break
			case 2: identifier = "Create Clean Archive"
				break
			case 3: identifier = "Create Symbolic Link"
				break
			case 4: identifier = "Hide Extensions"
				break
			default: identifier = ""
				break
		}
		if (identifier.isEmpty == false) {
			installService(identifier)
		} else {
			NSLog("Unrecognized tag \(sender.tag)")
		}
	}

	private func installService(_ name: String) {
		let bundle = Bundle.main
		let workspace = NSWorkspace.shared
		guard let servicePath = bundle.path(forResource: name, ofType: "workflow") else { return }
		workspace.openFile(servicePath)
	}

}
