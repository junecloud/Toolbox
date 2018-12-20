//
//  SafariExtensionHandler.swift
//  Copy Short Link
//
//  Created by Mike Piontek on 12/19/18.
//  Copyright © 2018 Junecloud LLC. All rights reserved.
//

import SafariServices

class SafariExtensionHandler: SFSafariExtensionHandler {

	override func messageReceived(withName messageName: String, from page: SFSafariPage, userInfo: [String : Any]?) {
		if messageName == "processResult" {

			let urlString = userInfo?["url"] as? String ?? ""
			let pasteboard = NSPasteboard.general
			pasteboard.clearContents()
			pasteboard.setString(urlString, forType: .string)
			page.dispatchMessageToScript(withName: "showResult", userInfo: userInfo)

		} else {

			NSLog("Unexpected message name: \(messageName)")

		}
	}

	override func validateToolbarItem(in window: SFSafariWindow, validationHandler: @escaping ((Bool, String) -> Void)) {
		window.getActiveTab { tab in
			guard let tab = tab else {
				validationHandler(false, "")
				return
			}
			tab.getActivePage { page in
				guard let page = page else {
					validationHandler(false, "")
					return
				}
				page.getPropertiesWithCompletionHandler { properties in
					let hasURL = (properties?.url != nil)
					validationHandler(hasURL, "")
				}
			}
		}
	}

	override func toolbarItemClicked(in window: SFSafariWindow) {
		window.getActiveTab { tab in
			tab?.getActivePage { page in
				page?.dispatchMessageToScript(withName: "copyShortLink", userInfo: nil)
			}
		}
	}

	override func validateContextMenuItem(withCommand command: String, in page: SFSafariPage, userInfo: [String : Any]? = nil, validationHandler: @escaping (Bool, String?) -> Void) {
		page.getPropertiesWithCompletionHandler { properties in
			let hasURL = (properties?.url != nil)
			let hideMenu = (hasURL == false)
			validationHandler(hideMenu, nil)
		}
	}

	override func contextMenuItemSelected(withCommand command: String, in page: SFSafariPage, userInfo: [String : Any]? = nil) {
		page.dispatchMessageToScript(withName: command, userInfo: userInfo)
	}

}
