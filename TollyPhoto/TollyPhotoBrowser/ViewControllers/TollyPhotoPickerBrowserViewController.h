//
//  TollyPhotoPickerBrowserViewController.h
//  TollyPhotoLib
//
//  Created by tolly on 15/4/28.
//  Copyright (c) 2015年 tolly. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TollyBrowserPhoto.h"
#import "TollyPhotoPickerCustomToolBarView.h"
#import "TollyPhotoCommon.h"

//MARK: Datasource
@class TollyPhotoPickerBrowserViewController;
@protocol  TollyPhotoPickerBrowserViewControllerDataSource<NSObject>
@optional
/**
 *  有多少组
 */
- (NSInteger) numberOfSectionInPhotosInPickerBrowser:(TollyPhotoPickerBrowserViewController *) pickerBrowser;

@required

/**
 *  每个组多少个图片
 */
- (NSInteger) photoBrowser:(TollyPhotoPickerBrowserViewController *)photoBrowser numberOfItemsInSection:(NSUInteger)section;

/**
 *  每个对应的IndexPath展示什么内容
 */
- (TollyBrowserPhoto *)photoBrowser:(TollyPhotoPickerBrowserViewController *)pickerBrowser photoAtIndexPath:(NSIndexPath *)indexPath;

@end


//MARK: delegate

@protocol TollyPhotoPickerBrowserViewControllerDelegate <NSObject>
@optional

/**
 *  点击每个Item时候调用
 */
- (void)photoBrowser:(TollyPhotoPickerBrowserViewController *)pickerBrowser photoDidSelectView:(UIView *)scrollBoxView atIndexPath:(NSIndexPath *)indexPath;

/**
 *  返回用户自定义的toolBarView(类似tableView FooterView)
 *
 *  @return 返回用户自定义的toolBarView
 */
- (TollyPhotoPickerCustomToolBarView *)photoBrowserShowToolBarViewWithphotoBrowser:(TollyPhotoPickerBrowserViewController *)photoBrowser;
/**
 *  准备删除那个图片
 *
 *  @param index        要删除的索引值
 */
- (BOOL)photoBrowser:(TollyPhotoPickerBrowserViewController *)photoBrowser willRemovePhotoAtIndexPath:(NSIndexPath *)indexPath;
/**
 *  删除indexPath对应索引的图片
 *
 *  @param indexPath        要删除的索引值
 */
- (void)photoBrowser:(TollyPhotoPickerBrowserViewController *)photoBrowser removePhotoAtIndexPath:(NSIndexPath *)indexPath;
/**
 *  滑动结束的页数
 *
 *  @param page         滑动的页数
 */
- (void)photoBrowser:(TollyPhotoPickerBrowserViewController *)photoBrowser didCurrentPage:(NSUInteger)page;
/**
 *  滑动开始的页数
 *
 *  @param page         滑动的页数
 */
- (void)photoBrowser:(TollyPhotoPickerBrowserViewController *)photoBrowser willCurrentPage:(NSUInteger)page;

@end


@interface TollyPhotoPickerBrowserViewController : UIViewController

// @require
// 数据源/代理
@property (nonatomic , weak) id<TollyPhotoPickerBrowserViewControllerDataSource> dataSource;
@property (nonatomic , weak) id<TollyPhotoPickerBrowserViewControllerDelegate> delegate;
// 点击的View
@property (nonatomic , strong) UIView *toView;
// 当前提供的组
@property (strong,nonatomic) NSIndexPath *currentIndexPath;

// @optional
// 是否可以编辑（删除照片）
@property (nonatomic , assign,getter=isEditing) BOOL editing;
// 动画status (放大缩小/淡入淡出/旋转)
@property (assign,nonatomic) UIViewAnimationAnimationStatus status;
// 长按保存图片会调用sheet
@property (strong,nonatomic) UIActionSheet *sheet;
// 放大缩小一张图片的情况下（查看头像）
- (void)showHeadPortrait:(UIImageView *)toImageView;
// 放大缩小一张图片的情况下（查看头像）/ 缩略图是toImageView.image 原图URL
- (void)showHeadPortrait:(UIImageView *)toImageView originUrl:(NSString *)originUrl;

// 导航高度
@property (assign,nonatomic) CGFloat navigationHeight;
// @function
// 展示控制器
- (void)show;
// 刷新数据
- (void)reloadData;
@end
