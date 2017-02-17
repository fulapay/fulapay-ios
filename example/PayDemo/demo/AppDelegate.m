//
//  AppDelegate.m
//  demo
//
//  Created by cby on 2017/1/16.
//  Copyright © 2017年 iXiye. All rights reserved.
//

#import "AppDelegate.h"
#import <XYPaySDK/XYPayDefine.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    XYPayConfig *config = [[XYPayConfig alloc] init];
    config.isProduction = NO;
    config.enableDebug = YES;
    config.notifyUrl = @"127.0.0.1";
    config.mchCreateIp = @"127.0.0.1";
    config.derFileName = @"public_key";
    config.p12FileName = @"private_key";
    [XYPay setupWithAppId:@"1000015" appKey:@"aSsdaG%#f8eaLdf" config:config];
    [XYPay setRSAPassword:@"123456"];
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
