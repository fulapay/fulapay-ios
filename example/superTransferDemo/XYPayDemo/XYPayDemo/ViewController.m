//
//  ViewController.m
//  XYPayDemo
//
//  Created by cby on 2016/11/3.
//  Copyright © 2016年 iXiye. All rights reserved.
//

#import "ViewController.h"
#import "XYPayDefine.h"

@interface ViewController () <XYPayControlDelegate>

@property (strong, nonatomic) XYPayControl *payControl;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (IBAction)buttonAc:(UIButton *)sender {
    
    // 生成模拟订单号（生产环境中订单号需唯一）
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    dateFormatter.dateFormat = @"yyyyMMddHHmmss";
    NSDate *start = [dateFormatter dateFromString:@"20170101000000"];
    NSDate *now = [NSDate date];
    NSTimeInterval timeStamp = [now timeIntervalSinceDate:start];
    NSString *outTradeNo = [NSString stringWithFormat:@"%.0lf", timeStamp];
    
    // 调起支付
    self.payControl = [[XYPayControl alloc] init];
    self.payControl.delegate = self;
    [self.payControl startMPOSTransferWithAmount:10000 goodsDes:@"细叶科技在线支付" tradeNo:outTradeNo mobile:@"15280533697" mchId:@"" recAccountNo:@"2341"];
}

- (IBAction)bAc:(id)sender {
    
    // 生成模拟订单号（生产环境中订单号需唯一）
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    dateFormatter.dateFormat = @"yyyyMMddHHmmss";
    NSDate *start = [dateFormatter dateFromString:@"20170101000000"];
    NSDate *now = [NSDate date];
    NSTimeInterval timeStamp = [now timeIntervalSinceDate:start];
    NSString *outTradeNo = [NSString stringWithFormat:@"%.0lf", timeStamp];
    
    // 调起支付
    self.payControl = [[XYPayControl alloc] init];
    self.payControl.delegate = self;
    [self.payControl startMPOSTransferWithAmount:10000 goodsDes:@"细叶科技在线支付" tradeNo:outTradeNo mobile:@"15280533697" mchId:@"88793741592119799888" recAccountNo:nil];
}

- (void)control:(XYPayControl *)control resp:(XYPayBaseResp *)resp
{
    NSLog(@"%@", resp.resMsg);
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
