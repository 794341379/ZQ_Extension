//
//  NSString+ZQ_Extension.m
//  ZQ_Extension_Example
//
//  Created by MrZeng_Sky on 2020/8/26.
//  Copyright © 2020 794341379@qq.com. All rights reserved.
//

#import "NSString+ZQ_Extension.h"
#import <CommonCrypto/CommonDigest.h>

@implementation NSString (ZQ_Extension)

- (BOOL)zq_isEmpty
{
    @try {
        if (!self) {
            return YES;
        } else {
            @try {
                NSCharacterSet *set = [NSCharacterSet whitespaceAndNewlineCharacterSet];
                NSString *trimedString = [self stringByTrimmingCharactersInSet:set];
                if ([trimedString length] == 0) {
                    return YES;
                } else {
                    return NO;
                }
            } @catch (NSException *exception) {
                return YES;
            }
        }
    } @catch (NSException *exception) {
        return YES;
    }
}

+ (BOOL)zq_isEmpty:(NSString *)string
{
    return [string zq_isEmpty];
}

+ (NSString *)zq_uuidString
{
    CFUUIDRef uuid_ref = CFUUIDCreate(NULL);
    CFStringRef uuid_string_ref= CFUUIDCreateString(NULL, uuid_ref);
    NSString *uuid = [NSString stringWithString:(__bridge NSString *)uuid_string_ref];
    CFRelease(uuid_ref);
    CFRelease(uuid_string_ref);
    NSString *uuid1 = [uuid lowercaseString];
    return uuid1;
}

- (CGSize)zq_getSizeWithFont:(UIFont *)font withMaxWidth:(CGFloat)width{
    NSDictionary *dic = @{NSFontAttributeName:font};
    CGSize size = [self boundingRectWithSize:CGSizeMake(width,MAXFLOAT) options:NSStringDrawingUsesLineFragmentOrigin attributes:dic context:nil].size;
    return size;
}

- (NSString *)zq_EncryptMD5{
    if (self.length<=0) return nil;
    
    const char *cStr = [self UTF8String];
    unsigned char digest[16];
    CC_MD5( cStr, (unsigned int)strlen(cStr), digest );
    
    NSMutableString *output = [NSMutableString stringWithCapacity:CC_MD5_DIGEST_LENGTH * 2];
    for (int i = 0; i < CC_MD5_DIGEST_LENGTH; i++) {
        [output appendFormat:@"%02x", digest[i]];
    }
    
    return  [output lowercaseString];
}

@end
