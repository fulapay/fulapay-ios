//
//  ViewController.m
//  demo
//
//  Created by cby on 2017/1/16.
//  Copyright © 2017年 iXiye. All rights reserved.
//

#import "ViewController.h"
#import "MerchantQrViewController.h"
#import <XYPaySDK/XYPayDefine.h>
#import "QrViewController.h"

@interface ViewController ()

@property (strong, nonatomic) XYPayControl *control;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (IBAction)qrPay:(id)sender
{
    UIStoryboard *sb = [UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]];
    QrViewController *qrVc = [sb instantiateViewControllerWithIdentifier:@"QrViewController"];
    [self presentViewController:qrVc animated:YES completion:nil];
}

- (IBAction)mchQr:(id)sender
{
    UIStoryboard *sb = [UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]];
    MerchantQrViewController *qrVc = [sb instantiateViewControllerWithIdentifier:@"MerchantQrViewController"];
    [self presentViewController:qrVc animated:YES completion:nil];
}

- (IBAction)scanVc:(id)sender
{
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    dateFormatter.dateFormat = @"yyyyMMddHHmmss";
    NSDate *start = [dateFormatter dateFromString:@"20170101000000"];
    NSDate *now = [NSDate date];
    NSTimeInterval timeStamp = [now timeIntervalSinceDate:start];
    NSString *outTradeNo = [NSString stringWithFormat:@"%.0lf", timeStamp];
    self.control = [[XYPayControl alloc] init];
    UIViewController *vc = [self.control startScanViewControllerAmount:1000 body:@"细叶" tradeNo:outTradeNo mobile:@"15280533697" mchId:@"88793741592119799888"];
    [self presentViewController:vc animated:YES completion:nil];
}

@end
