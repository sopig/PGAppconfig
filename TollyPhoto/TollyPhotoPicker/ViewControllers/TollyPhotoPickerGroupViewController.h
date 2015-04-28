//
//  TollyPhotoPickerGroupViewController.h
//  TollyPhotoLib
//
//  Created by tolly on 15/4/28.
//  Copyright (c) 2015年 tolly. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TollyPhotoPickerViewController.h"

@interface TollyPhotoPickerGroupViewController : UIViewController

@property (nonatomic , weak) id<TollyPhotoPickerViewControllerDelegate> delegate;
@property (nonatomic , assign) PickerViewShowStatus status;
@property (nonatomic , assign) NSInteger minCount;
// 记录选中的值
@property (strong,nonatomic) NSArray *selectAsstes;

@end
