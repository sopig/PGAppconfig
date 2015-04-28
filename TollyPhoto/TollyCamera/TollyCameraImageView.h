//
//  TollyCameraImageView.h
//  TollyPhotoLib
//
//  Created by tolly on 15/4/28.
//  Copyright (c) 2015年 tolly. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TollyCamera.h"

@class TollyCameraImageView;

@protocol TollyCameraImageViewDelegate <NSObject>

@optional
/**
 *  根据index来删除照片
 */
- (void) deleteImageView : (TollyCameraImageView *) imageView;

@end

@interface TollyCameraImageView : UIImageView

@property (weak, nonatomic) id <TollyCameraImageViewDelegate> delegatge;
/**
 *  是否是编辑模式 , YES 代表是
 */
@property (assign, nonatomic, getter = isEdit) BOOL edit;

@end
