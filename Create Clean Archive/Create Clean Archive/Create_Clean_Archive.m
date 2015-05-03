//
//  Create_Clean_Archive.m
//  Create Clean Archive
//
//  Created by Mike Piontek on 11/19/12.
//  Copyright (c) 2012 Junecloud LLC. All rights reserved.
//

#define JUNCleanFilesSome		0
#define JUNCleanFilesAll		1

#import <OSAKit/OSAKit.h>
#import "Create_Clean_Archive.h"

@implementation NSFileManager (JUNCreatorCode)

- (NSString *)creatorCodeForPath:(NSString *)path {
	NSDictionary *attributes = [self attributesOfItemAtPath:path error:nil];
	NSString *code = NSFileTypeForHFSTypeCode([attributes fileHFSTypeCode]);
	return [code stringByTrimmingCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"'"]];
}

@end

@implementation Create_Clean_Archive

- (id)runWithInput:(id)input fromAction:(AMAction *)anAction error:(NSDictionary **)errorInfo {

	NSString *archiveName = [[[self parameters] valueForKey:@"archiveName"] stringByReplacingOccurrencesOfString:@"/" withString:@":"];
	NSString *archivePath = [[[self parameters] valueForKey:@"archivePath"] stringByExpandingTildeInPath];
	NSInteger cleanFiles = [[[self parameters] valueForKey:@"cleanFiles"] integerValue];
	BOOL deleteOriginals = [[[self parameters] valueForKey:@"deleteOriginals"] boolValue];

	NSMutableArray *output = [NSMutableArray arrayWithCapacity:1];

	if ([[[archiveName pathExtension] lowercaseString] isEqualToString:@"zip"]) archiveName = [archiveName stringByDeletingPathExtension];
	if ((archiveName == nil || [archiveName isEqualToString:@""])) archiveName = ([input count] > 1) ? @"archive" : nil;

	NSArray *cleanItems = @[@"*/.DS_Store",@"*/Icon\r",@"*.textClipping"];
	if (cleanFiles == JUNCleanFilesAll) cleanItems = @[@"*/.*",@"*/Icon\r",@"*.textClipping"];

	NSFileManager *fileManager = [NSFileManager defaultManager];

	for (NSString *path in input) {

		NSString *name = [path lastPathComponent];
		BOOL skip = NO;
		NSMutableArray *skipItems = nil;

		BOOL isDirectory = NO;
		if ([fileManager fileExistsAtPath:path isDirectory:&isDirectory]) {
			if (isDirectory) {
				skipItems = [NSMutableArray arrayWithCapacity:1];
				NSArray *subPaths = [fileManager subpathsOfDirectoryAtPath:path error:NULL];
				for (NSString *item in subPaths) {
					NSString *code = [fileManager creatorCodeForPath:[path stringByAppendingPathComponent:item]];
					if ([code isEqualToString:@"alis"] || [code isEqualToString:@"fdrp"]) { // alias or folder alias
						NSString *skipItem = [name stringByAppendingPathComponent:item];
						[skipItems addObject:skipItem];
					}
				}
			} else {
				NSString *code = [fileManager creatorCodeForPath:path];
				NSString *ext = [name pathExtension];
				if ([code isEqualToString:@"alis"] || // alias
					[code isEqualToString:@"fdrp"] || // folder alias
					[name isEqualToString:@"Icon\r"] ||
					[name isEqualToString:@".DS_Store"] ||
					[ext isEqualToString:@"textClipping"]) {
					skip = YES;
				} else if (cleanFiles == JUNCleanFilesAll &&
					[name hasPrefix:@"."]) {
					skip = YES;
				}
			}
		} else skip = YES;

		if (skip) continue;

		NSString *parentPath = [path stringByDeletingLastPathComponent];
		NSString *outputPath = archivePath;
		if (outputPath == nil || [outputPath isEqualToString:@""]) outputPath = parentPath;
		if (archiveName == nil) archiveName = [fileManager displayNameAtPath:path];
		NSString *outputFile = [self pathForPath:outputPath name:archiveName extension:@"zip" uniqueOrInPaths:output];

		NSMutableArray *attributes = [NSMutableArray arrayWithObjects:@"-r",@"-q",outputFile,name,@"-x",nil];
		[attributes addObjectsFromArray:cleanItems];
		[attributes addObjectsFromArray:skipItems];

		NSTask *task = [[NSTask alloc] init];
		[task setCurrentDirectoryPath:parentPath];
		[task setLaunchPath:@"/usr/bin/zip"];
		[task setArguments:attributes];
		[task setStandardInput:[NSPipe pipe]];
		[task setStandardOutput:[NSPipe pipe]];
		[task setStandardError:[NSPipe pipe]];
		[task launch];
		[task waitUntilExit];

		if ([task terminationStatus] == 0) {
			if (![output containsObject:outputFile]) [output addObject:outputFile];
			if (deleteOriginals && ![path isEqualToString:outputFile]) {
				NSError *error = nil;
				if (![fileManager removeItemAtPath:path error:&error]) NSLog(@"Error deleting file: %@ %@",error,[error userInfo]);
			}
		} else {
			NSData *errorData = [[[task standardError] fileHandleForReading] readDataToEndOfFile];
			NSString *errorString = [[NSString alloc] initWithData:errorData encoding:NSUTF8StringEncoding];
			*errorInfo = @{
				OSAScriptErrorNumber: @(errOSASystemError),
				OSAScriptErrorMessage: errorString
			};
		}


	}

	return output;

}

- (NSString *)pathForPath:(NSString *)path name:(NSString *)name extension:(NSString *)extension uniqueOrInPaths:(NSArray *)paths {
	NSInteger no = 0;
	NSString *basePath = [path stringByAppendingPathComponent:name];
	NSString *newPath = [basePath stringByAppendingPathExtension:extension];
	NSFileManager *fileManager = [NSFileManager defaultManager];
	while ([fileManager fileExistsAtPath:newPath] && ![paths containsObject:newPath]) {
		no++;
		newPath = [[NSString stringWithFormat:@"%@-%lu",basePath,no] stringByAppendingPathExtension:extension];
	}
	return newPath;
}

- (IBAction)openSite:(id)sender {
	[[NSWorkspace sharedWorkspace] openURL:[NSURL URLWithString:@"http://junecloud.com/software/donate/"]];
}

@end
