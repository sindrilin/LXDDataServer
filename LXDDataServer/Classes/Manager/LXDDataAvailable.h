//
//  LXDDataAvailable.h
//  Pods
//
//  Created by didi on 2017/8/7.
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^DataFetchHandle)(NSArray *datas,  NSError * _Nullable error);

/*!
 *  @protocol   LXDDataAvailable
 *  统一数据获取接口
 */
@protocol LXDDataAvailable <NSObject>

@required
/*!
 *  @method fetchAllDataWithFetchHandle:
 *  拉取全部数据，不适合翻页数据
 */
- (void)fetchAllDataWithFetchHandle: (DataFetchHandle)fetchHandle;

/*!
 *  @method fetchDatasAtIndex:fetchHandle:
 *  获取下标对应的数据
 */
- (void)fetchDatasAtIndex: (NSUInteger)index fetchHandle: (DataFetchHandle)fetchHandle;

/*!
 *  @method appendData:
 *  追加数据
 */
- (void)appendData: (id)data;

/*!
 *  @method insertData:atIndex:
 *  在下标位置插入数据
 */
- (void)insertData: (id)data atIndex: (NSUInteger)index;

/*!
 *  @method deleteDataAtIndex:
 *  删除指定下标的数据
 */
- (void)deleteDataAtIndex: (NSUInteger)index;

/*!
 *  @method cacheDataToLocal
 *  在内存紧急的时候将数据保存到本地磁盘，从内存中移除
 */
- (void)cacheDataToLocal;

@optional
/*!
 *  @method fetchDatasInRange:fetchHandle:
 *  获取range范围的数据
 */
- (void)fetchDatasInRange: (NSRange)range fetchHandle: (DataFetchHandle)fetchHandle;

/*!
 *  @method fetchDatasFromServerWithPage:complete:
 *  适合翻页界面调用，请求对应页数的数据
 */
- (void)fetchDatasFromServerWithPage: (NSUInteger)page complete: (DataFetchHandle)complete;

/*!
 *  @method fetchDatasAtIndexSet:fetchHandle:
 *  请求indexSet当中所有对应下标的数据
 */
- (void)fetchDatasAtIndexSet: (NSIndexSet *)indexSet fetchHandle: (DataFetchHandle)fetchHandle;

/*!
 *  @method replaceData:atIndex:
 *  替换下标位置的数据
 */
- (void)replaceData: (id)data atIndex: (NSUInteger)index;

/*!
 *  @method dropLastData
 *  删除最后一个数据
 */
- (void)dropLastData;

/*!
 *  @method dropFirstData
 *  删除第一个数据
 */
- (void)dropFirstData;

/*!
 *  @method dropAllData
 *  清除所有数据
 */
- (void)dropAllData;

/*!
 *  @method deleteDataInIndexSet:
 *  删除indexSet内所有下标位置的数据
 */
- (void)deleteDataInIndexSet: (NSIndexSet *)indexSet;

/*!
 *  @method sortByUsingSelector:
 *  使用指定的方法对数据进行排序，方法应该返回NSComparisonResult结果
 */
- (void)sortByUsingSelector: (SEL)selector;

/*!
 *  @method sortByUsingCompare:
 *  使用block对数组数据进行排序
 */
- (void)sortByUsingCompare: (NSComparisonResult(^)(id data1, id data2))compare;

@end

NS_ASSUME_NONNULL_END
