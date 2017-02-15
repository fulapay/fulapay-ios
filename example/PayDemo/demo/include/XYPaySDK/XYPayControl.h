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

/**
 init with delegate

 @param delegate 代理
 @return 实例
 */
- (instancetype)initWithDelegate:(id <XYPayControlDelegate> )delegate;

/**
 调起扫码或二维码支付，没有UI

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
 手机号可为空，两者都填优先使用商户号
 */
- (void)startMerchantQr:(NSString *)mobile mchId:(NSString *)mchId;


/**
 调起扫码界面

 @param amount 总数
 @param body 商品描述
 @param tradeNo 订单号
 @param mobile 手机号
 @param mchId 商户号
 @return 扫码用的 UIViewController
 */
- (UIViewController *)startScanViewControllerAmount:(float)amount
                                               body:(NSString *)body
                                            tradeNo:(NSString *)tradeNo
                                             mobile:(NSString *)mobile
                                              mchId:(NSString *)mchId;

/**
 个人账户进件

 @param type 进件类型
 @param name 商户姓名，和身份证上一致
 @param mobile 商户手机号
 @param idNumber 商户身份证
 @param bankName 银行名字
 @param bankAccount 银行账户
 @param bankMobile 银行预留手机号
 @param bankCode 银行代码
 @param bankSubbranch 银行支行名称
 @param merchantNo 商户号，当修改商户信息时，商户号必填，否则留空
 */
- (void)startMerchantEnter:(XYPayMchEnterType)type
                      name:(NSString *)name
                    mobile:(NSString *)mobile
                  idNumber:(NSString *)idNumber
                  bankName:(NSString *)bankName
               bankAccount:(NSString *)bankAccount
                bankMobile:(NSString *)bankMobile
                  bankCode:(NSString *)bankCode
             bankSubbranch:(NSString *)bankSubbranch
                merchantNo:(NSString *)merchantNo;

/**
 企业账户进件

 @param type 进件类型
 @param name 商户姓名
 @param mobile 手机号
 @param bankName 银行名称
 @param bankAccount 银行账户
 @param bankCode 银行代码
 @param bankSubbranch 银行支行名称
 @param bizLicenseNo 营业执照号
 @param orgCode 组织机构码
 @param bankAccountName 户名
 @param merchantNo 商户号，当修改商户信息时，商户号必填，否则留空
 */
- (void)startCompanyMchEnter:(XYPayMchEnterType)type
                        name:(NSString *)name
                      mobile:(NSString *)mobile
                    bankName:(NSString *)bankName
                 bankAccount:(NSString *)bankAccount
                    bankCode:(NSString *)bankCode
               bankSubbranch:(NSString *)bankSubbranch
                bizLicenseNo:(NSString *)bizLicenseNo
                     orgCode:(NSString *)orgCode
             bankAccountName:(NSString *)bankAccountName
                  merchantNo:(NSString *)merchantNo;

/**
 商户进件，上传照片

 @param isCompany 是否是公司账户
 @param idFrontImage 身份证正面 当isCompany != 1 必填
 @param idBackImage 身份证背面 当isCompany != 1 必填
 @param idHandImage 手持身份证 当isCompany != 1 必填
 @param bankFrontImage 银行卡正面 当isCompany != 1 必填
 @param bizLicenseImage 营业执照 当isCompany = 1 是必填
 @param merchantNo 商户号 （必填）
 */
- (void)startMchPhotoIsCompany:(BOOL)isCompany
                  idFrontImage:(UIImage *)idFrontImage
                   idBackImage:(UIImage *)idBackImage
                   idHandImage:(UIImage *)idHandImage
                bankFrontImage:(UIImage *)bankFrontImage
               bizLicenseImage:(UIImage *)bizLicenseImage
                    merchantNo:(NSString *)merchantNo;

/**
 分页查询交易订单

 @param mobile 手机号  
 @param pageIndex 页码
 */
- (void)startTradeQuery:(NSString *)mobile
              pageIndex:(NSString *)pageIndex;


/**
 高级分页查询

 @param mobile 手机号
 @param pageIndex 页码
 @param pageSize 每页数据大小
 @param tradeState 订单状态
 @param startDate 开始时间
 @param endDate 结束时间
 */
- (void)startDetailTradeQuery:(NSString *)mobile
                    pageIndex:(NSString *)pageIndex
                     pageSize:(NSString *)pageSize
                    tradeState:(NSString *)tradeState
                    startDate:(NSString *)startDate
                      endDate:(NSString *)endDate;

/**
 根据手机号查询商户号

 @param mobile 手机号
 */
- (void)startMchId:(NSString *)mobile;

@end

