//
//  XYPay.h
//  XYPaySDK
//
//  Created by cby on 2017/1/7.
//  Copyright © 2017年 cby. All rights reserved.
//

#import <Foundation/Foundation.h>

@class XYPayConfig;

/**
 全局支付模块
 */
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

/**
 初始化支付模块
 
 @param appId 开发者在付啦开放平台管理后台(https://open.fulapay.com/login.html)创建的APP的ID
 @param appKey 应用APPKEY(应用详细页查询)
 */
+ (void)setupWithAppId:(NSString *)appId appKey:(NSString *)appKey;

/**
 初始化支付模块
 
 @param appId appId 开发者在付啦开放平台管理后台(https://open.fulapay.com/login.html)创建的APP的ID
 @param appKey 应用APPKEY(应用详细页查询)
 @param config 自定义支付相关设置
 */
+ (void)setupWithAppId:(NSString *)appId
                appKey:(NSString *)appKey
                config:(XYPayConfig *)config;

/**
 p12 私钥的口令（passphrase）

 @param passwd 口令
 */
+ (void)setRSAPassword:(NSString *)passwd;

@end
