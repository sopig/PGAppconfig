//
//  TollyPhotoPickerBrowserPhotoScrollView.h
//  TollyPhotoLib
//
//  Created by tolly on 15/4/28.
//  Copyright (c) 2015年 tolly. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <UIKit/UIKit.h>
#import "TollyPhotoPickerBrowserPhotoImageView.h"
#import "TollyPhotoPickerBrowserPhotoView.h"
#import "TollyBrowserPhoto.h"
#import "TollyPhotoPickerBrowserPhotoView.h"

typedef void(^callBackBlock)(id obj);
@class TollyPhotoPickerBrowserPhotoScrollView;

@protocol TollyPhotoPickerPhotoScrollViewDelegate <NSObject>

@optional
// 单击调用
- (void) pickerPhotoScrollViewDidSingleClick:(TollyPhotoPickerBrowserPhotoScrollView *)photoScrollView;
@end


@interface TollyPhotoPickerBrowserPhotoScrollView : UIScrollView <UIScrollViewDelegate, TollyPhotoPickerBrowserPhotoImageViewDelegate,TollyPhotoPickerBrowserPhotoViewDelegate>

@property (nonatomic,strong) TollyBrowserPhoto *photo;
@property (nonatomic, weak) id <TollyPhotoPickerPhotoScrollViewDelegate> photoScrollViewDelegate;
// 长按图片的操作，可以外面传入
@property (strong,nonatomic) UIActionSheet *sheet;
// 单击销毁的block
@property (copy,nonatomic) callBackBlock callback;

@end
