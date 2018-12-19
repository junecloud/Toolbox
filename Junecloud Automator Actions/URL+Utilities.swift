//
//  URL+Utilities.swift
//  Junecloud Automator Actions
//
//  Created by Mike Piontek on 12/13/17.
//  Copyright © 2017 Junecloud LLC. All rights reserved.
//

import Foundation

extension URL {

	static var actualHomeFolder: URL? {
		guard let pw = getpwuid(getuid()) else { return nil }
		guard let dir = pw.pointee.pw_dir else { return nil }
		return URL(fileURLWithFileSystemRepresentation: dir, isDirectory: true, relativeTo: nil)
	}

	static var servicesFolder: URL? {
		guard let homeURL = URL.actualHomeFolder else { return nil }
		return homeURL.appendingPathComponents("Library","Services")
	}

	public func appendingPathComponents(_ components: String...) -> URL {
		var url = self
		for component in components {
			url.appendPathComponent(component)
		}
		return url
	}

}
