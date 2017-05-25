//
//  VListPopMenuPath.h
//  ListPopMenu
//
//  Created by Vols on 2017/5/24.
//  Copyright © 2017年 vols. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, VListPopMenuArrowDirection) {
    VListPopMenuArrowDirectionTop = 0,  //箭头朝上
    VListPopMenuArrowDirectionBottom,   //箭头朝下
    VListPopMenuArrowDirectionLeft,     //箭头朝左
    VListPopMenuArrowDirectionRight,    //箭头朝右
    VListPopMenuArrowDirectionNone      //没有箭头
};

@interface VListPopMenuPath : NSObject

+ (CAShapeLayer *)maskLayerWithRect:(CGRect)rect
                            rectCorner:(UIRectCorner)rectCorner
                          cornerRadius:(CGFloat)cornerRadius
                            arrowWidth:(CGFloat)arrowWidth
                           arrowHeight:(CGFloat)arrowHeight
                         arrowPosition:(CGFloat)arrowPosition
                        arrowDirection:(VListPopMenuArrowDirection)arrowDirection;

+ (UIBezierPath *)bezierPathWithRect:(CGRect)rect
                             rectCorner:(UIRectCorner)rectCorner
                           cornerRadius:(CGFloat)cornerRadius
                            borderWidth:(CGFloat)borderWidth
                            borderColor:(UIColor *)borderColor
                        backgroundColor:(UIColor *)backgroundColor
                             arrowWidth:(CGFloat)arrowWidth
                            arrowHeight:(CGFloat)arrowHeight
                          arrowPosition:(CGFloat)arrowPosition
                         arrowDirection:(VListPopMenuArrowDirection)arrowDirection;
@end
