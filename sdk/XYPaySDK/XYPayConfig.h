//
//  XYPayConfig.h
//  XYPaySDK
//
//  Created by cby on 2017/1/7.
//  Copyright © 2017年 cby. All rights reserved.
//

#import <Foundation/Foundation.h>
#define XY_START_NONNULL _Pragma("clang assume_nonnull begin")
#define XY_END_NONNULL _Pragma("clang assume_nonnull end")

XY_START_NONNULL
/**
 全局支付模块设置
 */
@interface XYPayConfig : NSObject

/**
 随机字符串，可以不赋值. 不长于 32 位
 */
@property (copy, nonatomic, nullable) NSString *nonceStr;

/**
 签名类型，默认 RSA，可不设置
 */
@property (copy, nonatomic, nullable) NSString *signType;

/**
 提现类型, t0 为 1,
          t1 为 2,
          D0 为 0。 默认 t1,可不设置
 */
@property (copy, nonatomic, nullable) NSString *withdrawType;

/**
 商户订单创建IP
 */
@property (copy, nonatomic, nonnull) NSString *mchCreateIp;

/**
 交易结果异步通知url
 */
@property (copy, nonatomic, nonnull) NSString *notifyUrl;

/**
 是否打开日志打印，默认 YES
 */
@property (assign, nonatomic) BOOL enableDebug;

/**
 是否在生产环境，默认为 YES
 */
@property (assign, nonatomic) BOOL isProduction;

/**
 p12 私钥的文件名
 */
@property (copy, nonatomic, nullable) NSString *p12FileName;

/**
 der 服务器公钥的文件名
 */
@property (copy, nonatomic, nullable) NSString *derFileName;

@end
XY_END_NONNULL
