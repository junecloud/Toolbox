//
//  NSMutableArray+JUNAddOnce.h
//  Download URL Pattern
//
//  Created by Mike Piontek on 5/2/14.
//  Copyright (c) 2014 Junecloud LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableArray (JUNAddOnce)

- (void)addObjectsFromArrayOnce:(NSArray *)otherArray;

@end
