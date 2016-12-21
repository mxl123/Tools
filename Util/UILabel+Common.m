//
//  UILabel+Common.m
//  CreateSongs
//
//  Created by axg on 16/7/20.
//  Copyright © 2016年 AXG. All rights reserved.
//

#import "UILabel+Common.h"

@implementation UILabel (Common)

- (void)setLineSpace:(CGFloat)lineSpace {
    NSMutableAttributedString *attributedString = [[NSMutableAttributedString alloc] initWithString:self.text];
    NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc] init];
    [paragraphStyle setLineSpacing:lineSpace];
    [paragraphStyle setAlignment:NSTextAlignmentCenter];
    [attributedString addAttribute:NSParagraphStyleAttributeName value:paragraphStyle range:NSMakeRange(0, [self.text length])];
    self.attributedText = attributedString;
}

- (void)setColorWithRange:(NSRange)range withColor:(UIColor *)color {
    NSRange finalRange = range;
    
    if (range.location + range.length > self.text.length) {
        if (range.location > self.text.length) {
            range.location = 0;
            range.length = 0;
        } else {
            finalRange.length = self.text.length - finalRange.location;
        }
    }
    if (range.location == 0 && range.length == 0) {
        return;
    }
    NSMutableAttributedString *str = [[NSMutableAttributedString alloc] initWithString:self.text];
    [str addAttribute:NSForegroundColorAttributeName value:color range:finalRange];
    self.attributedText = str;
}

@end
