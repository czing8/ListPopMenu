//
//  ViewController.m
//  ListPopMenu
//
//  Created by Vols on 2017/5/24.
//  Copyright © 2017年 vols. All rights reserved.
//

#import "ViewController.h"
#import "VListPopMenu.h"

#define TITLES @[@"修改", @"删除", @"扫一扫",@"付款"]
#define ICONS  @[@"motify",@"delete",@"saoyisao",@"pay"]

@interface ViewController () <VListPopMenuDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];


}


- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    UITouch *t = touches.anyObject;
    CGPoint p = [t locationInView: self.view];
    
    [VListPopMenu showAtPoint:p titles:TITLES icons:nil menuWidth:110 otherSettings:^(VListPopMenu *popupMenu) {
        popupMenu.dismissOnSelected = NO;
        popupMenu.isShowShadow = YES;
        popupMenu.delegate = self;
        popupMenu.offset = 10;
        popupMenu.type = VListPopMenuTypeDark;
        popupMenu.rectCorner = UIRectCornerBottomLeft | UIRectCornerBottomRight;
    }];
}

#pragma mark - YBPopupMenuDelegate
- (void)listPopMenuDidSelectedAtIndex:(NSInteger)index VListPopMenu:(VListPopMenu *)VListPopMenu
{
    NSLog(@"点击了 %@ 选项",TITLES[index]);
}



- (IBAction)onPopupClick:(UIButton *)sender {
    [VListPopMenu showRelyOnView:sender titles:TITLES icons:ICONS menuWidth:120 delegate:self];
}

- (IBAction)onTestClick:(UIButton *)sender {

    [VListPopMenu showRelyOnView:sender titles:@[@"111",@"222",@"333",@"444",@"555",@"666",@"777",@"888"] icons:nil menuWidth:100 otherSettings:^(VListPopMenu *popupMenu) {
        popupMenu.priorityDirection = VListPopMenuPriorityDirectionLeft;
        popupMenu.borderWidth = 1;
        popupMenu.borderColor = [UIColor redColor];
    }];
}




- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
