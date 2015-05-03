//
//  Create_Clean_Archive.h
//  Create Clean Archive
//
//  Created by Mike Piontek on 11/19/12.
//  Copyright (c) 2012 Junecloud LLC. All rights reserved.
//

#import <Automator/AMBundleAction.h>

@interface Create_Clean_Archive : AMBundleAction

- (id)runWithInput:(id)input fromAction:(AMAction *)anAction error:(NSDictionary **)errorInfo;
- (NSString *)pathForPath:(NSString *)path name:(NSString *)name extension:(NSString *)extension uniqueOrInPaths:(NSArray *)paths;
- (IBAction)openSite:(id)sender;

@end
