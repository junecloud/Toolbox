//
//  Download_URL_Pattern.h
//  Download URL Pattern
//
//  Created by Mike Piontek on 11/20/12.
//  Copyright (c) 2012 Junecloud LLC. All rights reserved.
//

#import <Automator/AMBundleAction.h>

@interface Download_URL_Pattern : AMBundleAction

- (id)runWithInput:(id)input fromAction:(AMAction *)anAction error:(NSDictionary **)errorInfo;
- (NSMutableArray *)downloadURLPattern:(NSString *)urlPattern toPath:(NSString *)path error:(NSDictionary **)errorInfo;
- (IBAction)openSite:(id)sender;

@end
