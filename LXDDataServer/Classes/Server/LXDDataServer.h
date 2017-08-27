//
//  LXDDataServer.h
//  Pods
//
//  Created by didi on 2017/8/7.
//
//


#import "LXDDataAvailable.h"


typedef id<LXDDataAvailable> LXDDataManager;

/*!
 *  @class  LXDDataServer
 *  数据服务层
 */
@interface LXDDataServer : NSObject

/*!
 *  @method registerDataManager:forKey:
 *  注册数据管理对象
 */
+ (void)registerDataManager: (LXDDataManager)dataManager forKey: (NSString *)key;

/*!
 *  @method unregisterManagerForKey:
 *  移除管理对象
 */
+ (void)unregisterManagerForKey: (NSString *)key;

/*!
 *  @method dataManagerForKey:
 *  获取key对应的数据管理
 */
+ (LXDDataManager)dataManagerForKey: (NSString *)key;

@end
