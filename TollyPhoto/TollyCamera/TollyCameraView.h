//
//  TollyCameraView.h
//  TollyPhotoLib
//
//  Created by tolly on 15/4/28.
//  Copyright (c) 2015年 tolly. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TollyCameraView;

@protocol TollyCameraViewDelegate <NSObject>

@optional
- (void) cameraDidSelected : (TollyCameraView *) camera;

@end

@interface TollyCameraView : UIView

@property (weak, nonatomic) id <TollyCameraViewDelegate> delegate;

@end
