//
//  Make_Names_Web_Friendly.m
//  Make Names Web-Friendly
//
//  Created by Mike Piontek on 11/20/12.
//  Copyright (c) 2012 Junecloud LLC. All rights reserved.
//

#define JUNConvertSpacesToDashes		0
#define JUNConvertSpacesToUnderscores	1
#define JUNConvertSpacesToNone			2

#define JUNConvertCaseToLower			0
#define JUNConvertCaseToNone			1

#define JUNConvertSymbolsNone			0
#define JUNConvertSymbolsSome			1
#define JUNConvertSymbolsMost			2

#import <OSAKit/OSAKit.h>
#import "Make_Names_Web_Friendly.h"

@implementation Make_Names_Web_Friendly

- (id)runWithInput:(id)input fromAction:(AMAction *)anAction error:(NSDictionary **)errorInfo {

	self.convertSpacesTo = [[[self parameters] valueForKey:@"convertSpacesTo"] integerValue];
	self.convertCaseTo = [[[self parameters] valueForKey:@"convertCaseTo"] integerValue];
	NSInteger convertSymbols = [[[self parameters] valueForKey:@"convertSymbols"] integerValue];
	BOOL convertUmlauts = [[[self parameters] valueForKey:@"convertUmlauts"] boolValue];
	self.removePeriods = [[[self parameters] valueForKey:@"removePeriods"] boolValue];
	BOOL recursive = [[[self parameters] valueForKey:@"includeFilesInsideFolders"] boolValue];

	NSDictionary *replacements = @{

		@"0": @"0",
		@"1": @"1",
		@"2": @"2",
		@"3": @"3",
		@"4": @"4",
		@"5": @"5",
		@"6": @"6",
		@"7": @"7",
		@"8": @"8",
		@"9": @"9",
		@"0": @"0",

		@"A": @"A",
		@"B": @"B",
		@"C": @"C",
		@"D": @"D",
		@"E": @"E",
		@"F": @"F",
		@"G": @"G",
		@"H": @"H",
		@"I": @"I",
		@"J": @"J",
		@"K": @"K",
		@"L": @"L",
		@"M": @"M",
		@"N": @"N",
		@"O": @"O",
		@"P": @"P",
		@"Q": @"Q",
		@"R": @"R",
		@"S": @"S",
		@"T": @"T",
		@"U": @"U",
		@"V": @"V",
		@"W": @"W",
		@"X": @"X",
		@"Y": @"Y",
		@"Z": @"Z",
		@"a": @"a",
		@"b": @"b",
		@"c": @"c",
		@"d": @"d",
		@"e": @"e",
		@"f": @"f",
		@"g": @"g",
		@"h": @"h",
		@"i": @"i",
		@"j": @"j",
		@"k": @"k",
		@"l": @"l",
		@"m": @"m",
		@"n": @"n",
		@"o": @"o",
		@"p": @"p",
		@"q": @"q",
		@"r": @"r",
		@"s": @"s",
		@"t": @"t",
		@"u": @"u",
		@"v": @"v",
		@"w": @"w",
		@"x": @"x",
		@"y": @"y",
		@"z": @"z",

		@"Â": @"A",
		@"Á": @"A",
		@"À": @"A",
		@"Ã": @"A",
		@"Ê": @"E",
		@"É": @"E",
		@"È": @"E",
		@"Î": @"I",
		@"Í": @"I",
		@"Ì": @"I",
		@"Ô": @"O",
		@"Ó": @"O",
		@"Ò": @"O",
		@"Õ": @"O",
		@"Û": @"U",
		@"Ú": @"U",
		@"Ù": @"U",
		@"Å": @"A",
		@"Ø": @"O",
		@"Ñ": @"N",
		@"Ç": @"C",
		@"â": @"a",
		@"á": @"a",
		@"à": @"a",
		@"ã": @"a",
		@"ê": @"e",
		@"é": @"e",
		@"è": @"e",
		@"î": @"i",
		@"í": @"i",
		@"ì": @"i",
		@"ô": @"o",
		@"ó": @"o",
		@"ò": @"o",
		@"õ": @"o",
		@"û": @"u",
		@"ú": @"u",
		@"ù": @"u",
		@"å": @"a",
		@"ø": @"o",
		@"ñ": @"n",
		@"ç": @"c",
		@"ı": @"i",
		@"I": @"I",

		@"œ": @"oe",
		@"Œ": @"OE",
		@"æ": @"ae",
		@"Æ": @"AE",
		@"ﬁ": @"fi",
		@"ﬂ": @"fl",
		@"ß": @"ss",

		@" ": @" ",
		@"_": @"_",
		@"-": @"-",
		@"—": @"-",
		@"–": @"-",
		@"/": @"-",
		@"[": @"-",
		@"]": @"-",
		@"{": @"-",
		@"}": @"-",
		@"(": @"-",
		@")": @"-",
		@":": @"-",
		@";": @"-",
		@"—": @"—",
		@"\\": @"-",

		@".": @".",
		@"…": @"..."

	};
	self.replacements = [NSMutableDictionary dictionaryWithCapacity:[replacements count]];
	[self.replacements addEntriesFromDictionary:replacements];

	if (convertUmlauts) {
		replacements = @{
			@"Ä": @"Ae",
			@"Ë": @"Ee",
			@"Ï": @"Ie",
			@"Ö": @"Oe",
			@"Ü": @"Ue",
			@"ä": @"ae",
			@"ë": @"ee",
			@"ï": @"ie",
			@"ö": @"oe",
			@"ü": @"ue"
		};
	} else {
		replacements = @{
			@"Ä": @"A",
			@"Ë": @"E",
			@"Ï": @"I",
			@"Ö": @"O",
			@"Ü": @"U",
			@"ä": @"a",
			@"ë": @"e",
			@"ï": @"i",
			@"ö": @"o",
			@"ü": @"u"
		};
	}
	[self.replacements addEntriesFromDictionary:replacements];

	if (convertSymbols == JUNConvertSymbolsSome) {
		replacements = @{
			@"&": @" and ",
			@"[@]": @" at ",
			@"°": @" ",
			@"%": @" ",
			@"$": @" ",
			@"¢": @" ",
			@"€": @" ",
			@"£": @" ",
			@"¥": @" ",
			@"™": @" ",
			@"®": @" ",
			@"©": @" ",
			@"": @" "
		};
	} else if (convertSymbols == JUNConvertSymbolsMost) {
		replacements = @{
			@"&": @" and ",
			@"[@]": @" at ",
			@"°": @" degrees ",
			@"%": @" percent ",
			@"$": @" dollars ",
			@"¢": @" cents ",
			@"€": @" euros ",
			@"£": @" pounds ",
			@"¥": @" yen ",
			@"™": @" TM ",
			@"®": @" registered trademark ",
			@"©": @" copyright ",
			@"": @" Apple "
		};
	} else {
		replacements = @{
			@"&": @" ",
			@"[@]": @" ",
			@"°": @" ",
			@"%": @" ",
			@"$": @" ",
			@"¢": @" ",
			@"€": @" ",
			@"£": @" ",
			@"¥": @" ",
			@"™": @" ",
			@"®": @" ",
			@"©": @" ",
			@"": @" "
		};
	}
	[self.replacements addEntriesFromDictionary:replacements];

	NSMutableArray *output = [NSMutableArray arrayWithCapacity:1];

	for (NSString *path in input) {

		NSError *error = nil;
		NSString *newPath = [self friendlyPath:path recursive:recursive error:&error];
		if (newPath) {
			[output addObject:newPath];
		} else {
// TODO: error!
		}

	}

	return output;
}

- (NSString *)friendlyPath:(NSString *)path recursive:(BOOL)recursive error:(NSError **)error {

	NSFileManager *fileManager = [NSFileManager defaultManager];
	BOOL isDirectory = NO;
	if ([fileManager fileExistsAtPath:path isDirectory:&isDirectory]) {
		if (isDirectory && recursive) {
			NSError *subPathsError = nil;
			NSArray *subPaths = [fileManager contentsOfDirectoryAtPath:path error:&subPathsError];
			if (subPaths) {
				for (NSString *item in subPaths) {
					NSError *subPathError = nil;
					NSString *subPath = [path stringByAppendingPathComponent:item];
					if (![self friendlyPath:subPath recursive:recursive error:&subPathError]) {
						if (error != NULL) *error = subPathError;
						return nil;
					}
				}
			} else {
				if (error != NULL) *error = subPathsError;
				return nil;
			}
		}
	}

	NSString *name = [path lastPathComponent];
	NSMutableString *newName = [NSMutableString stringWithString:name];
	NSString *parentPath = [path stringByDeletingLastPathComponent];

	// Skip files that start with a period
	if ([name hasPrefix:@"."]) return path;

	// Convert characters, symbols, and umlauts
	[newName enumerateSubstringsInRange:NSMakeRange(0,[newName length]) options:NSStringEnumerationByComposedCharacterSequences usingBlock:
		^(NSString *substring, NSRange substringRange, NSRange enclosingRange, BOOL *stop) {

			if ([substring isEqualToString:@"@"]) substring = @"[@]";
			NSString *newSubstring = [self.replacements valueForKey:[substring precomposedStringWithCanonicalMapping]];
			if (newSubstring == nil) newSubstring = @"";
			[newName replaceCharactersInRange:substringRange withString:newSubstring];

		}
	];

	if (self.removePeriods) {
		NSMutableString *bareName = (isDirectory) ? newName : [NSMutableString stringWithString:[newName stringByDeletingPathExtension]];
		NSString *ext = (isDirectory) ? nil : [newName pathExtension];
		NSRegularExpression *periodsRegEx = [NSRegularExpression regularExpressionWithPattern:@"\\.+" options:0 error:nil];
		[periodsRegEx replaceMatchesInString:bareName options:0 range:NSMakeRange(0,[bareName length]) withTemplate:@" "];
		if (ext) bareName = [NSMutableString stringWithString:[bareName stringByAppendingPathExtension:ext]];
		newName = bareName;
	}

	// Change and reduce spaces
	NSString *spacePattern = @"\\s+";
	NSString *spaceCharacter = @" ";
	if (self.convertSpacesTo == JUNConvertSpacesToDashes) {
		spacePattern = @"[\\s-]+";
		spaceCharacter = @"-";
	} else if (self.convertSpacesTo == JUNConvertSpacesToUnderscores) {
		spacePattern = @"[\\s_]+";
		spaceCharacter = @"_";
	}
	NSRegularExpression *spacesRegEx = [NSRegularExpression regularExpressionWithPattern:spacePattern options:0 error:nil];
	[spacesRegEx replaceMatchesInString:newName options:0 range:NSMakeRange(0,[newName length]) withTemplate:spaceCharacter];

	// Change the case
	if (self.convertCaseTo == JUNConvertCaseToLower) newName = [NSMutableString stringWithString:[newName lowercaseString]];

	NSString *ext = nil;
	if (!isDirectory) {
		ext = [newName pathExtension];
		if ([ext isEqualToString:@""]) ext = nil;
	}

	// Trim spaces from beginning and end
	NSString *trimmedName = (isDirectory) ? newName : [newName stringByDeletingPathExtension];
	trimmedName = [trimmedName stringByTrimmingCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"-_ "]];
	newName = [NSMutableString stringWithString:trimmedName];
	if (ext) ext = [ext stringByTrimmingCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"-_ "]];

	// Change the name to a temporary name
	// This works around a bug where only changing the case causes the rename to fail
	NSString *tempName = [NSString stringWithFormat:@"%@-%@",newName,[self generateUUID]];
	NSString *tempPath = [parentPath stringByAppendingPathComponent:tempName];
	if (ext) tempPath = [tempPath stringByAppendingPathExtension:ext];
	if (![fileManager moveItemAtPath:path toPath:tempPath error:nil]) tempPath = path;

	// Attempt to rename the file
	NSString *newPath = [parentPath stringByAppendingPathComponent:newName];
	if (ext) newPath = [newPath stringByAppendingPathExtension:ext];
	if (![fileManager moveItemAtPath:tempPath toPath:newPath error:nil]) {

		// If the rename fails, make sure the name is unique
		NSString *newPath = [self pathForPath:parentPath name:newName extension:ext unique:YES];

		// Rename the file again
		NSError *moveError = nil;
		if (![fileManager moveItemAtPath:tempPath toPath:newPath error:&moveError]) {
			if (error != NULL) *error = moveError;
			return nil;
		}

	}

	return newPath;

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

- (NSString *)generateUUID {
	CFUUIDRef uuidRef = CFUUIDCreate(kCFAllocatorDefault);
	NSString *uuidString = (__bridge_transfer NSString *)CFUUIDCreateString(kCFAllocatorDefault,uuidRef);
	CFRelease(uuidRef);
	return uuidString;
}

- (IBAction)openSite:(id)sender {
	[[NSWorkspace sharedWorkspace] openURL:[NSURL URLWithString:@"http://junecloud.com/software/donate/"]];
}

@end
