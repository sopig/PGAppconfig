//
//  TollyPhotoPickerAssetsViewController.h
//  TollyPhotoLib
//
//  Created by tolly on 15/4/28.
//  Copyright (c) 2015年 tolly. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TollyPhotoCommon.h"
#import "TollyPhotoPickerGroupViewController.h"

@class TollyPhotoPickerGroup;

@interface TollyPhotoPickerAssetsViewController : UIViewController

@property (strong,nonatomic) TollyPhotoPickerGroupViewController *groupVc;
@property (nonatomic , assign) PickerViewShowStatus status;
@property (nonatomic , strong) TollyPhotoPickerGroup *assetsGroup;
@property (nonatomic , assign) NSInteger minCount;
// 需要记录选中的值的数据
@property (strong,nonatomic) NSArray *selectPickerAssets;

@end
