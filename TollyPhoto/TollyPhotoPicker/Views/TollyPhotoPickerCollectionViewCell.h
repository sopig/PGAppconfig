//
//  TollyPhotoPickerCollectionViewCell.h
//  TollyPhotoLib
//
//  Created by tolly on 15/4/28.
//  Copyright (c) 2015年 tolly. All rights reserved.
//

#import <UIKit/UIKit.h>

@class UICollectionView;

@interface TollyPhotoPickerCollectionViewCell : UICollectionViewCell

@property (nonatomic , strong) UIImage *cellImage;


+ (instancetype) cellWithCollectionView : (UICollectionView *) collectionView cellForItemAtIndexPath:(NSIndexPath *) indexPath;

@end
