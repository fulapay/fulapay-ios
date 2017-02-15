//
//  XYPayDefine.h
//  fula
//
//  Created by cby on 2016/12/7.
//  Copyright © 2016年 ixiye company. All rights reserved.
//

#ifndef XYPayDefine_h
#define XYPayDefine_h

typedef NS_ENUM(NSInteger, XYPayType)
{
    XYPayTypeDefault,                       // 未设定类型
    XYPayTypeUnionPay = 11,                 // 银联支付
    XYPayTypeWechatAppPay = 20,             // 微信 App 支付,现在只用于升级
    XYPayTypeWechatQr = 21,                 // 微信二维码
    XYPayTypeWechatScan = 22,               // 微信扫码
    XYPayTypeAlipayQr = 41,                 // 支付宝二维码
    XYPayTypeAlipayScan = 42,               // 支付宝扫码
    XYPayTypeMpos = 50,                     // Mpos 支付刷卡
    XYPayTypeMposPlugin = 51,               // Mpos 支付插件
    XYPayTypeUnifiedPay = 100,              // 统一支付，就是店铺二维码
    XYPayTypeUnifiedPayCard,                // 统一支付中的嗨卡
    XYPayTypeSuperTransfer,                 // MPOS 大额转账
    XYPayTypeAllScan = XYPayTypeWechatScan | XYPayTypeAlipayScan,
    XYPayTypeAllQr = XYPayTypeWechatQr | XYPayTypeAlipayQr,
};

typedef NS_ENUM(NSInteger, XYPayStatus)
{
    XYPayStatusOrderDidApply = 400,         // 订单已获得
    XYPayStatusOrderNotApply = 401,         // 订单未获得
    XYPayStatusDefault = 100,               // 默认状态
    XYPayStatusNoPay = 0,                   // 未支付
    XYPayStatusSuccess = 1,                 // 支付成功
    XYPayStatusPaying = 2,                  // 正在支付
    XYPayStatusFail = 3,                    // 支付失败
    XYPayStatusUnknown = 7                  // 未知错误
};

#import "XYPay.h"
#import "XYPayConfig.h"
#import "XYPayControl.h"
#import "XYPayBaseResp.h"

#endif /* XYPayDefine_h */
