//
//  XYPayConfig.h
//  XYPaySDK
//
//  Created by cby on 2017/1/7.
//  Copyright © 2017年 cby. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 全局支付模块设置
 */
@interface XYPayConfig : NSObject

/**
 随机字符串，可以不赋值. 不长于 32 位
 */
@property (strong, nonatomic) NSString *nonceStr;

/**
 签名类型，默认 RSA，可不设置
 */
@property (strong, nonatomic) NSString *signType;

/**
 提现类型，t0 为 1,t1 为 2, D0 为 0。 默认 t1,可不设置
 */
@property (strong, nonatomic) NSString *withdrawType;

/**
 商户订单创建IP
 */
@property (strong, nonatomic) NSString *mchCreateIp;

/**
 交易结果异步通知url
 */
@property (strong, nonatomic) NSString *notifyUrl;

/**
 是否打开日志打印，默认 NO
 */
@property (assign, nonatomic) BOOL enableDebug;

/**
 是否在生产环境，默认为 YES
 */
@property (assign, nonatomic) BOOL isProduction;

@end
