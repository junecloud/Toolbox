//
//  JUNAboutWindowController.swift
//  JUNAboutWindow
//
//  Created by Mike Piontek on 5/29/18.
//  Copyright © 2018 Junecloud LLC. All rights reserved.
//

import Cocoa

class JUNAboutWindowController: NSWindowController {

	private var aboutViewController: JUNAboutViewController? {
		return contentViewController as? JUNAboutViewController
	}

    override func windowDidLoad() {
        super.windowDidLoad()
        guard let window = window else { return }
        if #available(macOS 10.13, *) {
			// Window is already styled correctly by the storyboard
        } else {
			window.styleMask = [.titled, .closable, .fullSizeContentView]
			window.titlebarAppearsTransparent = true
			window.titleVisibility = .hidden
		}
		window.center()
    }

	@objc static func instantiate() -> JUNAboutWindowController? {
		let storyboard = NSStoryboard(name: "About", bundle: nil)
		return storyboard.instantiateInitialController() as? JUNAboutWindowController
	}
	
}
