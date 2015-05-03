//
//  JUNButtonCell.h
//  Notefile
//
//  Created by Mike Piontek on 11/29/11.
//  Copyright (c) 2011 Junecloud LLC. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface JUNButtonCell : NSButtonCell

@property (atomic, strong) NSImage *defaultImage;
@property (atomic, strong) NSImage *hoverImage;
@property (atomic, strong) NSImage *highlightImage;
@property BOOL hovering;

- (id)initImageCell:(NSImage *)anImage hover:(NSImage *)aHoverImage highlight:(NSImage *)aHighlightImage;

@end