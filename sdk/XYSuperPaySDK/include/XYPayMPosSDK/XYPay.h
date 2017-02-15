//
//  XYPay.h
//  XYPaySDK
//
//  Created by cby on 2017/1/7.
//  Copyright © 2017年 cby. All rights reserved.
//

#import <Foundation/Foundation.h>

@class XYPayConfig;
@interface XYPay : NSObject

/**
 当前设置的 appId
 */
+ (NSString *)appId;

/**
 当前设置的 appKey
 */
+ (NSString *)appKey;

/**
 当前 sdk 版本号
 */
+ (NSString *)version;

+ (void)setupWithAppId:(NSString *)appId appKey:(NSString *)appKey;
+ (void)setupWithAppId:(NSString *)appId
                appKey:(NSString *)appKey
                config:(XYPayConfig *)config;

/**
 p12 私钥的密码

 @param passwd 密码
 */
+ (void)setRSAPassword:(NSString *)passwd;

@end
