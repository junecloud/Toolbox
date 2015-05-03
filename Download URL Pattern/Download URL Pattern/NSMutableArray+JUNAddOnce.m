//
//  NSMutableArray+JUNAddOnce.m
//  Download URL Pattern
//
//  Created by Mike Piontek on 5/2/14.
//  Copyright (c) 2014 Junecloud LLC. All rights reserved.
//

#import "NSMutableArray+JUNAddOnce.h"

@implementation NSMutableArray (JUNAddOnce)

- (void)addObjectsFromArrayOnce:(NSArray *)otherArray {
	for (id object in otherArray) {
		if ([self containsObject:object] == NO) [self addObject:object];
	}
}

@end
