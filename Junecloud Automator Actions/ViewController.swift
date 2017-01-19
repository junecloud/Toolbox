//
//  ViewController.swift
//  Junecloud Automator Actions
//
//  Created by Mike Piontek on 1/18/17.
//  Copyright © 2017 Junecloud LLC. All rights reserved.
//

import Cocoa

class ViewController: NSViewController {

	override func viewDidLoad() {
		super.viewDidLoad()
	}

	override func viewDidAppear() {

	}

	@IBAction func installService(_ sender: NSButton) {

	}

	private func installService(_ name: String) {
		let bundle = Bundle.main
		let workspace = NSWorkspace.shared()
		guard let servicePath = bundle.path(forResource: name, ofType: "workflow") else { return }
		workspace.openFile(servicePath)
	}

}

