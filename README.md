# fulapay-ios

# 上手指南

## 目录结构

```
|
|-doc       文档
|-example   例子
|-sdk       sdk
|-cert      相关的密钥
```

## 添加 sdk
1. 手动添加

将 .a 文件、其他 .h 文件以及 .xcassets 文件拖到工程中。在需要的地方导入 `#import "XYPayDefine.h"`。

2. CocoaPods
开发中

3. 添加权限
在 info.plist 中添加相机权限 Privacy - Photo Library Usage Description

## 使用

1. 在 AppDelegate 中初始化 XYPay  

    ```
    XYPayConfig *config = [[XYPayConfig alloc] init];
    config.notifyUrl = @"127.0.0.1";
    config.mchCreateIp = @"127.0.0.1";
    config.isProduction = NO;
    config.enableDebug = YES;
    config.withdrawType = @"1";
    config.derFileName = @"public_key";
    config.p12FileName = @"private_key";
    [XYPay setupWithAppId:@"1000015" appKey:@"dadf#kjfiel" config:config];
    [XYPay setRSAPassword:@"123456"];
    ```

2. 在需要调用支付的地方用 XYPayControl 实例调用对应方法 
 
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

# 可能遇到的问题
## openssl (密钥生成)

````
openssl genrsa -out private_key.pem 1024
openssl req -new -key private_key.pem -out rsaCertReq.csr
openssl x509 -req -days 3650 -in rsaCertReq.csr -signkey private_key.pem -out rsaCert.crt
openssl x509 -outform der -in rsaCert.crt -out public_key.der　　　　　　　　　　　　　　　// Create public_key.der For IOS
 
openssl pkcs12 -export -out private_key.p12 -inkey private_key.pem -in rsaCert.crt　　// Create private_key.p12 For IOS. 这一步，请记住你输入的密码，IOS代码里会用到
```` 

.der 是付啦服务器的公钥，.p12 是开发者的私钥。

## unrecognized selector sent to instance 问题

运行中静态库报 unrecognized 错误时需要在 Build Setting 中的 Other Linker Flag 中添加 -ObjC，注意大小写。如果工程无法使用-ObjC（在第三方库冲突等情况下使用 -ObjC 会报错) 可以使用 -force_load + .a文件地址。

有更多问题请联系官方群。详细文档见 doc 目录
