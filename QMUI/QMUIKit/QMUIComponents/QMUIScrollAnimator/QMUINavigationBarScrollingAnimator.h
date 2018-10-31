//
//  QMUINavigationBarScrollingAnimator.h
//  QMUIKit
//
//  Created by MoLice on 2018/O/16.
//  Copyright © 2018 QMUI Team. All rights reserved.
//

#import "QMUIScrollAnimator.h"

NS_ASSUME_NONNULL_BEGIN

/**
 实现通过界面上的 UIScrollView 滚动来控制顶部导航栏外观的类，导航栏外观会跟随滚动距离的变化而变化。
 
 使用方式：
 
 1. 用 init 方法初始化。
 2. 通过 scrollView 属性关联一个 UIScrollView。
 3. 修改 offsetYToStartAnimation 调整动画触发的滚动位置。
 4. 修改 distanceToStopAnimation 调整动画触发后滚动多久到达终点。
 
 @note 注意，由于在同个 UINavigationController 里的所有 viewController 的 navigationBar 都是共享的，所以如果修改了 navigationBar 的样式，需要自行处理界面切换时 navigationBar 的样式恢复。
 @note 注意，为了性能考虑，在 progress 达到 0 后再往上滚，或者 progress 达到 1 后再往下滚，都不会再触发那一系列 animationBlock。
 */
@interface QMUINavigationBarScrollingAnimator : QMUIScrollAnimator

/// 指定要关联的 UINavigationBar，若不指定，会自动寻找当前 App 可视界面上的 navigationBar
@property(nullable, nonatomic, weak) UINavigationBar *navigationBar;

/**
 contentOffset.y 到达哪个值即开始动画，默认为 0
 
 @note 注意，如果 adjustsOffsetYWithInsetTopAutomatically 为 YES，则实际计算时的值为 (-contentInset.top + offsetYToStartAnimation)，这时候 offsetYToStartAnimation = 0 则表示在列表默认的停靠位置往下拉就会触发临界点。
 */
@property(nonatomic, assign) CGFloat offsetYToStartAnimation;

/// 控制从 offsetYToStartAnimation 开始，要滚动多长的距离就打到动画结束的位置，默认为 44
@property(nonatomic, assign) CGFloat distanceToStopAnimation;

/// 传给 offsetYToStartAnimation 的值是否要自动叠加上 -contentInset.top，默认为 YES。
@property(nonatomic, assign) BOOL adjustsOffsetYWithInsetTopAutomatically;

/// 当前滚动位置对应的进度
@property(nonatomic, assign, readonly) float progress;

/**
 用于控制不同滚动位置下的表现，总的动画 block，如果定义了这个，则滚动时不会再调用后面那几个 block
 @param animator 当前的 animator 对象
 @param progress 当前滚动位置处于 offsetYToStartAnimation 到 (offsetYToStartAnimation + distanceToStopAnimation) 之间的哪个进度
 */
@property(nullable, nonatomic, copy) void (^animationBlock)(QMUINavigationBarScrollingAnimator * _Nonnull animator, float progress);

/**
 返回不同滚动位置下对应的背景图
 @param animator 当前的 animator 对象
 @param progress 当前滚动位置处于 offsetYToStartAnimation 到 (offsetYToStartAnimation + distanceToStopAnimation) 之间的哪个进度
 */
@property(nullable, nonatomic, copy) UIImage * (^backgroundImageBlock)(QMUINavigationBarScrollingAnimator * _Nonnull animator, float progress);

/**
 返回不同滚动位置下对应的导航栏底部分隔线的图片
 @param animator 当前的 animator 对象
 @param progress 当前滚动位置处于 offsetYToStartAnimation 到 (offsetYToStartAnimation + distanceToStopAnimation) 之间的哪个进度
 */
@property(nullable, nonatomic, copy) UIImage * (^shadowImageBlock)(QMUINavigationBarScrollingAnimator * _Nonnull animator, float progress);

/**
 返回不同滚动位置下对应的导航栏的 tintColor
 @param animator 当前的 animator 对象
 @param progress 当前滚动位置处于 offsetYToStartAnimation 到 (offsetYToStartAnimation + distanceToStopAnimation) 之间的哪个进度
 */
@property(nullable, nonatomic, copy) UIColor * (^tintColorBlock)(QMUINavigationBarScrollingAnimator * _Nonnull animator, float progress);

/**
 返回不同滚动位置下对应的导航栏的 titleView tintColor
 @param animator 当前的 animator 对象
 @param progress 当前滚动位置处于 offsetYToStartAnimation 到 (offsetYToStartAnimation + distanceToStopAnimation) 之间的哪个进度
 */
@property(nullable, nonatomic, copy) UIColor * (^titleViewTintColorBlock)(QMUINavigationBarScrollingAnimator * _Nonnull animator, float progress);

/**
 返回不同滚动位置下对应的状态栏样式
 @param animator 当前的 animator 对象
 @param progress 当前滚动位置处于 offsetYToStartAnimation 到 (offsetYToStartAnimation + distanceToStopAnimation) 之间的哪个进度
 */
@property(nullable, nonatomic, copy) UIStatusBarStyle (^statusbarStyleBlock)(QMUINavigationBarScrollingAnimator * _Nonnull animator, float progress);

/**
 返回不同滚动位置下对应的导航栏的 barTintColor
 @param animator 当前的 animator 对象
 @param progress 当前滚动位置处于 offsetYToStartAnimation 到 (offsetYToStartAnimation + distanceToStopAnimation) 之间的哪个进度
 */
@property(nonatomic, copy) UIColor * (^barTintColorBlock)(QMUINavigationBarScrollingAnimator * _Nonnull animator, float progress);
@end

NS_ASSUME_NONNULL_END
