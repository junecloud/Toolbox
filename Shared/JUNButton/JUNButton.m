//
//  JUNButton.m
//  Notefile
//
//  Created by Mike Piontek on 11/29/11.
//  Copyright (c) 2011 Junecloud LLC. All rights reserved.
//

#import "JUNButton.h"

@implementation JUNButton

- (id)initWithFrame:(NSRect)frameRect image:(NSImage *)anImage hover:(NSImage *)aHoverImage highlight:(NSImage *)aHighlightImage {
	if ((self = [super initWithFrame:(NSRect)frameRect])) {

		self.layerContentsRedrawPolicy = NSViewLayerContentsRedrawOnSetNeedsDisplay;
		self.trafficLight = NO;
		JUNButtonCell *aCell = [[JUNButtonCell alloc] initImageCell:anImage hover:aHoverImage highlight:aHighlightImage];
		self.cell = aCell;
        [self addTrackingArea];

	}
	return self;
}

- (void)awakeFromNib {
	[self addTrackingArea];
}

#pragma mark - NSTrackingArea

- (void)mouseEntered:(NSEvent *)theEvent {
	if (self.trafficLight) {
		[[NSNotificationCenter defaultCenter] postNotificationName:JUNMouseEnteredButton object:self];
	} else [self setHovering:YES];
}

- (void)mouseExited:(NSEvent *)theEvent {
	if (self.trafficLight) {
		[[NSNotificationCenter defaultCenter] postNotificationName:JUNMouseExitedButton object:self];
	} else [self setHovering:NO];
}

#pragma mark - Custom methods

- (void)addTrackingArea {
	NSTrackingArea *trackingArea = [[NSTrackingArea alloc] initWithRect:self.frame
		options:(NSTrackingMouseEnteredAndExited|NSTrackingActiveAlways|NSTrackingInVisibleRect)
		owner:self userInfo:nil];
	[self addTrackingArea:trackingArea];
}

- (void)setHovering:(BOOL)hovering {
	JUNButtonCell *cell = self.cell;
	cell.hovering = ([self isEnabled]) ? hovering : NO;
	[self drawCell:cell];
}

@end