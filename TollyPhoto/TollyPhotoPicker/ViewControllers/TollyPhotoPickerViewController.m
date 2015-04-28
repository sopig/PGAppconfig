//
//  TollyPhotoPickerViewController.m
//  TollyPhotoLib
//
//  Created by tolly on 15/4/28.
//  Copyright (c) 2015年 tolly. All rights reserved.
//

#import "TollyPhotoPickerViewController.h"
#import "TollyPhotoPickerGroupViewController.h"
#import <AssetsLibrary/AssetsLibrary.h>
#import "TollyPhotoPickerCollectionView.h"
#import "TollyPhotoPickerBrowserViewController.h"
#import "UIView+Extension.h"
#import "TollyPhotoPickerCollectionViewCell.h"
#import "TollyPhotoPickerFooterCollectionReusableView.h"
#import "TollyPhotoPickerDatas.h"
#import "TollyPhotoPickerGroup.h"
#import "TollyPhotoPickerAssetsViewController.h"
#import "TollyPhotoPickerGroupTableViewCell.h"

@interface TollyPhotoPickerViewController ()
@property (nonatomic , weak) TollyPhotoPickerGroupViewController *groupVc;
@end

@implementation TollyPhotoPickerViewController
#pragma mark - Life cycle
- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    [self addNotification];
}

- (void)dealloc{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

#pragma mark - init Action
- (void) createNavigationController{
    TollyPhotoPickerGroupViewController *groupVc = [[TollyPhotoPickerGroupViewController alloc] init];
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:groupVc];
    nav.view.frame = self.view.bounds;
    [self addChildViewController:nav];
    [self.view addSubview:nav.view];
    self.groupVc = groupVc;
}

- (instancetype)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil{
    if (self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil]) {
        [self createNavigationController];
    }
    return self;
}

- (void)setSelectPickers:(NSArray *)selectPickers{
    _selectPickers = selectPickers;
    self.groupVc.selectAsstes = selectPickers;
}

- (void)setStatus:(PickerViewShowStatus)status{
    _status = status;
    self.groupVc.status = status;
}

- (void)setMinCount:(NSInteger)minCount{
    if (minCount <= 0) return;
    _minCount = minCount;
    self.groupVc.minCount = minCount;
}

#pragma mark - 展示控制器
- (void)show{
    [[[[UIApplication sharedApplication].windows firstObject] rootViewController] presentViewController:self animated:YES completion:nil];
}

- (void) addNotification{
    // 监听异步done通知
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(done:) name:PICKER_TAKE_DONE object:nil];
    });
}

- (void) done:(NSNotification *)note{
    NSArray *selectArray =  note.userInfo[@"selectAssets"];
    dispatch_async(dispatch_get_main_queue(), ^{
        if ([self.delegate respondsToSelector:@selector(pickerViewControllerDoneAsstes:)]) {
            [self.delegate pickerViewControllerDoneAsstes:selectArray];
        }else if (self.callBack){
            self.callBack(selectArray);
        }
        [self dismissViewControllerAnimated:YES completion:nil];
    });
}

- (void)setDelegate:(id<TollyPhotoPickerViewControllerDelegate>)delegate{
    _delegate = delegate;
    self.groupVc.delegate = delegate;
}

@end
