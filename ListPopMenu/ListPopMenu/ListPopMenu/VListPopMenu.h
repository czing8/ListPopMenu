//
//  VListPopMenu.h
//  ListPopMenu
//
//  Created by Vols on 2017/5/24.
//  Copyright © 2017年 vols. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VListPopMenuPath.h"

// 过期提醒
#define YBDeprecated(instead) NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, instead)

typedef NS_ENUM(NSInteger , VListPopMenuType) {
    VListPopMenuTypeDefault = 0,
    VListPopMenuTypeDark
};

/**
 箭头方向优先级
 
 当控件超出屏幕时会自动调整成反方向
 */
typedef NS_ENUM(NSInteger , VListPopMenuPriorityDirection) {
    VListPopMenuPriorityDirectionTop = 0,  //Default
    VListPopMenuPriorityDirectionBottom,
    VListPopMenuPriorityDirectionLeft,
    VListPopMenuPriorityDirectionRight,
    VListPopMenuPriorityDirectionNone      //不自动调整
};

@class VListPopMenu;
@protocol VListPopMenuDelegate <NSObject>

@optional
/**
 点击事件回调
 */
- (void)listPopMenuDidSelectedAtIndex:(NSInteger)index VListPopMenu:(VListPopMenu *)VListPopMenu;
- (void)listPopMenuBeganDismiss;
- (void)listPopMenuDidDismiss;
- (void)listPopMenuBeganShow;
- (void)listPopMenuDidShow;

@end

@interface VListPopMenu : UIView

/**
 圆角半径 Default is 5.0
 */
@property (nonatomic, assign) CGFloat cornerRadius;

/**
 自定义圆角 Default is UIRectCornerAllCorners
 
 当自动调整方向时corner会自动转换至镜像方向
 */
@property (nonatomic, assign) UIRectCorner rectCorner;

/**
 是否显示阴影 Default is YES
 */
@property (nonatomic, assign , getter=isShadowShowing) BOOL isShowShadow;

/**
 是否显示灰色覆盖层 Default is YES
 */
@property (nonatomic, assign) BOOL showMaskView;

/**
 选择菜单项后消失 Default is YES
 */
@property (nonatomic, assign) BOOL dismissOnSelected;

/**
 点击菜单外消失  Default is YES
 */
@property (nonatomic, assign) BOOL dismissOnTouchOutside;

/**
 设置字体大小 Default is 15
 */
@property (nonatomic, assign) CGFloat fontSize;

/**
 设置字体颜色 Default is [UIColor blackColor]
 */
@property (nonatomic, strong) UIColor * textColor;

/**
 设置偏移距离 (>= 0) Default is 0.0
 */
@property (nonatomic, assign) CGFloat offset;

/**
 边框宽度 Default is 0.0
 
 设置边框需 > 0
 */
@property (nonatomic, assign) CGFloat borderWidth;

/**
 边框颜色 Default is LightGrayColor
 
 borderWidth <= 0 无效
 */
@property (nonatomic, strong) UIColor * borderColor;

/**
 箭头宽度 Default is 15
 */
@property (nonatomic, assign) CGFloat arrowWidth;

/**
 箭头高度 Default is 10
 */
@property (nonatomic, assign) CGFloat arrowHeight;

/**
 箭头位置 Default is center
 
 只有箭头优先级是VListPopMenuPriorityDirectionLeft/VListPopMenuPriorityDirectionRight/VListPopMenuPriorityDirectionNone时需要设置
 */
@property (nonatomic, assign) CGFloat arrowPosition;

/**
 箭头方向 Default is VListPopMenuArrowDirectionTop
 */
@property (nonatomic, assign) VListPopMenuArrowDirection arrowDirection;

/**
 箭头优先方向 Default is VListPopMenuPriorityDirectionTop
 
 当控件超出屏幕时会自动调整箭头位置
 */
@property (nonatomic, assign) VListPopMenuPriorityDirection priorityDirection;

/**
 可见的最大行数 Default is 5;
 */
@property (nonatomic, assign) NSInteger maxVisibleCount;

/**
 menu背景色 Default is WhiteColor
 */
@property (nonatomic, strong) UIColor * backColor;

/**
 item的高度 Default is 44;
 */
@property (nonatomic, assign) CGFloat itemHeight;

/**
 设置显示模式 Default is VListPopMenuTypeDefault
 */
@property (nonatomic, assign) VListPopMenuType type;

/**
 代理
 */
@property (nonatomic, weak) id <VListPopMenuDelegate> delegate;

/**
 在指定位置弹出
 
 @param titles    标题数组  数组里是NSString/NSAttributedString
 @param icons     图标数组  数组里是NSString/UIImage
 @param itemWidth 菜单宽度
 */
+ (VListPopMenu *)showAtPoint:(CGPoint)point
                      titles:(NSArray *)titles
                       icons:(NSArray *)icons
                   menuWidth:(CGFloat)itemWidth
                    delegate:(id<VListPopMenuDelegate>)delegate;

/**
 在指定位置弹出(推荐方法)
 
 @param point          弹出的位置
 @param titles         标题数组  数组里是NSString/NSAttributedString
 @param icons          图标数组  数组里是NSString/UIImage
 @param itemWidth      菜单宽度
 @param otherSetting   其他设置
 */
+ (VListPopMenu *)showAtPoint:(CGPoint)point
                      titles:(NSArray *)titles
                       icons:(NSArray *)icons
                   menuWidth:(CGFloat)itemWidth
               otherSettings:(void (^) (VListPopMenu * popupMenu))otherSetting;

/**
 依赖指定view弹出
 
 @param titles    标题数组  数组里是NSString/NSAttributedString
 @param icons     图标数组  数组里是NSString/UIImage
 @param itemWidth 菜单宽度
 */
+ (VListPopMenu *)showRelyOnView:(UIView *)view
                         titles:(NSArray *)titles
                          icons:(NSArray *)icons
                      menuWidth:(CGFloat)itemWidth
                       delegate:(id<VListPopMenuDelegate>)delegate;

/**
 依赖指定view弹出(推荐方法)
 
 @param titles         标题数组  数组里是NSString/NSAttributedString
 @param icons          图标数组  数组里是NSString/UIImage
 @param itemWidth      菜单宽度
 @param otherSetting   其他设置
 */
+ (VListPopMenu *)showRelyOnView:(UIView *)view
                         titles:(NSArray *)titles
                          icons:(NSArray *)icons
                      menuWidth:(CGFloat)itemWidth
                  otherSettings:(void (^) (VListPopMenu * popupMenu))otherSetting;

/**
 消失
 */
- (void)dismiss;

@end


