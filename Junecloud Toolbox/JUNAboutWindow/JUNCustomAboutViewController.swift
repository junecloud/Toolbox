//
//  JUNCustomAboutViewController.swift
//  JUNAboutWindow
//
//  Created by Mike Piontek on 6/16/18.
//  Copyright © 2018 Junecloud. All rights reserved.
//

import Cocoa

class JUNCustomAboutViewController: JUNAboutViewController {

	override var linkColor: NSColor? {
		if #available(macOS 10.13, *) {
			return NSColor(named: "junecloud link")
		}
		return NSColor(red: 0.173, green: 0.694, blue: 0.745, alpha: 1.000)
	}

}
