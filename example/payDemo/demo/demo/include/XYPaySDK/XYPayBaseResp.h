//
//  XYTradeResp.h
//  XYPaySDK
//
//  Created by cby on 2017/1/6.
//  Copyright © 2017年 cby. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "XYPayDefine.h"

/**
 支付结束时，回调返回的类
 */
@interface XYPayBaseResp : NSObject

/**
 响应码， required
 0000	请求成功
 1000	请求参数错误
 2000	付啦系统内部异常
 3000	开发者信息未认证，请联系付啦运营人员处理！
 3001	开发者授权公钥尚未设置，请联系付啦相关运营人员！
 3010	尚未创建APP，请到付啦开放平台创建！
 3011	APP状态异常，请联系付啦运营人员处理！
 3020	商户不存在，操作失败！
 3021	商户未审核,请联系付啦运营人员审核！
 3022	商户未激活,请联系付啦运营人员激活！
 4000	用户取消
 5000	付啦系统处理中
 6000	网络错误
 7000   验证签名错误
 */
@property (copy, nonatomic) NSString *resCode;

/**
 响应的消息，可能为空 optional
 */
@property (copy, nonatomic) NSString *resMsg;

/**
 如果支付失败，会返回对应的的代码，可能为空 optional
 */
@property (copy, nonatomic) NSString *errCode;

/**
 失败的消息 optional
 */
@property (copy, nonatomic) NSString *errMsg;
@property (copy, nonatomic) NSString *qrUrl;
@property (strong, nonatomic) UIImage *qrImage;
@property (assign, nonatomic) XYPayType payType;
@property (copy, nonatomic) NSString *url;
@property (copy, nonatomic) NSString *card_url;

@end
