
    //
//  MerchantQrViewController.m
//  demo
//
//  Created by cby on 2017/1/16.
//  Copyright © 2017年 iXiye. All rights reserved.
//

#import "MerchantQrViewController.h"
#import "XYPayControl.h"

@interface MerchantQrViewController () <XYPayControlDelegate>

@property (weak, nonatomic) IBOutlet UIImageView *imageView;
@property (strong, nonatomic) XYPayControl *control;

@end

@implementation MerchantQrViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.control = [[XYPayControl alloc] init];
    self.control.delegate = self;
    [self.control startMerchantQr:@"15280533697" mchId:@""];
}

- (void)control:(XYPayControl *)control resp:(XYPayBaseResp *)resp
{
    NSLog(@"%@", resp.url);
    dispatch_async(dispatch_get_main_queue(), ^{
        
        self.imageView.image = resp.qrImage;
    });
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)backAc:(id)sender
{
    [self dismissViewControllerAnimated:YES completion:nil];
}



/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little
preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
