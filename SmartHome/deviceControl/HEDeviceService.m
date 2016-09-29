
//
//  HEDeviceService.m
//  MyDemo
//
//  Created by 尹啟星 on 16/9/18.
//  Copyright © 2016年 yinqixing. All rights reserved.
//

#import "HEDeviceService.h"
#import "uSDK/uSDKDeviceManager.h"
#import <uSDK/uSDKManager.h>

@interface HEDeviceService () <uSDKDeviceManagerDelegage,uSDKDeviceDelegate>
@end
@implementation HEDeviceService

+ (instancetype)sharedInstance
{
    static HEDeviceService *instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        @synchronized(self) {
            instance = [[HEDeviceService alloc] init];
        }
    });
    
    return instance;
}
- (instancetype)init{
    self = [super init];
    if (self) {
        [uSDKDeviceManager defaultDeviceManager].delegate = self;
    }
    return  self;
}
- (void)startUSDK:(boolBlock)block{
    [[uSDKManager defaultManager] startSDKWithAppId:AppID secretKey:app_secret success:^{
        block(YES);
        DeviceService.isuSDKStartSuccess = YES;
        Log(@"uSDK启动成功");
    } failure:^(NSError *error) {
        block(NO);
        DeviceService.isuSDKStartSuccess = NO;
        Log(@"uSDK启动失败");
        
        
    }];
}
- (void)smartLinkBindWithSSID:(NSString*)ssid
                     password:(NSString*)pwd
                      timeout:(NSTimeInterval)timeout
                      success:(uSdkBingdingSuccessBlock)successBlock
                        faild:(uSdkBingdingFaildBlock)faildBlock {
    __weak typeof(self) weakSelf = self;
    [[uSDKDeviceManager defaultDeviceManager] configDeviceBySmartLinkWithSSID:ssid
                               password:pwd
                        timeoutInterval:60.0
    success:^(uSDKDevice *device) {
        if (device) {
            successBlock(device);
            device.delegate = weakSelf;
        }
    }
     failure:^(NSError *error) {
         faildBlock(error);
    }];
}
#pragma mark - uSDKDeviceManagerDelegage
- (void)deviceManager:(uSDKDeviceManager *)deviceManager didAddDevices:(NSArray<uSDKDevice *> *)devices{
    
}
- (void)deviceManager:(uSDKDeviceManager *)deviceManager didBindDevice:(NSString *)deviceID{
    
}
- (void)deviceManager:(uSDKDeviceManager *)deviceManager didUnbindDevice:(NSString *)deviceID{
    
}
- (void)deviceManager:(uSDKDeviceManager *)deviceManager didRemoveDevices:(NSArray<uSDKDevice *> *)devices{
    
}
- (void)deviceManager:(uSDKDeviceManager *)deviceManager didUpdateCloudState:(uSDKCloudConnectionState)state error:(NSError *)offlineReason{
    
}
#pragma mark - uSDKDeviceDelegate
- (void)deviceDidUpdateBaseInfo:(uSDKDevice *)device{
    
}
- (void)device:(uSDKDevice *)device didUpdateVlaueForAttributes:(NSArray<uSDKDeviceAttribute *> *)attributes{
    
}
- (void)device:(uSDKDevice *)device didUpdateState:(uSDKDeviceState)state error:(NSError *)error{
    
}
- (void)device:(uSDKDevice *)device didReceiveAlarms:(NSArray<uSDKDeviceAlarm *> *)alarms{
    
}

@end

