//
//  XYPayManager.h
//  fula
//
//  Created by cby on 2016/12/7.
//  Copyright © 2016年 ixiye company. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "XYPayDefine.h"

@class XYPayControl;
@class XYPayBaseResp;

@protocol XYPayControlDelegate <NSObject>

/**
 支付回调

 @param control XYPayControl
 @param resp 返回对应的数据
 */
- (void)control:(XYPayControl *)control resp:(XYPayBaseResp *)resp;

@end

/**
 支付控制模块，用于调起具体的支付方式，可以有多个实例
 */
@interface XYPayControl : NSObject

/**
 PayControl 代理
 */
@property (weak, nonatomic) id<XYPayControlDelegate> delegate;

#ifdef ___MFPOS_DEFINE_H___
/**
 调起大额转账

 @param amount 转账金额, 必填
 @param goodsDes 商品描述， 必填
 @param tradeNo 第三方（非付啦）生成的交易 id,需唯一 必填
 @param mobile 交易手机号 必填
 @param mchId 商户号 （可不填，但是手机号必填）,如果填了商户号，则优先使用商户号
 @param recAccountNo 收款账户 可不填
 */
- (void)startMPOSTransferWithAmount:(float)amount
                           goodsDes:(NSString *)goodsDes
                            tradeNo:(NSString *)tradeNo
                             mobile:(NSString *)mobile
                              mchId:(NSString *)mchId
                       recAccountNo:(NSString *)recAccountNo;
#endif

/**
 调起扫码或二维码支付

 @param payType 支付类型,在二维码支付时必须确定是微信或者支付宝。在扫码时 sdk
 将自动判断
 @param amount 金额 必填
 @param goodsDes 商品描述 必填
 @param tradeNo 第三方（非付啦）生成的交易 id,需唯一 必填
 @param mobile 交易手机号 必填
 @param mchId 商户号（可不填，但是手机号必填），如果填了商户号，则优先使用商户号
 @param authCode 付款码，在扫码的时候必填。二维码支付请设为空
 */
- (void)startQrPayWithPayType:(XYPayType)payType
                       amount:(float)amount
                         body:(NSString *)goodsDes
                      tradeNo:(NSString *)tradeNo
                       mobile:(NSString *)mobile
                        mchId:(NSString *)mchId
                     authCode:(NSString *)authCode;

/**
 商户二维码，统一支付

 @param mobile 商户注册手机号
 @param mchId  商户号
 商户号可为空，若两者都不为空优先使用商户号
 */
- (void)startMerchantQr:(NSString *)mobile mchId:(NSString *)mchId;

- (UIViewController *)startScanViewControllerAmount:(float)amount
                                               body:(NSString *)body
                                            tradeNo:(NSString *)tradeNo
                                             mobile:(NSString *)mobile
                                              mchId:(NSString *)mchId;

@end

