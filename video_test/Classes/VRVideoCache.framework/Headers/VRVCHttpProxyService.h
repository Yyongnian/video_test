//
//  VRVCHttpProxyService.h
//  VRVideoCache
//
//  Created by 58 on 2017/8/14.
//  Copyright © 2017年 58. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol VRVCHttpProxyServiceDelegate <NSObject>

/**
 * 下载完成回调
 */
- (void)serverFinishDownloadVideoPath:(NSURL*)url;

@end

@class VRVCGCDWebServer;
@interface VRVCHttpProxyService : NSObject

+ (VRVCHttpProxyService*)sharedInstance;

@property(nonatomic, weak) id<VRVCHttpProxyServiceDelegate> delegate;

@property (nonatomic, assign) BOOL webServerDidStop;

/**
 * suspendedInBackGround 是否在后台下载数据
 */
@property(nonatomic, readonly)BOOL suspendedInBackGround;

/**
 * 启动server
 * param = YES 进入后台 关闭server，停止所有请求
 * param = NO 进入后台, 不关闭server
 */
- (void)startServerWithSuspendedInBackGround:(BOOL) suspendedInBackGround;

/**
 * 关闭server
 */
- (void)stopServer;

/**
 * @brief 获取本地服务地址
 * @param url Documents(Cache 和libary 都可以)  到VR路径
 * 例: url = Documents/VRHousePlayer+Datas/
 * 供VR 使用 获取本地文件使用
 */
- (NSString *)getProxyUrl:(NSString*)url;

/**
 * 查询server是否在运行状态
 */
- (BOOL)isRunning;

/**
 * 当前SDK版本
 */
- (NSString*)getVideoCacheVersion;

@end
