//
//  UIColor+ZQ_Extension.h
//  ZQ_Base
//
//  Created by zq on 2020/8/26.
//  Copyright © 2020年 mrzeng_sky. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger,ZQ_GradientChangeDirection) {
    ZQ_GradientChangeDirectionLevel,//水平方向渐变
    ZQ_GradientChangeDirectionVertical,//垂直方向渐变
    ZQ_GradientChangeDirectionUpwardDiagonalLine,//主对角线方向渐变
    ZQ_GradientChangeDirectionDownDiagonalLine,//副对角线方向渐变
};

@interface UIColor (ZQ_Extension)

/**
 从十六进制字符串获取颜色
 color:支持@“#123456”、 @“0X123456”、 @“123456”三种格式
 
 @param color 颜色值
 @return 获取的颜色
 */
+ (UIColor *)zq_colorWithHex:(NSString *)color;

/**
 从十六进制字符串获取颜色
 color:支持@“#123456”、 @“0X123456”、 @“123456”三种格式

 @param color 颜色值
 @param alpha 透明度
 @return 获取的颜色
 */
+ (UIColor *)zq_colorWithHex:(NSString *)color alpha:(CGFloat)alpha;

/// 颜色转8进制
/// @param color 需要转换的颜色
+ (NSInteger)zq_colorToHex:(UIColor*)color;

/**
生成渐变色
 
 @param size 渐变区域的尺寸
 @param direction 渐变方向
 @param startColor 透明度
 @param endColor 透明度
 @return 渐变色
*/
+ (UIColor *)zq_colorGradientChangeWithSize:(CGSize)size direction:(ZQ_GradientChangeDirection)direction startColor:(UIColor*)startColor endColor:(UIColor*)endColor;

@end
