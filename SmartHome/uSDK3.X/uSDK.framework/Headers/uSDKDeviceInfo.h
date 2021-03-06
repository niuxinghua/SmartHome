//
//  uSDKDeviceInfo.h
//  uSDK
//
//  Created by liugn on 15/12/11.
//  Copyright © 2015年 haier. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "uSDKConstantInfo.h"

/**
 *	设备网络状态
 */
typedef NS_ENUM(NSInteger,uSDKDeviceState) {
    /**
     *  未连接
     */
    uSDKDeviceStateUnconnect = 0,
    /**
     *  连接中
     */
    uSDKDeviceStateConnecting,
    /**
     *  连接成功
     */
    uSDKDeviceStateConnected,
    /**
     *  就绪
     */
    uSDKDeviceStateReady,
    /**
     *  离线
     */
    uSDKDeviceStateOffline
};

/**
 *	设备协议类型
 */
typedef NS_ENUM(NSInteger,uSDKAppProtocolType) {
    /**
     *  协议类型--标准
     */
    uSDKProtocolTypeSTD,
    /**
     *  协议类型--六位码
     */
    uSDKProtocolTypeSIXID,
};

/**
 *	设备网络类型
 */
typedef NS_ENUM(NSInteger,uSDKDeviceNetTypeConst) {
    /**
     *  远程
     */
    NET_TYPE_REMOTE = 0,
    /**
     *  本地
     */
    NET_TYPE_LOCAL,
} ;

@class uSDKErrorInfo,uSDKDeviceAttribute;
@protocol uSDKDeviceDelegate;

/**
 *  家电设备信息类，包括家电设备的基本属性信息。
 */
@interface uSDKDeviceInfo : NSObject{
    NSString* _deviceID;
    NSString* _ip;
    NSString* _uplusID;
    BOOL _isRemoteDeviceOnline;
    uSDKDeviceState _state;
    BOOL _isSubscribed;
    
    NSString* _eProtocolVer;
    NSString* _smartLinkPlatform;
    NSString* _smartLinkSoftwareVersion;
    NSString* _smartLinkHardwareVersion;
    NSString* _smartLinkDevfileVersion;
    uSDKDeviceNetTypeConst _netType;
    uSDKDeviceTypeConst _type;
    NSInteger _middleType;
    NSString* _specialId;
}

/**
 *  设备mac；
 */
@property (nonatomic, copy ,readonly) NSString* mac;

/**
 *  设备ID；
 */
@property (nonatomic, copy ,readonly) NSString* deviceID;

/**
 *  设备IP；
 */
@property (nonatomic, copy ,readonly) NSString* ip;

/**
 *  设备的类型唯一识别码，用来唯一标识设备类型；
 */
@property (nonatomic, copy ,readonly) NSString* uplusID;

/**
 *  获取设备状态。
 */
@property (nonatomic, assign, readonly) uSDKDeviceState state;

/**
 *  设备是否已被订阅；
 */
@property (nonatomic, assign ,readonly) BOOL isSubscribed;

/**
 *  设备遵守的E++协议版本号；
 */
@property (nonatomic, strong ,readonly) NSString* eProtocolVer;

/**
 *  设备wifi的平台信息；
 */
@property (nonatomic, strong ,readonly) NSString* smartLinkPlatform;

/**
 *  设备模块的软件版本号；
 */
@property (nonatomic, strong ,readonly) NSString* smartLinkSoftwareVersion;

/**
 *  设备模块的硬件版本号；
 */
@property (nonatomic, strong ,readonly) NSString* smartLinkHardwareVersion;

/**
 *  设备模块使用的配置文件版本号；
 */
@property (nonatomic, strong ,readonly) NSString* smartLinkDevfileVersion;

/**
 *  设备的类型唯一识别码，用来唯一标识家电设备类型；
 */
@property (nonatomic, strong ,readonly) NSString* typeIdentifier DEPRECATED_ATTRIBUTE;

/**
 *  设备大类分类，设备按照大类通常分类为：洗衣机、冰箱、柜机空调、冰箱酒柜等。详细请见uSDKDeviceTypeConst枚举定义；
 */
@property (nonatomic, assign ) uSDKDeviceTypeConst type;

/**
 *  设备中类
 */
@property (nonatomic, assign ,readonly) NSInteger middleType;

/**
 *  设备专用号
 */
@property (nonatomic, strong ,readonly) NSString* specialId;

/**
 *  设备的网络类型。网络类型是指本地和远程，详细请见uSDKDeviceNetTypeConst枚举定义；
 */
@property (nonatomic, assign ,readonly) uSDKDeviceNetTypeConst netType;

/**
 *  APP通过解析获取到的远程家电设备json内容得到设备信息，生成远程家电设备对象。
 *
 *  @param deviceID                 设备ID
 *  @param uplusID                  设备类型唯一标识码
 *  @param isRemoteDeviceOnline     是否远程在线
 *
 *  @return 返回uSDKDeviceInfo实例
 */
-(instancetype)initWithDeviceID:(NSString*)deviceID
                        uplusID:(NSString*)uplusID
                       isOnline:(BOOL)isRemoteDeviceOnline;

@end

/**
 *  执行操作命令，特殊设备返回两种错误信息，对应此类中的两个成员变量。一般设备只返回一个错误码（只有一个属性有值）。
 */
@interface uSDKErrorInfo : NSObject

/**
 *	@brief  功能描述：<br>
 *      错误信息号
 */
@property (nonatomic, assign) NSInteger errorNo;

/**
 *	@brief  功能描述：<br>
 *      错误信息id
 */
@property (nonatomic, assign) NSInteger errorInfoId;

@end