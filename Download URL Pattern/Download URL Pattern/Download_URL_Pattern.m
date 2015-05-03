//
//  Download_URL_Pattern.m
//  Download URL Pattern
//
//  Created by Mike Piontek on 11/20/12.
//  Copyright (c) 2012 Junecloud LLC. All rights reserved.
//

#import <OSAKit/OSAKit.h>
#import "Download_URL_Pattern.h"
#import "NSMutableArray+JUNAddOnce.h"

@implementation Download_URL_Pattern

- (id)runWithInput:(id)input fromAction:(AMAction *)anAction error:(NSDictionary **)errorInfo {

	NSString *downloadString = [[self parameters] valueForKey:@"downloadString"];
	NSString *downloadPath = [[[self parameters] valueForKey:@"downloadPath"] stringByExpandingTildeInPath];

	NSMutableArray *output = [NSMutableArray arrayWithCapacity:1];

	if (downloadString == nil || [downloadString isEqualToString:@""]) {
		for (NSURL *url in input) {
			NSDictionary *thisError = nil;
			NSArray *thisOutput = [self downloadURLPattern:[url absoluteString] toPath:downloadPath error:&thisError];
			if (thisOutput) {
				[output addObjectsFromArrayOnce:thisOutput];
			} else *errorInfo = thisError;
		}
	} else {
		NSDictionary *thisError = nil;
		NSArray *thisOutput = [self downloadURLPattern:downloadString toPath:downloadPath error:&thisError];
		if (thisOutput) {
			[output addObjectsFromArrayOnce:thisOutput];
		} else *errorInfo = thisError;
	}

	return output;

}

- (NSMutableArray *)downloadURLPattern:(NSString *)urlPattern toPath:(NSString *)path error:(NSDictionary **)errorInfo {

	NSMutableArray *output = [NSMutableArray arrayWithCapacity:1];

	if (urlPattern == nil || [urlPattern isEqualToString:@""]) return output;

	NSRegularExpression *regEx = [NSRegularExpression regularExpressionWithPattern:@"^https?://[^/]*/"
		options:NSRegularExpressionCaseInsensitive error:nil];
	NSRange urlMatch = [regEx rangeOfFirstMatchInString:urlPattern options:0
		range:NSMakeRange(0,[urlPattern length])];
	if (urlMatch.location == NSNotFound) {
		*errorInfo = @{
			OSAScriptErrorNumber: @(errOSASystemError),
			OSAScriptErrorMessage: @"The URL pattern must be a full URL, starting with http:// or https://"
		};
		return nil;
	}

	// Get the file names from the input string
	// Replace brackets with numbers, so File[00-99].jpg becomes File#1.jpg
	NSString *outputString = nil;
	NSRegularExpression *bracketPattern = [NSRegularExpression regularExpressionWithPattern:@"\\[[^]]*\\]"
		options:NSRegularExpressionCaseInsensitive error:nil];
	NSRange firstMatch = [bracketPattern rangeOfFirstMatchInString:urlPattern options:0
		range:NSMakeRange(0,[urlPattern length])];

	if (firstMatch.location != NSNotFound) {

		NSString *subString = [urlPattern substringWithRange:NSMakeRange(0,firstMatch.location)];
		NSRange firstSlash = [subString rangeOfString:@"/" options:NSBackwardsSearch range:NSMakeRange(0,firstMatch.location)];
		NSUInteger length = [urlPattern length]-firstSlash.location-1;
		outputString = [urlPattern substringWithRange:NSMakeRange(firstSlash.location+1,length)];

		NSString *replacedString = @"";
		NSUInteger beforeStart = 0;
		NSUInteger bracketCount = 0;
		NSArray *matches = [bracketPattern matchesInString:outputString options:0 range:NSMakeRange(0,[outputString length])];
		for (NSTextCheckingResult *match in matches) {
			bracketCount++;
			NSRange range = [match range];
			NSUInteger length = range.location-beforeStart;
			NSString *beforeString = [outputString substringWithRange:NSMakeRange(beforeStart,length)];
			replacedString = [replacedString stringByAppendingString:beforeString];
			NSString *numberString = [NSString stringWithFormat:@"#%ld",(unsigned long)bracketCount];
			replacedString = [replacedString stringByAppendingString:numberString];
			beforeStart = range.location+range.length;
		}

		if (beforeStart > 0) {
			NSUInteger length = [outputString length]-beforeStart;
			NSString *afterString = [outputString substringWithRange:NSMakeRange(beforeStart,length)];
			replacedString = [replacedString stringByAppendingString:afterString];
		}
		outputString = replacedString;

	}
	if (outputString == nil || [outputString isEqualToString:@""]) outputString = [urlPattern lastPathComponent];
	NSString *outputPath = [path stringByAppendingPathComponent:outputString];

	NSArray *attributes = @[
		urlPattern,@"--referer",urlPattern,@"--user-agent",@"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_8_2) AppleWebKit/536.26.17 (KHTML, like Gecko) Version/6.0.2 Safari/536.26.17",@"-o",outputPath
	];

	NSTask *task = [[NSTask alloc] init];
	[task setLaunchPath:@"/usr/bin/curl"];
	[task setArguments:attributes];
	[task setStandardInput:[NSPipe pipe]];
	[task setStandardOutput:[NSPipe pipe]];
	[task setStandardError:[NSPipe pipe]];
	[task launch];
	[task waitUntilExit];

	if ([task terminationStatus] == 0) {
		[output addObject:path];
	} else {
		NSData *errorData = [[[task standardError] fileHandleForReading] readDataToEndOfFile];
		NSString *errorString = [[NSString alloc] initWithData:errorData encoding:NSUTF8StringEncoding];
		*errorInfo = @{
			OSAScriptErrorNumber: @(errOSASystemError),
			OSAScriptErrorMessage: errorString
		};
	}

	return output;

}

- (IBAction)openSite:(id)sender {
	[[NSWorkspace sharedWorkspace] openURL:[NSURL URLWithString:@"http://junecloud.com/software/donate/"]];
}

@end
