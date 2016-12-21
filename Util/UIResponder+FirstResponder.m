//
//  UIResponder+FirstResponder.m
//  BaseBusiness
//
//  Created by Somiya on 15/11/11.
//  Copyright © 2015年 Somiya. All rights reserved.
//

#import "UIResponder+FirstResponder.h"

static __weak id currentFirstResponder;
@implementation UIResponder (FirstResponder)
+ (id)currentFirstResponder {
    currentFirstResponder = nil;
    [[UIApplication sharedApplication] sendAction:@selector(findFirstResponder:) to:nil from:nil forEvent:nil];
    return currentFirstResponder;
}
- (void)findFirstResponder:(id)sender {
    currentFirstResponder = self;
}
@end