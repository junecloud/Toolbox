//
//  WindowController.swift
//  Junecloud Automator Actions
//
//  Created by Mike Piontek on 12/19/18.
//  Copyright © 2018 Junecloud LLC. All rights reserved.
//

import Cocoa

class WindowController: NSWindowController {

	private var tabViewController: NSTabViewController? {
		return contentViewController as? NSTabViewController
	}

    override func windowDidLoad() {
        super.windowDidLoad()
        guard let window = window else { return }
        if #available(macOS 10.13, *) {
			// Handled in the storyboard
		} else {
			window.titleVisibility = .hidden
		}
		window.center()
    }

	@IBAction func selectTab(_ sender: Any?) {
		guard let control = sender as? NSSegmentedControl else { return }
		let index = control.selectedSegment
		tabViewController?.selectedTabViewItemIndex = index
	}

}
