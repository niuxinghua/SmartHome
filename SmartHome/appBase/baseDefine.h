//
//  baseDefine.h
//  FunTime-OC
//
//  Created by paul-y on 16/4/2.
//  Copyright © 2016年 Paul-Yin. All rights reserved.
//

#ifndef baseDefine_h
#define baseDefine_h
// 日志打印设置
#ifdef DEBUG // 处于开发阶段
#define Log(xx,...) NSLog(@"%s(%d): " xx, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)

//A better version of NSLog
#define NSLog(format, ...) do {                                                                         \
                            fprintf(stderr, "<%s : %d> %s\n",                                           \
                            [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String],  \
                            __LINE__, __func__);                                                        \
                            (NSLog)((format), ##__VA_ARGS__);                                           \
                            fprintf(stderr, "-------\n");                                               \
                            } while (0)

#else // 处于发布阶段
#define Log(...)
#define NSLog(format, ...)
#endif
//颜色
#define REDCOLOR [UIColor redColor]
#define WHITECOLOR [UIColor whiteColor]
#define BLUECOLOR [UIColor blueColor]
#define GREENCOLOR [UIColor greenColor]

#define RGBColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]

#define RGBGrayColor(a) [UIColor colorWithRed:(a)/255.0 green:(a)/255.0 blue:(a)/255.0 alpha:1.0]
// 设备判断

#define isiPad                  (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

#define isiPhone                (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)




#define isIPhone5               ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

#define isIPhone4               ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)

#define isIPhone6               ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)

#define isIPhone6Plus               ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)



// 系统版本

#define SYSTEM_VERSION          [[[UIDevice currentDevice] systemVersion] floatValue]





#define DICT_VAL(a, b)              [a valueForKeyPath:b]
#define DICT_INTVAL(a, b)           [[a valueForKeyPath:b] intValue]
#define DICT_FLOATVAL(a, b)         [[a valueForKeyPath:b] floatValue]
#define DICT_BOOLVAL(a, b)          DICT_INTVAL(a,b)==1

#define INT(a)                      [NSNumber numberWithInt:a]
#define INTEGER(a)                  [NSNumber numberWithInteger:a]
#define DOUBLE(a)                   [NSNumber numberWithDouble:a]
#define FLOAT(a)                    [NSNumber numberWithFloat:a]
#define STRFORMAT(a, ...)          [NSString stringWithFormat:a, ##__VA_ARGS__]

#define SYSFont(a) [UIFont systemFontOfSize:a]
#define SYSBoldFont(a) [UIFont boldSystemFontOfSize:a]



// 屏幕

#define MAIN_SCREEN         [UIScreen mainScreen].bounds

#define USER_DEFAULT        [NSUserDefaults standardUserDefaults]
#define FILE_DEFAULT        [NSFileManager defaultManager]

#define isReachability      [[Reachability reachabilityForInternetConnection] isReachable]
#define isWIFIReachability  [[Reachability reachabilityForLocalWiFi] currentReachabilityStatus] != NotReachable
#define is3GReachability    [[Reachability reachabilityForInternetConnection] currentReachabilityStatus] != NotReachable


#define ScreenHeight        [[UIScreen mainScreen] bounds].size.height
#define ScreenWidth         [[UIScreen mainScreen] bounds].size.width

#define NavgationBarHeight 44
#define StatusBarHeight    20
#define TabbarHeight       49
#define Nav_StatusBarHeight (NavgationBarHeight + StatusBarHeight)
#define UIVisibleHeight     (ScreenHeight-NavgationBarHeight-StatusBarHeight-TabbarHeight)
// 日期格式

#define  DATE_FORMATE_YYYY_MM_DD                        @"yyyy-MM-dd"
#define  DATE_FORMATE_HH_MM_SS_COLON                    @"HH:mm:ss"
#define  DATE_FORMATE_HH_MM_SS                          @"HH-mm-ss"
#define  DATE_FORMATE_HH_MM__COLON                      @"HH:mm"
#define  DATE_FORMATE_YYYY_MM_DD_HH_MM_SS               @"yyyy-MM-dd HH:mm:ss"
#define  DATE_FORMATE_YYYYMMDDHHMMSS                    @"yyyyMMddHHmmss"
//字体
#define FONT_18 [UIFont boldSystemFontOfSize:18]
#endif /* baseDefine_h */
//方法简化
#define BARBUTTON(TITLE, SELECTOR) 	[[UIBarButtonItem alloc] initWithTitle:TITLE style:UIBarButtonItemStylePlain target:self action:SELECTOR]
#define SYSBARBUTTON(ITEM, SELECTOR) [[UIBarButtonItem alloc] initWithBarButtonSystemItem:ITEM target:self action:SELECTOR]
//系统API单例
#define NotifiyDefaultCenter [NSNotificationCenter defaultCenter]
//打印当前线程
#define LogThread NSLog(@"%@",[NSThread currentThread])
//打印方法名字和行数
/**
 *  打印方法名字和行数
 */
#define LogFunc   NSLog(@"%s(%d)",__func__,__LINE__);

#define theApp  ((AppDelegate*)[[UIApplication sharedApplication] delegate])

