//
//  URL+HomeFolder.swift
//  Junecloud Toolbox
//
//  Created by Mike Piontek on 12/13/17.
//  Copyright © 2017 Junecloud LLC. All rights reserved.
//

import Foundation

extension URL {

	public static var userHomeFolder: URL? {
		guard let pw = getpwuid(getuid()) else { return nil }
		guard let dir = pw.pointee.pw_dir else { return nil }
		return URL(fileURLWithFileSystemRepresentation: dir, isDirectory: true, relativeTo: nil)
	}

	public static var userApplicationSupportFolder: URL? {
		guard var url = URL.userHomeFolder else { return nil }
		url.appendPathComponents("Library", "Application Support")
		return url
	}

	public static var userServicesFolder: URL? {
		guard var url = URL.userHomeFolder else { return nil }
		url.appendPathComponents("Library", "Services")
		return url
	}

	public mutating func appendPathComponents(_ components: String..., pathExtension: String? = nil) {
		for component in components {
			appendPathComponent(component)
		}
		if let pathExtension = pathExtension {
			appendPathExtension(pathExtension)
		}
	}

	public func appendingPathComponents(_ components: String..., pathExtension: String? = nil) -> URL {
		var url = self
		for component in components {
			url.appendPathComponent(component)
		}
		if let pathExtension = pathExtension {
			url.appendPathExtension(pathExtension)
		}
		return url
	}

}
