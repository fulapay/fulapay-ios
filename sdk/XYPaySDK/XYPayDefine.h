//
//  XYPayDefine.h
//  fula
//
//  Created by cby on 2016/12/7.
//  Copyright © 2016年 ixiye company. All rights reserved.
//

#ifndef XYPayDefine_h
#define XYPayDefine_h

/**
 支付类型

 - XYPayTypeDefault: 未设定类型
 - XYPayTypeUnionPay: 银联支付
 - XYPayTypeWechatAppPay: 微信 App 支付
 - XYPayTypeWechatQr: 微信二维码
 - XYPayTypeWechatScan: 微信扫码
 - XYPayTypeAlipayQr: 支付宝二维码
 - XYPayTypeAlipayScan: 支付宝扫码
 - XYPayTypeMpos: Mpos 支付刷卡
 - XYPayTypeMposPlugin: Mpos 支付插件
 - XYPayTypeUnifiedPay: 统一支付，就是店铺二维码
 - XYPayTypeUnifiedPay: 统一支付中的嗨卡
 - XYPayTypeSuperTransfer: MPOS 大额转账
 - XYPayTypeAllScan: 扫码
 - XYPayTypeAllQr: 二维码
 */
typedef NS_ENUM(NSInteger, XYPayType)
{
    XYPayTypeDefault,
    XYPayTypeUnionPay = 11,
    XYPayTypeWechatAppPay = 20,
    XYPayTypeWechatQr = 21,
    XYPayTypeWechatScan = 22,
    XYPayTypeAlipayQr = 41,
    XYPayTypeAlipayScan = 42,
    XYPayTypeMpos = 50,
    XYPayTypeMposPlugin = 51,
    XYPayTypeUnifiedPay = 100,
    XYPayTypeUnifiedPayCard,
    XYPayTypeSuperTransfer,
};

/**
 支付状态

 - XYPayStatusOrderDidApply: 订单已获得
 - XYPayStatusOrderNotApply: 订单未获得
 - XYPayStatusDefault: 默认状态
 - XYPayStatusNoPay: 未支付
 - XYPayStatusSuccess: 支付成功
 - XYPayStatusPaying: 正在支付
 - XYPayStatusFail: 支付失败
 - XYPayStatusUnknown: 未知错误
 */
typedef NS_ENUM(NSInteger, XYPayStatus)
{
    XYPayStatusOrderDidApply = 400,
    XYPayStatusOrderNotApply = 401,
    XYPayStatusDefault = 100,
    XYPayStatusNoPay = 0,
    XYPayStatusSuccess = 1,
    XYPayStatusPaying = 2,
    XYPayStatusFail = 3,
    XYPayStatusUnknown = 7
};

#import "XYPay.h"
#import "XYPayConfig.h"
#import "XYPayControl.h"
#import "XYPayBaseResp.h"

#endif /* XYPayDefine_h */
