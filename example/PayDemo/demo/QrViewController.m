//
//  QrViewController.m
//  demo
//
//  Created by cby on 2017/1/16.
//  Copyright © 2017年 iXiye. All rights reserved.
//

#import "QrViewController.h"
#import "XYPayControl.h"

@interface QrViewController () <XYPayControlDelegate>

@property (weak, nonatomic) IBOutlet UIImageView *imageView;
@property (strong, nonatomic) XYPayControl *control;

@end

@implementation QrViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    dateFormatter.dateFormat = @"yyyyMMddHHmmss";
    NSDate *start = [dateFormatter dateFromString:@"20170101000000"];
    NSDate *now = [NSDate date];
    NSTimeInterval timeStamp = [now timeIntervalSinceDate:start];
    NSString *outTradeNo = [NSString stringWithFormat:@"%.0lf", timeStamp];
    self.control = [[XYPayControl alloc] init];
    self.control.delegate = self;
    [self.control startQrPayWithPayType:XYPayTypeWechatQr amount:1000 body:@"细叶" tradeNo:outTradeNo mobile:@"15280533697" mchId:@"88793741592119799888" authCode:nil];
}

- (void)control:(XYPayControl *)control resp:(XYPayBaseResp *)resp
{
    NSDictionary *data = resp.data;
    dispatch_async(dispatch_get_main_queue(), ^{
        self.imageView.image = data[@"qrImage"];
    });
}

- (IBAction)backAc:(id)sender
{
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
