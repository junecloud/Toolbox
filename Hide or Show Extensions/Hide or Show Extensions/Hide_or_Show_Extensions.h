//
//  Hide_or_Show_Extensions.h
//  Hide or Show Extensions
//
//  Created by Mike Piontek on 11/19/12.
//  Copyright (c) 2012 Junecloud LLC. All rights reserved.
//

#import <Automator/AMBundleAction.h>

@interface Hide_or_Show_Extensions : AMBundleAction

- (id)runWithInput:(id)input fromAction:(AMAction *)anAction error:(NSDictionary **)errorInfo;
- (BOOL)showExtensions:(BOOL)showExtensions ofItemAtPath:(NSString *)path recursive:(BOOL)recursive error:(NSError **)error;
- (IBAction)openSite:(id)sender;

@end
