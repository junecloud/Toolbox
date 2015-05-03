//
//  JUNButton.h
//  Notefile
//
//  Created by Mike Piontek on 11/29/11.
//  Copyright (c) 2011 Junecloud LLC. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "JUNButtonCell.h"

#define JUNMouseEnteredButton	@"JUNMouseEnteredButton"
#define JUNMouseExitedButton	@"JUNMouseExitedButton"

@interface JUNButton : NSButton

@property BOOL trafficLight;

- (id)initWithFrame:(NSRect)frameRect image:(NSImage *)anImage hover:(NSImage *)aHoverImage highlight:(NSImage *)aHighlightImage;
- (void)addTrackingArea;
- (void)setHovering:(BOOL)hovering;

@end