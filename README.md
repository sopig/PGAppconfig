# TollyPhoto
a photoBrowser and camera and picker

##Useage

```Swift
/**
 *
 使用方法：
 
 
 TollyCameraViewController:
 TollyCameraViewController *cameraVc = [[TollyCameraViewController alloc] init];
 // 打开相机 回调是ZLComplate block回调对象. 返回数组
 - (void)startCameraOrPhotoFileWithViewController:(UIViewController*)viewController complate : (ZLComplate ) complate;
 // 需要一个强引用的属性，引用它.
 self.cameraVc = cameraVc.
 
 TollyPickerViewController:
 Note : (图片相册多选控制器)
 创建控制器
 TollyPickerViewController *pickerVc = [[TollyPickerViewController alloc] init];
 // 默认显示相册里面的内容SavePhotos
 pickerVc.status = PickerViewShowStatusCameraRoll;
 // 选择图片的最小数，默认是9张图片
 pickerVc.minCount = 4;
 // 设置代理回调
 pickerVc.delegate = self;
 // 展示控制器
 [pickerVc show];
 
 第一种回调方法：- (void)pickerViewControllerDoneAsstes:(NSArray *)assets
 第二种回调方法pickerVc.callBack = ^(NSArray *assets){
 // TODO 回调结果，可以不用实现代理
 };
 
 TollyPickerBrowserViewController:
 Note : (图片游览器)
 创建控制器
 TollyPickerBrowserViewController *pickerBrowser = [[TollyPickerBrowserViewController alloc] init];
 // 传入点击imageView的话，会有微信朋友圈照片的风格
 pickerBrowser.toView = cell.imageView;
 // 数据源/delegate
 pickerBrowser.delegate = self;
 pickerBrowser.dataSource = self;
 // 是否可以删除照片
 pickerBrowser.editing = YES;
 // 当前选中的值
 pickerBrowser.currentIndexPath = indexPath;
 pickerBrowser.currentPage = indexPath.row;
 // 展示控制器
 [pickerBrowser show];
 
 数据源 ----- <TollyPickerBrowserViewControllerDataSource>
    有多少组
    - (NSInteger) numberOfSectionInPhotosInPickerBrowser:(TollyPhotoPickerBrowserViewController *) pickerBrowser;
    每个组多少个图片
    - (NSInteger) photoBrowser:(TollyPhotoPickerBrowserViewController *)photoBrowser numberOfItemsInSection:(NSUInteger)section;
    每个对应的IndexPath展示什么内容
    - (TollyPhotoPickerBrowserPhoto *)photoBrowser:(TollyPhotoPickerBrowserViewController *)pickerBrowser photoAtIndexPath:(NSIndexPath *)indexPath;

 
 代理 ----- <TollyPickerBrowserViewControllerDelegate>
    返回用户自定义的toolBarView(类似tableView FooterView)
    - (TollyPhotoPickerCustomToolBarView *)photoBrowserShowToolBarViewWithphotoBrowser:(TollyPhotoPickerBrowserViewController *)photoBrowser;
    准备删除那个图片
    - (BOOL)photoBrowser:(TollyPhotoPickerBrowserViewController *)photoBrowser willRemovePhotoAtIndexPath:(NSIndexPath *)indexPath;
    删除indexPath对应索引的图片
    - (void)photoBrowser:(TollyPhotoPickerBrowserViewController *)photoBrowser removePhotoAtIndexPath:(NSIndexPath *)indexPath;
    滑动结束的页数
    - (void)photoBrowser:(TollyPhotoPickerBrowserViewController *)photoBrowser didCurrentPage:(NSUInteger)page;
    滑动开始的页数
    - (void)photoBrowser:(TollyPhotoPickerBrowserViewController *)photoBrowser willCurrentPage:(NSUInteger)page;
 
 */
```
