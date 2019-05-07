//
//  String+SHA1.swift
//  Junecloud Toolbox
//
//  Created by Mike Piontek on 12/13/17.
//  Copyright © 2017 Junecloud LLC. All rights reserved.
//

import Foundation

extension Data {

    var sha1: String {
        let data = self
        var digest = [UInt8](repeating: 0, count:Int(CC_SHA1_DIGEST_LENGTH))
        data.withUnsafeBytes {
            _ = CC_SHA1($0.baseAddress, CC_LONG(data.count), &digest)
        }
        let hexBytes = digest.map { String(format: "%02hhx", $0) }
        return hexBytes.joined()
    }

}
