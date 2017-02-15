//
//  XYPayManager.h
//  fula
//
//  Created by cby on 2016/12/7.
//  Copyright © 2016年 ixiye company. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XYPayDefine.h"

@class XYPayControl;
@class XYPayBaseResp;

@protocol XYPayControlDelegate <NSObject>

/**
 支付回调

 @param control XYPayManager
 @param resp 返回对应的数据
 */
- (void)control:(XYPayControl *)control resp:(XYPayBaseResp *)resp;

@end

@interface XYPayControl : NSObject

@property (weak, nonatomic) id <XYPayControlDelegate> delegate;

/**
 调起大额转账接口
 
 @param amount 转账金额, 必填
 @param goodsDes 商品描述， 必填
 @param tradeNo 第三方（非付啦）生成的交易 id,需唯一 必填
 @param mobile 交易手机号 必填
 @param mchId 商户号 （可不填，但是手机号必填）
 @param recAccountNo 收款账户 必填
 */
- (void)startMPOSTransferWithAmount:(float)amount
                           goodsDes:(NSString *)goodsDes
                            tradeNo:(NSString *)tradeNo
                             mobile:(NSString *)mobile
                              mchId:(NSString *)mchId
                       recAccountNo:(NSString *)recAccountNo;

@end

