//
//  Save_for_Web.h
//  Save for Web
//
//  Created by Mike Piontek on 11/16/12.
//  Copyright (c) 2012 Junecloud LLC. All rights reserved.
//

#import <Automator/AMBundleAction.h>

typedef NS_ENUM(NSUInteger,JUNUseApp) {
    JUNUseAppBuiltIn,
    JUNUseAppPhotoshop
};

typedef NS_ENUM(NSUInteger,JUNFileType) {
    JUNFileTypeJPEG,
    JUNFileTypePNG,
    JUNFileTypeGIF
};

@interface Save_for_Web : AMBundleAction

@property (weak) IBOutlet NSButton *sharpenBox;

- (id)runWithInput:(id)input fromAction:(AMAction *)anAction error:(NSDictionary **)errorInfo;
- (IBAction)changedApplication:(id)sender;
- (IBAction)openSite:(id)sender;

@end