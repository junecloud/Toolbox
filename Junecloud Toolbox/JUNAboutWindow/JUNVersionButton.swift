//
//  JUNVersionButton.swift
//  JUNAboutWindow
//
//  Created by Mike Piontek on 5/29/18.
//  Copyright © 2018 Junecloud LLC. All rights reserved.
//

import Cocoa

class JUNVersionButton: NSButton {

	@IBInspectable var showsHandCursor: Bool = false

	override init(frame frameRect: NSRect) {
		super.init(frame: frameRect)
		commonSetup()
	}

	required init?(coder: NSCoder) {
		super.init(coder: coder)
		commonSetup()
	}

	override func resetCursorRects() {
		super.resetCursorRects()
		if showsHandCursor == true {
			addCursorRect(bounds, cursor: NSCursor.pointingHand)
		}
	}

	private func commonSetup() {
		focusRingType = .none
	}

}
