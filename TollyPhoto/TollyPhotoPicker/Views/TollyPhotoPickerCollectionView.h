//
//  TollyPhotoPickerCollectionView.h
//  TollyPhotoLib
//
//  Created by tolly on 15/4/28.
//  Copyright (c) 2015年 tolly. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TollyPhotoAssets.h"

// 展示状态
typedef NS_ENUM(NSUInteger, TollyPickerCollectionViewShowOrderStatus){
    TollyPickerCollectionViewShowOrderStatusTimeDesc = 0, // 升序
    TollyPickerCollectionViewShowOrderStatusTimeAsc // 降序
};


@class TollyPhotoPickerCollectionView;
@protocol TollyPhotoPickerCollectionViewDelegate <NSObject>
// 选择相片就会调用
- (void) pickerCollectionViewDidSelected:(TollyPhotoPickerCollectionView *) pickerCollectionView deleteAsset:(TollyPhotoAssets *)deleteAssets;

@end

@interface TollyPhotoPickerCollectionView : UICollectionView

@property (nonatomic , assign) TollyPickerCollectionViewShowOrderStatus status;
// 保存所有的数据
@property (nonatomic , strong) NSArray *dataArray;
// 保存选中的图片
@property (nonatomic , strong) NSMutableArray *selectAsstes;
// 最后保存的一次图片
@property (strong,nonatomic) NSMutableArray *lastDataArray;
// delegate
@property (nonatomic , weak) id <TollyPhotoPickerCollectionViewDelegate> collectionViewDelegate;
// 限制最大数
@property (nonatomic , assign) NSInteger minCount;

// 选中的索引值，为了防止重用
@property (nonatomic , strong) NSMutableArray *selectsIndexPath;
// 记录选中的值
@property (assign,nonatomic) BOOL isRecoderSelectPicker;

@end
