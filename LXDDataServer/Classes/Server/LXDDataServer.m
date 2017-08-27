//
//  LXDDataServer.m
//  Pods
//
//  Created by didi on 2017/8/7.
//
//

#import "LXDDataServer.h"



@interface LXDDataServer ()

@property (nonatomic, strong) dispatch_semaphore_t lock;
@property (nonatomic, strong) NSMutableDictionary<NSString *, LXDDataManager> *managers;

@end


@implementation LXDDataServer


#pragma mark - Public
+ (void)registerDataManager: (LXDDataManager)dataManager forKey: (NSString *)key {
    [[LXDDataServer _dataServer] _registerDataManager: dataManager forKey: key];
}

+ (void)unregisterManagerForKey: (NSString *)key {
    [[LXDDataServer _dataServer] _unregisterDataManagerForKey: key];
}

+ (LXDDataManager)dataManagerForKey: (NSString *)key {
    return [[LXDDataServer _dataServer] _dataManagerForKey: key];
}


#pragma mark - Private
+ (instancetype)_dataServer {
    static LXDDataServer *dataServer;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        dataServer = [LXDDataServer new];
        dataServer.lock = dispatch_semaphore_create(1);
        [[NSNotificationCenter defaultCenter] addObserver: self selector: @selector(_memoryWarning) name: UIApplicationDidReceiveMemoryWarningNotification object: nil];
    });
    return dataServer;
}

- (void)_memoryWarning {
    [self.managers.allValues makeObjectsPerformSelector: @selector(cacheDataToLocal)];
}

- (void)_registerDataManager: (LXDDataManager)dataManager forKey: (NSString *)key {
    dispatch_semaphore_wait(_lock, DISPATCH_TIME_FOREVER);
    [_managers setObject: dataManager forKey: key];
    dispatch_semaphore_signal(_lock);
}

- (void)_unregisterDataManagerForKey: (NSString *)key {
    dispatch_semaphore_wait(_lock, DISPATCH_TIME_FOREVER);
    [_managers removeObjectForKey: key];
    dispatch_semaphore_signal(_lock);
}

- (LXDDataManager)_dataManagerForKey: (NSString *)key {
    dispatch_semaphore_wait(_lock, DISPATCH_TIME_FOREVER);
    LXDDataManager manager = [_managers objectForKey: key];
    dispatch_semaphore_signal(_lock);
    return manager;
}


@end
