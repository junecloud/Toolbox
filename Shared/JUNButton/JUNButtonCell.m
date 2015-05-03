//
//  JUNButtonCell.m
//  Notefile
//
//  Created by Mike Piontek on 11/29/11.
//  Copyright (c) 2011 Junecloud LLC. All rights reserved.
//

#import "JUNButtonCell.h"

@implementation JUNButtonCell

- (id)initImageCell:(NSImage *)anImage hover:(NSImage *)aHoverImage highlight:(NSImage *)aHighlightImage {
	if ((self = [super initImageCell:anImage])) {
		self.defaultImage = anImage;
		self.hoverImage = aHoverImage;
		self.highlightImage = aHighlightImage;
		self.hovering = NO;
		self.bordered = NO;
		self.buttonType = NSMomentaryChangeButton;
		// self.showsBorderOnlyWhileMouseInside = YES;
	}
	return self;
}

- (void)awakeFromNib {
	self.bordered = NO;
	self.buttonType = NSMomentaryChangeButton;
	self.showsBorderOnlyWhileMouseInside = YES;
	if (!self.defaultImage) self.defaultImage = self.image;
	if (!self.hoverImage) self.hoverImage = self.image;
	if (!self.highlightImage) self.highlightImage = self.alternateImage;
}

- (void)mouseEntered:(NSEvent *)event {
	self.image = self.hoverImage;
}

- (void)mouseExited:(NSEvent *)event {
	self.image = self.defaultImage;
}

- (void)drawImage:(NSImage *)image withFrame:(NSRect)frame inView:(NSView *)controlView {
	NSImage *currentImage = nil;
	if (self.isHighlighted) {
		currentImage = self.highlightImage;
	} else if (self.hovering) {
		currentImage = self.hoverImage;
	} else currentImage = self.defaultImage;
	[currentImage drawInRect:frame fromRect:NSZeroRect operation:NSCompositeSourceOver fraction:1.0 respectFlipped:YES hints:nil];
}

@end