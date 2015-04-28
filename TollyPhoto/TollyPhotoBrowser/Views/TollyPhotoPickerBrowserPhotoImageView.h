//
//  TollyPhotoPickerBrowserPhotoImageView.h
//  TollyPhotoLib
//
//  Created by tolly on 15/4/28.
//  Copyright (c) 2015年 tolly. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol TollyPhotoPickerBrowserPhotoImageViewDelegate;

@interface TollyPhotoPickerBrowserPhotoImageView : UIImageView

@property (nonatomic, weak) id <TollyPhotoPickerBrowserPhotoImageViewDelegate> tapDelegate;
@property (assign,nonatomic) CGFloat progress;

@end


@protocol TollyPhotoPickerBrowserPhotoImageViewDelegate <NSObject>

@optional

- (void)imageView:(UIImageView *)imageView singleTapDetected:(UITouch *)touch;
- (void)imageView:(UIImageView *)imageView doubleTapDetected:(UITouch *)touch;

@end