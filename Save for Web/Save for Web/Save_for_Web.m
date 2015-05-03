//
//  Save_for_Web.m
//  Save for Web
//
//  Created by Mike Piontek on 11/16/12.
//  Copyright (c) 2012 Junecloud LLC. All rights reserved.
//
//	Generate Photoshop.h:
//	sdef /Applications/Adobe\ Photoshop\ CS6/Adobe\ Photoshop\ CS6.app | sdp -fh --basename Photoshop
//	sdef /Applications/Adobe\ Photoshop\ CC\ 2014/Adobe\ Photoshop\ CC\ 2014.app | sdp -fh --basename PhotoshopCC

#import <ScriptingBridge/ScriptingBridge.h>
#import <OSAKit/OSAKit.h>
#import "Save_for_Web.h"
#import "Photoshop.h"
#import "PhotoshopCC.h"

@implementation NSFileManager (JUNCreatorCode)

- (NSString *)creatorCodeForPath:(NSString *)path {
	NSDictionary *attributes = [self attributesOfItemAtPath:path error:nil];
	NSString *code = NSFileTypeForHFSTypeCode([attributes fileHFSTypeCode]);
	return [code stringByTrimmingCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"'"]];
}

@end

@implementation Save_for_Web

- (void)opened {
	NSInteger useApplication = [[[self parameters] valueForKey:@"useApplication"] integerValue];
	[self applicationSelected:useApplication];
}

- (id)runWithInput:(id)input fromAction:(AMAction *)anAction error:(NSDictionary **)errorInfo {

	NSString *outputPath = [[[self parameters] valueForKey:@"outputPath"] stringByExpandingTildeInPath];
	BOOL replaceExisting = [[[self parameters] valueForKey:@"replaceExisting"] boolValue];
	BOOL deleteOriginals = [[[self parameters] valueForKey:@"deleteOriginals"] boolValue];
	NSInteger useApplication = [[[self parameters] valueForKey:@"useApplication"] integerValue];
	NSInteger fileType = [[[self parameters] valueForKey:@"fileType"] integerValue];
	BOOL constrainSize = [[[self parameters] valueForKey:@"constrainSize"] boolValue];
	double maxWidth = [[[self parameters] valueForKey:@"maxWidth"] doubleValue];
	double maxHeight = [[[self parameters] valueForKey:@"maxHeight"] doubleValue];
	BOOL sharpenImage = [[[self parameters] valueForKey:@"sharpenImage"] boolValue];

	NSMutableArray *output = [NSMutableArray arrayWithCapacity:1];

	NSString *newExt = @"jpg";
	if (fileType == JUNFileTypeGIF) {
		newExt = @"gif";
	} else if (fileType == JUNFileTypePNG) {
		newExt = @"png";
	}

	if (maxWidth < 1) maxWidth = DBL_MAX;
	if (maxHeight < 1) maxHeight = DBL_MAX;
	NSSize maxSize = NSMakeSize(maxWidth,maxHeight);

	NSFileManager *fileManager = [NSFileManager defaultManager];
	PhotoshopApplication *photoshop = nil;
	// PhotoshopE050 savedDialogs;
	PhotoshopE440 savedUnits;
	PhotoshopE400 savedPreviews;

	if (useApplication == JUNUseAppPhotoshop) {
		photoshop = [SBApplication applicationWithBundleIdentifier:@"com.adobe.Photoshop"];
		if (photoshop) {
			// [photoshop activate];
			// savedDialogs = photoshop.displayDialogs;
			savedUnits = photoshop.settings.rulerUnits;
			savedPreviews = photoshop.settings.imagePreviews;
			// photoshop.displayDialogs = PhotoshopE050Never;
			photoshop.settings.rulerUnits = PhotoshopE440PixelUnits;
			photoshop.settings.imagePreviews = PhotoshopE400No;
		} else {
			*errorInfo = @{
				OSAScriptErrorNumber: @(errOSASystemError),
				OSAScriptErrorMessage: @"Adobe Photoshop is not available. Try selecting the Built-In option instead, or quit Photoshop if it's currently in use."
			};
			return nil;
		}
	}

	for (NSString *path in input) {

		NSString *name = [path lastPathComponent];
		NSString *dir = [path stringByDeletingLastPathComponent];
		NSString *anOutputPath = ([outputPath isEqualToString:@""]) ? dir : outputPath;
		BOOL success = NO;

		BOOL unique = !replaceExisting;
		if ([anOutputPath isEqualToString:dir] && deleteOriginals) unique = NO;
		NSString *outputFile = [self pathForPath:anOutputPath name:name extension:newExt unique:unique];

		if (photoshop) {

			PhotoshopDocument *document = nil;
			NSString *ext = [[path pathExtension] lowercaseString];
			NSString *code = [fileManager creatorCodeForPath:path];
			NSString *script = nil;

			if ([ext isEqualToString:@"pdf"] || [ext isEqualToString:@"ai"] || [code isEqualToString:@"PDF "]) {
				script = @"var x = new PDFOpenOptions();"
					"x.resolution = 300;"
					"x.antiAlias = true;"
					"x.mode = OpenDocumentMode.RGB;"
					"x.suppressWarnings = true;"
					"x.page = 1;";
			} else if ([ext isEqualToString:@"eps"] || [code isEqualToString:@"EPSP"]) {
				script = @"var x = new EPSOpenOptions();"
					"x.resolution = 300;"
					"x.antiAlias = true;"
					"x.mode = OpenDocumentMode.RGB;";
			} else {
				script = @"app.open(File(\"%@\"));";
			}

			if (script) {
				NSString *escapedPath = [path stringByReplacingOccurrencesOfString:@"\"" withString:@"\\\""];
				NSString *script = [NSString stringWithFormat:@"app.open(File(\"%@\"));",escapedPath];
				NSString *result = [photoshop doJavascript:script withArguments:nil showDebugger:PhotoshopE940Never];
				if (result) document = photoshop.currentDocument;
			}

			if (document) {

				if (fileType == JUNFileTypePNG) {
					[document mergeVisibleLayers];
				} else [document flatten];
				[document changeModeTo:PhotoshopE089RGB withOptions:nil];
				[document convertToProfile:@"sRGB IEC61966-2.1" intent:PhotoshopE130Perceptual blackpointCompensation:NO dithering:YES];
				[document setBitsPerChannel:PhotoshopE815Eight];

				if (constrainSize) {
					NSSize size = [self scaleSize:NSMakeSize(document.width,document.height) toSize:maxSize];
					if (size.width < document.width || size.height < document.height) {
					
						// Could use PhotoshopE175BicubicSharper?
						@try {
							// Photoshop CS
							[document resizeImageWidth:size.width height:size.height resolution:72.0 resampleMethod:PhotoshopE175Bicubic];
						} @catch (NSException *exception) {
							// Photoshop CC
							[(PhotoshopCCDocument *)document resizeImageWidth:size.width height:size.height resolution:72.0 resampleMethod:PhotoshopE175Bicubic amount:0.0];
						}
						if (sharpenImage) [photoshop doJavascript:@"activeDocument.activeLayer.applyUnSharpMask(40,0.8,3);"
							withArguments:nil showDebugger:PhotoshopE940Never];
					}
				}

				NSString *script = nil;
				if (fileType == JUNFileTypeGIF) {
					script = @"var x = new GIFSaveOptions();"
						"x.palette = Palette.LOCALSELECTIVE;"
						"x.colors = 256;"
						"x.dither = Dither.DIFFUSION;"
						"x.ditherAmount = 95;"
						"x.matte = MatteType.NONE;"
						"x.transparency = true;"
						"app.activeDocument.saveAs(new File(\"%@\"),x,true,Extension.LOWERCASE);";
				} else if (fileType == JUNFileTypePNG) {
					script = @"var x = new PNGSaveOptions();"
						"x.compression = 9;"
						"x.interlaced = false;"
						"app.activeDocument.saveAs(new File(\"%@\"),x,true,Extension.LOWERCASE);";
				} else {
					script = @"var x = new JPEGSaveOptions();"
						"x.embedColorProfile = false;"
						"x.formatOptions = FormatOptions.OPTIMIZEDBASELINE;"
						"x.matte = MatteType.NONE;"
						"x.quality = 9;"
						"app.activeDocument.saveAs(new File(\"%@\"),x,true,Extension.LOWERCASE);";
				}
				if (script) {
					NSString *escapedPath = [outputFile stringByReplacingOccurrencesOfString:@"\"" withString:@"\\\""];
					script = [NSString stringWithFormat:script,escapedPath];
					NSString *result = [photoshop doJavascript:script withArguments:nil showDebugger:PhotoshopE940Never];
					if (result) success = YES;
				}
				[document closeSaving:PhotoshopSavoNo];

			}

		} else {

			CFStringRef utiTypeRef = UTTypeCreatePreferredIdentifierForTag(
				kUTTagClassFilenameExtension,(__bridge CFStringRef)[path pathExtension],NULL);
			if (UTTypeConformsTo(utiTypeRef,kUTTypeImage)) {

				NSData *imageData = nil;
				NSImage *image = [[NSImage alloc] initWithContentsOfFile:path];
				NSData *data = [image TIFFRepresentation];
				NSBitmapImageRep *bitmapRep = [NSBitmapImageRep imageRepWithData:data];

				if (constrainSize) {

					// Make sure we get the actual pixel size of the image, ignoring PPI
					NSRect rect = NSMakeRect(0.0,0.0,maxWidth,maxHeight);
					NSImageRep *imageRep = [image bestRepresentationForRect:rect context:nil hints:nil];
					CGFloat imageWidth = (CGFloat)imageRep.pixelsWide;
					CGFloat imageHeight = (CGFloat)imageRep.pixelsHigh;
					NSSize size = [self scaleSize:NSMakeSize(imageWidth,imageHeight) toSize:maxSize];

					if (size.width < imageWidth || size.height < imageHeight) {

						[NSGraphicsContext saveGraphicsState];

						NSBitmapImageRep *resizedRep = [[NSBitmapImageRep alloc] initWithBitmapDataPlanes:NULL
							pixelsWide:size.width
							pixelsHigh:size.height
							bitsPerSample:8
							samplesPerPixel:4
							hasAlpha:YES
							isPlanar:NO
							colorSpaceName:NSCalibratedRGBColorSpace
							bytesPerRow:0
							bitsPerPixel:0];
						resizedRep.pixelsWide = size.width;
						resizedRep.pixelsHigh = size.height;
						[resizedRep setSize:size];

						NSGraphicsContext *context = [NSGraphicsContext graphicsContextWithBitmapImageRep:resizedRep];
						[context setImageInterpolation:NSImageInterpolationHigh];
						[NSGraphicsContext setCurrentContext:context];
						NSRect inRect = NSMakeRect(0.0,0.0,image.size.width,image.size.height);
						NSRect outRect = NSMakeRect(0.0,0.0,size.width,size.height);
						[image drawInRect:outRect fromRect:inRect operation:NSCompositeSourceOver fraction:1.0];

						[NSGraphicsContext restoreGraphicsState];

						bitmapRep = resizedRep;

					}
				}

				if (fileType == JUNFileTypeGIF) {
					NSDictionary *properties = @{
						NSImageDitherTransparency: @YES
					};
					imageData = [bitmapRep representationUsingType:NSGIFFileType properties:properties];
				} else if (fileType == JUNFileTypePNG) {
					NSDictionary *properties = @{
						NSImageInterlaced: @NO
					};
					imageData = [bitmapRep representationUsingType:NSPNGFileType properties:properties];
				} else {
					NSDictionary *properties = @{
						NSImageCompressionFactor: @0.9,
						NSImageProgressive: @NO
					};
					imageData = [bitmapRep representationUsingType:NSJPEGFileType properties:properties];
				}

				if (imageData) success = [imageData writeToFile:outputFile atomically:YES];

			}
			CFRelease(utiTypeRef);

		}

		if (success) {
			[output addObject:outputFile];
			if (deleteOriginals && ![path isEqualToString:outputFile]) {
				NSError *error = nil;
				if (![fileManager removeItemAtPath:path error:&error]) NSLog(@"Error deleting file: %@ %@",error,[error userInfo]);
			}
		} else {
			NSString *message = [NSString stringWithFormat:@"%@ could not be saved.",name];
			if (photoshop) message = [message stringByAppendingString:@" Try selecting the Built-In option instead, or quit Photoshop if it's currently in use."];
			*errorInfo = @{
				OSAScriptErrorNumber: @(errOSASystemError),
				OSAScriptErrorMessage: message
			};
			return nil;	
		}

	}

	if (photoshop) {
		// photoshop.displayDialogs = savedDialogs;
		photoshop.settings.rulerUnits = savedUnits;
		photoshop.settings.imagePreviews = savedPreviews;
	}
	
	return output;

}

- (NSString *)pathForPath:(NSString *)path name:(NSString *)name extension:(NSString *)extension unique:(BOOL)unique {
	NSInteger no = 0;
	NSString *basePath = [[path stringByAppendingPathComponent:name] stringByDeletingPathExtension];
	NSString *newPath = [basePath stringByAppendingPathExtension:extension];
	if (unique) {
		NSFileManager *fileManager = [NSFileManager defaultManager];
		while ([fileManager fileExistsAtPath:newPath]) {
			no++;
			newPath = [[NSString stringWithFormat:@"%@-%ld",basePath,(long)no] stringByAppendingPathExtension:extension];
		}
	}
	return newPath;
}

- (NSSize)scaleSize:(NSSize)size toSize:(NSSize)max {
	NSSize newSize = NSMakeSize(size.width,size.height);
	if (newSize.width > max.width) newSize.width = max.width;
	newSize.height = round((newSize.width * size.height) / size.width);
	if (newSize.height > max.height) {
		newSize.height = max.height;
		newSize.width = round((newSize.height * size.width) / size.height);
	}
	return newSize;
}

- (void)applicationSelected:(NSInteger)application {
	if (application == JUNUseAppPhotoshop) {
		[self.sharpenBox setEnabled:YES];
		[self.sharpenBox setTitle:@"Sharpen after resizing"];
	} else {
		[self.sharpenBox setEnabled:NO];
		[self.sharpenBox setState:NSOffState];
		[self.sharpenBox setTitle:@"Sharpen after resizing (requires Photoshop)"];
	}
}

- (IBAction)changedApplication:(id)sender {
	NSPopUpButton *popup = (NSPopUpButton *)sender;
	[self applicationSelected:popup.indexOfSelectedItem];
}

- (IBAction)openSite:(id)sender {
	[[NSWorkspace sharedWorkspace] openURL:[NSURL URLWithString:@"http://junecloud.com/software/donate/"]];
}

@end
