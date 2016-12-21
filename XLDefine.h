//
//  XLDefine.h
//  KaxiFinance
//
//  Created by mxl on 2016/12/21.
//  Copyright © 2016年 Meloinfo. All rights reserved.
//

#ifndef XLDefine_h
#define XLDefine_h
/**
 *  常规字体
 */
#define NORML_FONT(font) [UIFont systemFontOfSize:(font)]
/**
 *  加粗字体
 */
#define JIACU_FONT(font) [UIFont boldSystemFontOfSize:(font)]

/**
 *  运行时间
 */
#define TICK   NSDate *startTime = [NSDate date]
#define TOCK   NSLog(@"Time: %f", -[startTime timeIntervalSinceNow])

// RGB颜色
#define RGBColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:(a)]
// HexString颜色
#define HexStringColor(hex) [UIColor colorWithHexString:(hex)]

/**
 *  weak strong self for retain cycle
 */
#define WEAK_SELF __weak typeof(self) weakSelf = self
#define STRONG_SELF __strong typeof(weakSelf) self = weakSelf
/**
 *  屏幕宽高
 */
#define SCREEN_W    [[UIScreen mainScreen] bounds].size.width
#define SCREEN_H    [[UIScreen mainScreen] bounds].size.height
#define WIDTH_NIT   [[UIScreen mainScreen] bounds].size.width / 375
#define HEIGHT_NIT  [[UIScreen mainScreen] bounds].size.height / 667

#define kKeyWindow [UIApplication sharedApplication].keyWindow
#define kScreen_Bounds [UIScreen mainScreen].bounds

#define kDevice_Is_iPhone4 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
#define kDevice_Is_iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define kDevice_Is_iPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)
#define kDevice_Is_iPhone6Plus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)
#define kDevice_Is_iPad ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(768, 1024), [[UIScreen mainScreen] currentMode].size) : NO)
#define kDevice_Is_iPad3 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1536, 2048), [[UIScreen mainScreen] currentMode].size) : NO)

#define DebugLog(s, ...) NSLog(@"%s(%d): %@", __FUNCTION__, __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__])

/**
 *  单例
 */
#define XLSingletonM(name) \
static id _instance = nil; \
+ (id)allocWithZone:(struct _NSZone *)zone \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [super allocWithZone:zone]; \
}); \
return _instance; \
} \
+ (instancetype)shared##name \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [[self alloc] init]; \
}); \
return _instance; \
} \
- (id)copyWithZone:(NSZone *)zone \
{ \
return _instance; \
}


#endif /* XLDefine_h */
