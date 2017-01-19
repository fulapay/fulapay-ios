# fulapay-ios
Fulapay SDK in OC and Swift

# openssl

````
openssl genrsa -out private_key.pem 1024
openssl req -new -key private_key.pem -out rsaCertReq.csr
openssl x509 -req -days 3650 -in rsaCertReq.csr -signkey private_key.pem -out rsaCert.crt
openssl x509 -outform der -in rsaCert.crt -out public_key.der　　　　　　　　　　　　　　　// Create public_key.der For IOS
 
openssl pkcs12 -export -out private_key.p12 -inkey private_key.pem -in rsaCert.crt　　// Create private_key.p12 For IOS. 这一步，请记住你输入的密码，IOS代码里会用到
```` 

.der 是付啦服务器的公钥，.p12 是开发者的私钥。

# unrecognized selector sent to instance 问题

运行中静态库报 unrecognized 错误时需要在 Build Setting 中的 Other Linker Flag 中添加 -ObjC，注意大小写。如果工程无法使用-ObjC（在第三发库冲突等情况下使用 -ObjC 会报错) 可以使用 -force_load + .a文件地址。

# 上手指南

## 添加 sdk
### 手动添加

将 .a 文件、其他 .h 文件以及 .xcassets 文件拖到工程中。在需要的地方导入 `#import "XYPayDefine.h"`。

### cocoapods
开发中

## 初始化
todo
