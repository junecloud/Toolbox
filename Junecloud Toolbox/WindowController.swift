//
//  WindowController.swift
//  Junecloud Toolbox
//
//  Created by Mike Piontek on 12/19/18.
//  Copyright © 2018 Junecloud LLC. All rights reserved.
//

import Cocoa

class WindowController: NSWindowController {

	public var selectedSectionIndex: Int {
		return tabViewController?.selectedTabViewItemIndex ?? 0
	}

	private var tabViewController: NSTabViewController? {
		return contentViewController as? NSTabViewController
	}

    override func windowDidLoad() {
        super.windowDidLoad()
        updateTitle()
        guard let window = window else { return }
        if #available(macOS 10.13, *) {
			// Handled in the storyboard
		} else {
			window.titleVisibility = .hidden
		}
		if let view = window.contentView {
			// With resizing disabled, the window is too wide. If constraints are added,
			// the window is no longer centered, unless the size is set here.
			let size = view.fittingSize
			window.setContentSize(size)
		}
		window.center()
    }

	@IBAction func showMoreMenu(_ sender: Any?) {

		let index = tabViewController?.selectedTabViewItemIndex

		let menu = NSMenu(title: "More")

		let automatorItem = NSMenuItem(title: "Automator Actions", action: #selector(showSection), keyEquivalent: "")
		automatorItem.tag = 0
		automatorItem.state = (index == 0) ? .on : .off
		menu.addItem(automatorItem)

		let safariItem = NSMenuItem(title: "Safari Extension", action: #selector(showSection), keyEquivalent: "")
		safariItem.tag = 1
		safariItem.state = (index == 1) ? .on : .off
		menu.addItem(safariItem)

		guard let view = sender as? NSView else { return }
		let point = NSPoint(x: view.frame.origin.x + 7, y: view.frame.origin.y + view.frame.size.height)
		menu.popUp(positioning: nil, at: point, in: view)

	}

	@IBAction func showSection(_ sender: Any?) {
		guard let menuItem = sender as? NSMenuItem else { return }
		tabViewController?.selectedTabViewItemIndex = menuItem.tag
		updateTitle()
	}

	private func updateTitle() {
		window?.title = tabViewController?.title ?? ""
	}

}
