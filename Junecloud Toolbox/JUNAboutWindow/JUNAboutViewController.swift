//
//  JUNAboutViewController.swift
//  JUNAboutWindow
//
//  Created by Mike Piontek on 5/29/18.
//  Copyright © 2018 Junecloud LLC. All rights reserved.
//

import Cocoa

class JUNAboutViewController: NSViewController {

	internal var linkColor: NSColor? {
		return nil
	}

	internal var marketingVersionString: String {
		let key = "CFBundleShortVersionString"
		return Bundle.main.object(forInfoDictionaryKey: key) as? String ?? ""
	}

	internal var buildVersionString: String {
		let key = kCFBundleVersionKey as String
		return Bundle.main.object(forInfoDictionaryKey: key) as? String ?? ""
	}

	internal var versionShowsHandCursor: Bool {
		return false
	}

	internal var resourceSubdirectory: String? {
		return nil
	}

	@IBOutlet private var nameField: NSTextField?
	@IBOutlet private var versionButton: JUNVersionButton?
	@IBOutlet private var creditsView: NSScrollView?

    override func viewDidLoad() {
        super.viewDidLoad()

		let bundle = Bundle.main
		let name = bundle.object(forInfoDictionaryKey: kCFBundleNameKey as String) as? String
		nameField?.stringValue = name ?? ""

		loadCredits()
		updateVersionText()

		versionButton?.showsHandCursor = versionShowsHandCursor
    }

	deinit {
		NotificationCenter.default.removeObserver(self)
	}

	@IBAction func versionNumberWasPressed(_ sender: Any?) {
		// Does nothing by default
	}

	private func loadCredits() {
		do {
			let bundle = Bundle.main
			if let url = bundle.url(forResource: "Credits", withExtension: "html", subdirectory: resourceSubdirectory) {
				let string = try String(contentsOf: url)
				guard let data = string.data(using: .utf8) else { return }
				let baseURL = url.deletingLastPathComponent()
				let attributedString = NSAttributedString(html: data, baseURL: baseURL, documentAttributes: nil)
				showCredits(attributedString)
			} else if let url = bundle.url(forResource: "Credits", withExtension: "rtf", subdirectory: resourceSubdirectory) {
				let data = try Data(contentsOf: url)
				let attributedString = NSAttributedString(rtf: data, documentAttributes: nil)
				showCredits(attributedString)
			}
		} catch {
			NSLog("Error loading credits: \(error)")
		}
	}

	private func showCredits(_ attributedString: NSAttributedString?) {
		guard var string = attributedString else { return }
		guard let textView = creditsView?.documentView as? NSTextView else { return }
		textView.textContainerInset = CGSize(width: 40.0, height: 40.0)
		var attributes: [NSAttributedString.Key:Any] = [
			.cursor: NSCursor.pointingHand
		]
		if let color = linkColor {
			attributes[.foregroundColor] = color
		}
		textView.linkTextAttributes = attributes

		// Set all the text to the label color to support dark mode
		if let mutableString = string.mutableCopy() as? NSMutableAttributedString {
			let attributes: [NSAttributedString.Key:Any] = [
				.foregroundColor: NSColor.textColor
			]
			let range = NSRange(location: 0, length: mutableString.length)
			mutableString.addAttributes(attributes, range: range)
			string = mutableString
		}

		textView.textStorage?.setAttributedString(string)
	}

	@objc private func updateVersionText() {
		let version = marketingVersionString
		let build = buildVersionString
		versionButton?.title = "\(version) (\(build))"
	}

}
