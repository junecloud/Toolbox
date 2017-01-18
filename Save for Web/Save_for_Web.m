//
//  Save_for_Web.m
//  Save for Web
//
//  Created by Mike Piontek on 11/16/12.
//  Copyright (c) 2012 Junecloud LLC. All rights reserved.
//

@import OSAKit;
@import CoreImage;
#import "Save_for_Web.h"

@implementation NSFileManager (JUNCreatorCode)

- (NSString *)creatorCodeForPath:(NSString *)path {
	NSDictionary *attributes = [self attributesOfItemAtPath:path error:nil];
	NSString *code = NSFileTypeForHFSTypeCode([attributes fileHFSTypeCode]);
	return [code stringByTrimmingCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"'"]];
}

@end

@implementation Save_for_Web

// - (void)opened { }

- (id)runWithInput:(id)input fromAction:(AMAction *)anAction error:(NSDictionary **)errorInfo {

	NSString *outputPath = [[[self parameters] valueForKey:@"outputPath"] stringByExpandingTildeInPath];
	BOOL replaceExisting = [[[self parameters] valueForKey:@"replaceExisting"] boolValue];
	BOOL deleteOriginals = [[[self parameters] valueForKey:@"deleteOriginals"] boolValue];
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

	for (NSString *path in input) {

		NSString *name = [path lastPathComponent];
		NSString *dir = [path stringByDeletingLastPathComponent];
		NSString *anOutputPath = ([outputPath isEqualToString:@""]) ? dir : outputPath;
		BOOL success = NO;

		BOOL unique = !replaceExisting;
		if ([anOutputPath isEqualToString:dir] && deleteOriginals) unique = NO;
		NSString *outputFile = [self pathForPath:anOutputPath name:name extension:newExt unique:unique];

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
					[image drawInRect:outRect fromRect:inRect operation:NSCompositingOperationSourceOver fraction:1.0];

					[NSGraphicsContext restoreGraphicsState];

					bitmapRep = resizedRep;

					if (sharpenImage) {

						static CGFloat const JUNSharpenRadiusValue = 0.8;
						static CGFloat const JUNSharpenIntensityValue = 0.4;

						CIImage *ciImage = [[CIImage alloc] initWithBitmapImageRep:bitmapRep];
						CIFilter *filter = [CIFilter filterWithName:@"CIUnsharpMask" keysAndValues:
							kCIInputImageKey, ciImage,
							@"inputRadius", @(JUNSharpenRadiusValue),
							@"inputIntensity", @(JUNSharpenIntensityValue),
							nil];
						CIImage *ciOutputImage = filter.outputImage;
						NSBitmapImageRep *outputImageRep = [[NSBitmapImageRep alloc] initWithCIImage:ciOutputImage];
						bitmapRep = outputImageRep;

					}

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

		if (success) {
			[output addObject:outputFile];
			if (deleteOriginals && ![path isEqualToString:outputFile]) {
				NSError *error = nil;
				if (![fileManager removeItemAtPath:path error:&error]) NSLog(@"Error deleting file: %@ %@",error,[error userInfo]);
			}
		} else {
			NSString *message = [NSString stringWithFormat:@"%@ could not be saved.",name];
			*errorInfo = @{
				OSAScriptErrorNumber: @(errOSASystemError),
				OSAScriptErrorMessage: message
			};
			return nil;	
		}

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

- (IBAction)openSite:(id)sender {
	[[NSWorkspace sharedWorkspace] openURL:[NSURL URLWithString:@"http://junecloud.com/software/donate/"]];
}

@end
