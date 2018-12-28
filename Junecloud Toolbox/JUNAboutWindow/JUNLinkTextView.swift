//
//  JUNLinkTextView.swift
//  JUNAboutWindow
//
//  Created by Mike Piontek on 5/29/18.
//  Copyright © 2018 Junecloud LLC. All rights reserved.
//

import Cocoa

class JUNLinkTextView: NSTextView {

	private var notificationClipView: NSClipView?

	private var superClipView: NSClipView? {
		return superview as? NSClipView
	}

	override func viewWillMove(toSuperview newSuperview: NSView?) {
		super.viewWillMove(toSuperview: newSuperview)
		guard let clipView = notificationClipView else { return }
		clipView.postsBoundsChangedNotifications = false
		NotificationCenter.default.removeObserver(self, name: NSView.boundsDidChangeNotification, object: clipView)
		notificationClipView = nil
	}

	override func viewDidMoveToSuperview() {
		super.viewDidMoveToSuperview()
		guard let clipView = superClipView else { return }
		clipView.postsBoundsChangedNotifications = true
		NotificationCenter.default.addObserver(self, selector: #selector(boundsDidChange), name: NSView.boundsDidChangeNotification, object: clipView)
		notificationClipView = clipView
	}

	override func resetCursorRects() {
		super.resetCursorRects()
		NSObject.cancelPreviousPerformRequests(withTarget: self, selector: #selector(resetCursorRects), object: nil)

		guard let manager = layoutManager else { return }
		guard let container = textContainer	else { return }
		let containerOrigin = textContainerOrigin
		let string = attributedString()
		let range = NSMakeRange(0, string.length)

		string.enumerateAttribute(.link, in: range, options: []) { (value, range, stop) in
			guard value != nil else { return }
			let glyphRange = manager.glyphRange(forCharacterRange: range, actualCharacterRange: nil)
			var rectCount = 0
			let selectedRange = NSMakeRange(NSNotFound, 0)
			guard let rectArray = manager.rectArray(forGlyphRange: glyphRange, withinSelectedGlyphRange: selectedRange, in: container, rectCount: &rectCount) else { return }
			for i in 0..<rectCount {
				var glyphRect = rectArray[i]
				glyphRect.origin.x += containerOrigin.x
				glyphRect.origin.y += containerOrigin.y
				addCursorRect(glyphRect, cursor: NSCursor.pointingHand)
			}
		}
	}

	override func mouseUp(with event: NSEvent) {
		guard let url = url(for: event) else { return }
		NSWorkspace.shared.open(url)
	}

	deinit {
		NotificationCenter.default.removeObserver(self)
		NSObject.cancelPreviousPerformRequests(withTarget: self)
	}

	@objc private func boundsDidChange(_ notification: Notification) {
		NSObject.cancelPreviousPerformRequests(withTarget: self, selector: #selector(resetCursorRects), object: nil)
		perform(#selector(resetCursorRects), with: nil, afterDelay: 0.3)
	}

	private func url(for event: NSEvent) -> URL? {
		guard let manager = layoutManager else { return nil }
		guard let container = textContainer	else { return nil }
		let containerOrigin = textContainerOrigin
		let string = attributedString()
		var point = convert(event.locationInWindow, from: nil)

		// Convert view coordinates to container coordinates
		point.x -= containerOrigin.x
		point.y -= containerOrigin.y

		// Convert those coordinates to the nearest glyph index
		let glyphIndex = manager.glyphIndex(for: point, in: container)

		// Check if the mouse is actually over the glyph it's nearest to
		let glyphRange = NSMakeRange(glyphIndex, 1)
		let glyphRect = manager.boundingRect(forGlyphRange: glyphRange, in: container)
		guard NSPointInRect(point, glyphRect) else { return nil }

		// Convert the glyph index to a character index, and get the link attribute there
		let charIndex = manager.characterIndexForGlyph(at: glyphIndex)
		return string.attribute(.link, at: charIndex, effectiveRange: nil) as? URL
	}

}
