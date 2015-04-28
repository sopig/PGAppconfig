//
//  TollyCameraViewController.h
//  TollyPhotoLib
//
//  Created by tolly on 15/4/28.
//  Copyright (c) 2015年 tolly. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^codeBlock)();
typedef void(^TollyComplate)(id object);

@interface TollyCameraViewController : UIViewController

// 顶部View
@property (weak, nonatomic) UIView *topView;
// 底部View
@property (weak, nonatomic) UIView *controlView;
/**
 *  打开相机
 *
 *  @param viewController 控制器
 *  @param complate       成功后的回调
 */
- (void)startCameraOrPhotoFileWithViewController:(UIViewController*)viewController complate : (TollyComplate ) complate;
@end
