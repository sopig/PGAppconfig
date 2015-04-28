//
//  TollyCamera.m
//  TollyPhotoLib
//
//  Created by tolly on 15/4/28.
//  Copyright (c) 2015年 tolly. All rights reserved.
//

#import "TollyCamera.h"

@implementation TollyCamera

- (UIImage *)fullScreenImage{
    return [UIImage imageWithContentsOfFile:self.imagePath];
}

@end
