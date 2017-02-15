# 付啦支付 sdk iOS
# 上手指南

## 目录结构

```
|
|-doc       文档
|-example   例子
|-sdk       sdk
|-cert      相关的密钥
```

## 接入 sdk
1. 手动接入
- 将 .a 文件以及 include 文件夹一起拖到工程中。在需要的地方导入 `#import "XYPayDefine.h"`。
- 在 info.plist 中添加相机权限 Privacy - Photo Library Usage Description

## 使用

0. 证书设置
在开发者本地生成密钥以及对应的公钥，并将公钥转换为 .p12 格式以支持 iOS 平台。然后同服务器的 der 格式公钥（cert 目录下有）一起放入工程中。

1. 在 AppDelegate 中初始化 XYPay  

    ```
    XYPayConfig *config = [[XYPayConfig alloc] init];
    config.notifyUrl = @"127.0.0.1";
    config.mchCreateIp = @"127.0.0.1";
    config.isProduction = NO;      // 不是生成环境
    config.enableDebug = YES;      // 打印日志
    config.withdrawType = @"1";
    config.derFileName = @"public_key";
    config.p12FileName = @"private_key";
    [XYPay setupWithAppId:@"1000015" appKey:@"dadf#kjfiel" config:config];
    // 必须要设置密钥证书密码，请设置安全的证书密码以保证交易安全
    [XYPay setRSAPassword:@"123456"];
    ```

2. 在需要调用支付的地方用 XYPayControl 实例调用对应方法 
 
 以下例子是调用二维码支付
	```
    self.payControl = [[XYPayControl alloc] init];
    self.payControl.delegate = self;
    [self.payControl startQrPayWithPayType:XYPayTypeWechatQr
                                    amount:100
                                      body:@"细叶"
                                   tradeNo:outTradeNo
                                    mobile:@"15280533697"
                                     mchId:@"88793741592119799888"
                                  authCode:nil];
	``` 
3. 支付回调
在成功请求服务器后 sdk 会调用 control:resp: 方法返回必须的数据。其中 resp 是个 XYPayBaseResp 实例，resp 各个参数的具体含义请看 doc 目录下具体的文档。



# 可能遇到的问题
1. 怎么生成密钥？  
用 openssl 生成，mac 系统下自带  
    ````
    openssl genrsa -out private_key.pem 1024
    openssl req -new -key private_key.pem -out rsaCertReq.csr
    openssl x509 -req -days 3650 -in rsaCertReq.csr -signkey private_key.pem -out rsaCert.crt
    openssl x509 -outform der -in rsaCert.crt -out public_key.der　　　　　　　　　　　　　　　
    openssl pkcs12 -export -out private_key.p12 -inkey private_key.pem -in rsaCert.crt　　// Create private_key.p12 For IOS. 这一步，请记住你输入的密码，IOS代码里会用到
    ```` 

2. unrecognized selector sent to instance 问题   
运行中静态库报 unrecognized 错误时需要在 Build Setting 中的 Other Linker Flag 中添加 -ObjC，注意大小写。  
如果工程无法使用 -ObjC（在第三方库冲突等情况下使用 -ObjC 会报错) 可以使用 -force_load + .a文件地址。

3. 密钥好多，我到底该怎么做  
工程需要的密钥有两个，分别为：
    - .p12 格式的私钥.   
    这是开发者自己生成并且和服务器注册过的私钥。这个私钥用来保证服务器与客户端数据的一致性。如何在服务器注册请联系客服。 qq:233891975  
    - .der 格式的公钥.   
    这是服务器的公钥,用来验证客户端收到的数据未被修改。这个密钥在 cert 目录下获得。     
    需要注意的是，测试服务器和生产环境的服务器的公钥是不同的

4. 设置密钥好麻烦，我只想测试一下  
用 cert 目录下的 rsa_private_key.p12 和 rsa_public_key.der 来测试，或者直接看demo。

5. SDK 会不会很大  
付啦支付 SDK 的所有代码大小为 150 KB左右，加上必要的图片资料也不会很大。但是大额转账 SDK 因为涉及到了硬件所以会大一些。

有更多问题请联系官方群 qq:233891975 。详细文档见 doc 目录  

# 更新日志

|日期|版本|描述|  
| ---------- | -----------| ---------- |  
|2016.12.21|1.0.0|完成付啦支付基本功能, 支持 mpos 大额转账、二维码收款、扫码支付、统一支付，支持RSA加密验签|  
|2017.1.16|1.0.1|优化回调返回的参数，使其更加合理，支持个人及企业商户进件，查询交易订单|  


# todo
实现 CocoaPods 接入