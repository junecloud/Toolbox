//
//  Create_Symbolic_Link.m
//  Create Symbolic Link
//
//  Created by Mike Piontek on 11/19/12.
//  Copyright (c) 2012 Junecloud LLC. All rights reserved.
//

#import <OSAKit/OSAKit.h>
#import "Create_Symbolic_Link.h"

@implementation Create_Symbolic_Link

- (id)runWithInput:(id)input fromAction:(AMAction *)anAction error:(NSDictionary **)errorInfo {

	NSString *linkName = [[[self parameters] valueForKey:@"linkName"] stringByReplacingOccurrencesOfString:@"/" withString:@":"];
	NSString *linkPath = [[[self parameters] valueForKey:@"linkPath"] stringByExpandingTildeInPath];

	NSMutableArray *output = [NSMutableArray arrayWithCapacity:1];
	NSFileManager *fileManager = [NSFileManager defaultManager];

	for (NSString *path in input) {

		NSString *outputPath = linkPath;
		if (outputPath == nil || [outputPath isEqualToString:@""]) outputPath = [path stringByDeletingLastPathComponent];
		NSString *name = linkName;
		if (name == nil || [name isEqualToString:@""]) name = [path lastPathComponent];
		NSString *ext = [name pathExtension];
		if (ext == nil || [ext isEqualToString:@""]) ext = [path pathExtension];
		outputPath = [self pathForPath:outputPath name:name extension:ext unique:YES];

		NSError *error = nil;
		if ([fileManager createSymbolicLinkAtPath:outputPath withDestinationPath:path error:&error]) {
			[output addObject:outputPath];
		} else {
			NSString *errorString = [error localizedDescription];
			if (!errorString) errorString = [NSString stringWithFormat:@"The symbolic link for %@ could not be created.",[path lastPathComponent]];
			*errorInfo = @{
				OSAScriptErrorNumber: @(errOSASystemError),
				OSAScriptErrorMessage: errorString
			};
		}

		/* NSTask *task = [[NSTask alloc] init];
		[task setLaunchPath:@"/bin/ln"];
		[task setArguments:@[@"-s",path,outputPath]];
		[task setStandardInput:[NSPipe pipe]];
		[task setStandardOutput:[NSPipe pipe]];
		[task setStandardError:[NSPipe pipe]];
		[task launch];
		[task waitUntilExit];

		if ([task terminationStatus] == 0) {
			[output addObject:outputPath];
		} else {
			NSData *errorData = [[[task standardError] fileHandleForReading] readDataToEndOfFile];
			NSString *errorString = [[NSString alloc] initWithData:errorData encoding:NSUTF8StringEncoding];
			*errorInfo = @{
				OSAScriptErrorNumber: [NSNumber numberWithInt:errOSASystemError],
				OSAScriptErrorMessage: errorString
			};
		} */

	}

	return output;
}

- (NSString *)pathForPath:(NSString *)path name:(NSString *)name extension:(NSString *)extension unique:(BOOL)unique {
	NSInteger no = 0;
	if ([extension isEqualToString:@""]) extension = nil;
	NSString *basePath = [[path stringByAppendingPathComponent:name] stringByDeletingPathExtension];
	NSString *newPath = [NSString stringWithString:basePath];
	if (extension) newPath = [newPath stringByAppendingPathExtension:extension];
	if (unique) {
		NSFileManager *fileManager = [NSFileManager defaultManager];
		while ([fileManager fileExistsAtPath:newPath]) {
			no++;
			newPath = [NSString stringWithFormat:@"%@-%lu",basePath,no];
			if (extension) newPath = [newPath stringByAppendingPathExtension:extension];
		}
	}
	return newPath;
}

- (IBAction)openSite:(id)sender {
	[[NSWorkspace sharedWorkspace] openURL:[NSURL URLWithString:@"http://junecloud.com/software/donate/"]];
}

@end
