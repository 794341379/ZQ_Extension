//
//  NSString+ZQ_Extension.h
//  ZQ_Extension_Example
//
//  Created by MrZeng_Sky on 2020/8/26.
//  Copyright © 2020 794341379@qq.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (ZQ_Extension)

///字符串是否为空
- (BOOL)zq_isEmpty;

/// 字符串是否为空
/// @param string  需要判断的字符串
+ (BOOL)zq_isEmpty:(NSString *)string;

/**
 获取UDID
 */
+ (NSString *)zq_uuidString;

/**
 *  计算普通文本字体size
 *  @param font       字体
 *  @param width      字体最大所占宽度
 *
 *  @return 富文本size
 */
- (CGSize)zq_getSizeWithFont:(UIFont*)font withMaxWidth:(CGFloat)width;

/**
 md5编码
 */
- (NSString *)zq_EncryptMD5;

@end

