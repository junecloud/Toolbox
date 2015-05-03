//
//  Hide_or_Show_Extensions.m
//  Hide or Show Extensions
//
//  Created by Mike Piontek on 11/19/12.
//  Copyright (c) 2012 Junecloud LLC. All rights reserved.
//

#import <OSAKit/OSAKit.h>
#import "Hide_or_Show_Extensions.h"

@implementation Hide_or_Show_Extensions

- (id)runWithInput:(id)input fromAction:(AMAction *)anAction error:(NSDictionary **)errorInfo {

	BOOL showExtensions = ([[[self parameters] valueForKey:@"showExtensions"] integerValue] == 1) ? YES : NO;
	BOOL recursive = [[[self parameters] valueForKey:@"includeFilesInsideFolders"] boolValue];

	NSMutableArray *output = [NSMutableArray arrayWithCapacity:1];

	for (NSString *path in input) {
		NSError *error = nil;
		if ([self showExtensions:showExtensions ofItemAtPath:path recursive:recursive error:&error]) {
			[output addObject:path];
		} else {
			NSString *errorString = [error localizedDescription];
			if (!errorString) errorString = [NSString stringWithFormat:@"%@ cannot be changed.",[path lastPathComponent]];
			*errorInfo = @{
				OSAScriptErrorNumber: @(errOSASystemError),
				OSAScriptErrorMessage: errorString
			};
		}
	}

	return output;
}

- (BOOL)showExtensions:(BOOL)showExtensions ofItemAtPath:(NSString *)path recursive:(BOOL)recursive error:(NSError **)error {

	NSFileManager *fileManager = [NSFileManager defaultManager];
	BOOL isDirectory = NO;
	if ([fileManager fileExistsAtPath:path isDirectory:&isDirectory]) {
		if (isDirectory && recursive) {
			NSError *subPathsError = nil;
			NSArray *subPaths = [fileManager subpathsOfDirectoryAtPath:path error:&subPathsError];
			if (subPaths) {
				for (NSString *item in subPaths) {
					NSError *subPathError = nil;
					NSString *subPath = [path stringByAppendingPathComponent:item];
					// subpathsOfDirectoryAtPath:error: is recursive, so recursive should only be used once
					if (![self showExtensions:showExtensions ofItemAtPath:subPath recursive:NO error:&subPathError]) {
						if (error != NULL) *error = subPathError;
						return NO;
					}
				}
				return YES;
			} else {
				if (error != NULL) *error = subPathsError;
				return NO;
			}
		} else {
			NSError *attributesError = nil;
			NSNumber *hidden = (showExtensions) ? @NO : @YES;
			NSDictionary *attributes = @{ NSFileExtensionHidden: hidden };
			if (![fileManager setAttributes:attributes ofItemAtPath:path error:&attributesError]) {
				if (error != NULL) *error = attributesError;
				return NO;
			}
		}
	}
	return YES;

}

- (IBAction)openSite:(id)sender {
	[[NSWorkspace sharedWorkspace] openURL:[NSURL URLWithString:@"http://junecloud.com/software/donate/"]];
}

@end
