//
//  HEDeviceService.h
//  MyDemo
//
//  Created by 尹啟星 on 16/9/18.
//  Copyright © 2016年 yinqixing. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <uSDK/uSDKDevice.h>
#define  DeviceService [HEDeviceService sharedInstance]
typedef void (^boolBlock)(BOOL success);
typedef void (^uSdkBingdingSuccessBlock)(uSDKDevice* dev);
typedef void (^uSdkBingdingFaildBlock)(NSError* error);

@interface HEDeviceService : NSObject
@property(nonatomic,assign) BOOL isuSDKStartSuccess;
+ (instancetype)sharedInstance;
- (void)startUSDK:(boolBlock)block;
- (void)smartLinkBindWithSSID:(NSString*)ssid
               password:(NSString*)pwd
                timeout:(NSTimeInterval)timeout
                success:(uSdkBingdingSuccessBlock)successBlock
                  faild:(uSdkBingdingFaildBlock)faildBlock;
@end
