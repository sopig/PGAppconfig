//
//  TollyPhotoCommon.h
//  TollyPhotoLib
//
//  Created by tolly on 15/4/28.
//  Copyright (c) 2015年 tolly. All rights reserved.
//

#ifndef TollyPhotoLib_TollyPhotoCommon_h
#define TollyPhotoLib_TollyPhotoCommon_h
// 点击销毁的block
typedef void(^TollyPickerBrowserViewControllerTapDisMissBlock)(NSInteger);

// 点击View执行的动画
typedef NS_ENUM(NSUInteger, UIViewAnimationAnimationStatus) {
    UIViewAnimationAnimationStatusZoom = 0, // 放大缩小
    UIViewAnimationAnimationStatusFade , // 淡入淡出
    UIViewAnimationAnimationStatusRotate // 旋转
};

// 图片最多显示9张，超过9张取消单击事件
static NSInteger const KPhotoShowMaxCount = 9;

#define iOS7gt ([[UIDevice currentDevice].systemVersion doubleValue] >= 7.0)

// ScrollView 滑动的间距
static CGFloat const TollyPickerColletionViewPadding = 20;

// ScrollView拉伸的比例
static CGFloat const TollyPickerScrollViewMaxZoomScale = 3.0;
static CGFloat const TollyPickerScrollViewMinZoomScale = 1.0;

// 进度条的宽度/高度
static NSInteger const TollyPickerProgressViewW = 50;
static NSInteger const TollyPickerProgressViewH = 50;

// 分页控制器的高度
static NSInteger const TollyPickerPageCtrlH = 25;

// NSNotification
static NSString *PICKER_TAKE_DONE = @"PICKER_TAKE_DONE";

#endif
