//
//  Create_Symbolic_Link.h
//  Create Symbolic Link
//
//  Created by Mike Piontek on 11/19/12.
//  Copyright (c) 2012 Junecloud LLC. All rights reserved.
//

#import <Automator/AMBundleAction.h>

@interface Create_Symbolic_Link : AMBundleAction

- (id)runWithInput:(id)input fromAction:(AMAction *)anAction error:(NSDictionary **)errorInfo;
- (IBAction)openSite:(id)sender;

@end
