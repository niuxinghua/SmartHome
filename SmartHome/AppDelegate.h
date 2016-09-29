//
//  AppDelegate.h
//  SmartHome
//
//  Created by 尹啟星 on 16/9/18.
//  Copyright © 2016年 尹啟星. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>
#import "HEDeviceService.h"
@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property(nonatomic,assign) BOOL isUSDKStartSuccess;
@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;

- (void)saveContext;
- (NSURL *)applicationDocumentsDirectory;
- (NSString *)currentSSID;

@end

