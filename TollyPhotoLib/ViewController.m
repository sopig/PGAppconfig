//
//  ViewController.m
//  TollyPhotoLib
//
//  Created by tolly on 15/4/28.
//  Copyright (c) 2015年 tolly. All rights reserved.
//

#import "ViewController.h"
#import "TollyPhoto.h"

@interface ViewController ()<UICollectionViewDataSource,UICollectionViewDelegate,TollyPhotoPickerBrowserViewControllerDataSource,TollyPhotoPickerBrowserViewControllerDelegate>

@property (nonatomic , strong) NSMutableArray *assets;
@property (weak,nonatomic) UICollectionView *collectionView;
@property (strong,nonatomic) TollyCameraViewController *cameraVc;

@end

@implementation ViewController


@end
