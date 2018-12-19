//
//  WindowController.swift
//  Junecloud Automator Actions
//
//  Created by Mike Piontek on 12/19/18.
//  Copyright © 2018 Junecloud LLC. All rights reserved.
//

import Cocoa

class WindowController: NSWindowController {

    override func windowDidLoad() {
        super.windowDidLoad()
        guard let window = window else { return }
        if #available(macOS 10.13, *) {
			// Handled in the storyboard
		} else {
			window.titleVisibility = .hidden
			window.titlebarAppearsTransparent = true
		}
		window.center()
    }

}
