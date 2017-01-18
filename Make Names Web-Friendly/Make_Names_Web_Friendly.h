//
//  Make_Names_Web_Friendly.h
//  Make Names Web-Friendly
//
//  Created by Mike Piontek on 11/20/12.
//  Copyright (c) 2012 Junecloud LLC. All rights reserved.
//

#import <Automator/AMBundleAction.h>

@interface Make_Names_Web_Friendly : AMBundleAction

@property (nonatomic, strong) NSMutableDictionary *replacements;
@property (nonatomic) NSInteger convertSpacesTo;
@property (nonatomic) NSInteger convertCaseTo;
@property (nonatomic) BOOL removePeriods;

- (id)runWithInput:(id)input fromAction:(AMAction *)anAction error:(NSDictionary **)errorInfo;
- (NSString *)friendlyPath:(NSString *)path recursive:(BOOL)recursive error:(NSError **)error;
- (IBAction)openSite:(id)sender;

@end