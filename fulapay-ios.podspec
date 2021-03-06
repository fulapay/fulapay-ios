Pod::Spec.new do |s|
    s.name                  = 'fulapay-ios'
    s.version               = '1.0.3'
    s.license               = { :type => 'Copyright', :text => 'Copyright 2016 ixiye.com. All rights reserved.'}
    s.summary               = 'Fulapay SDK for iOS'
    s.homepage              = 'https://github.com/fulapay/fulapay-ios'
    s.authors               = { 'Hua Wen' => '394220838@qq.com' }
    s.source                = { :git => 'https://github.com/fulapay/fulapay-ios.git', :tag => s.version}
    s.requires_arc          = true
    s.ios.deployment_target = '7.0'
    s.platform              = :ios
    s.requires_arc          = true
    s.source_files          = 'sdk/XYPaySDK/XYPaySDK.framework/Headers/*.h'
    s.vendored_frameworks   = 'sdk/XYPaySDK/XYPaySDK.framework'
    s.resources             = 'sdk/XYPaySDK/XYPaySDK.framework/Assets.car'
end
