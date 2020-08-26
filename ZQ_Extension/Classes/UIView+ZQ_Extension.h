//
//  UIColor+ZQ_Extension.h
//  ZQ_Base
//
//  Created by zq on 2020/8/26.
//  Copyright © 2020年 mrzeng_sky. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (ZQ_Extension)

typedef void (^GestureActionBlock)(UIGestureRecognizer *_Nonnull);

@property (nonatomic, assign) CGFloat x;
@property (nonatomic, assign) CGFloat y;
@property (nonatomic, assign) CGFloat centerX;
@property (nonatomic, assign) CGFloat centerY;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, assign) CGSize size;

@property (nonatomic, assign) CGFloat top;
@property (nonatomic, assign) CGFloat bottom;
@property (nonatomic, assign) CGFloat left;
@property (nonatomic, assign) CGFloat right;

/**
 * @brief Shortcut for frame.origin
 */
@property(nonatomic,assign) CGPoint origin;

/// 平移
/// @param delta 移动的坐标
- (void)zq_moveBy:(CGPoint) delta;

/// 缩放比例
/// @param scaleFactor 缩放比例
- (void)zq_scaleBy:(CGFloat) scaleFactor;

/// 适配 以确保两个尺寸都适合给定尺寸
/// @param aSize 新的尺寸
- (void)zq_fitInSize:(CGSize) aSize;

/**
 移除此view上的所有子视图
 */
- (void)zq_removeAllSubviews;

/**
通过类名，找到子视图
*/
- (UIView *_Nonnull)zq_findViewWithClassName:(NSString *_Nonnull)aName;

///radius：角度 corners： UIRectCornerBottomLeft | UIRectCornerBottomRight | UIRectCornerTopRight | UIRectCornerTopLeft
- (void)zq_cutViewLayerCornerRadius:(NSInteger)radius direction:(UIRectCorner)corners;

/// 切自定义不同的圆角
/// @param radiusArray 圆角数组 依次为 topLeft topRight bottomLeft bottomRight
- (void)zq_cutViewLayerCustomSizeCornerRadius:(NSArray <NSNumber *>*_Nonnull)radiusArray;

/**
 *  @brief  添加tap手势
 *
 *  @param block 代码块
 */
- (void)addTapActionWithBlock:(GestureActionBlock _Nonnull )block;
/**
 *  @brief  添加长按手势
 *
 *  @param block 代码块
 */
- (void)addLongPressActionWithBlock:(GestureActionBlock _Nonnull )block;

@end
