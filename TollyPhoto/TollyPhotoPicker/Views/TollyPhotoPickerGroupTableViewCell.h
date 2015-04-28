//
//  TollyPhotoPickerGroupTableViewCell.h
//  TollyPhotoLib
//
//  Created by tolly on 15/4/28.
//  Copyright (c) 2015年 tolly. All rights reserved.
//

#import <UIKit/UIKit.h>
@class TollyPhotoPickerGroup;

@interface TollyPhotoPickerGroupTableViewCell : UITableViewCell

/**
 *  赋值xib
 */
@property (nonatomic , strong) TollyPhotoPickerGroup *group;

+ (instancetype) instanceCell;

@end
