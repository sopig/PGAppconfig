//
//  TollyPhotoPickerBrowserPhotoView.h
//  TollyPhotoLib
//
//  Created by tolly on 15/4/28.
//  Copyright (c) 2015年 tolly. All rights reserved.
//

#import <UIKit/UIKit.h>
@protocol TollyPhotoPickerBrowserPhotoViewDelegate;

@interface TollyPhotoPickerBrowserPhotoView : UIView
@property (nonatomic, weak) id <TollyPhotoPickerBrowserPhotoViewDelegate> tapDelegate;
@end


@protocol TollyPhotoPickerBrowserPhotoViewDelegate <NSObject>

@optional

- (void)view:(UIView *)view singleTapDetected:(UITouch *)touch;
- (void)view:(UIView *)view doubleTapDetected:(UITouch *)touch;

@end