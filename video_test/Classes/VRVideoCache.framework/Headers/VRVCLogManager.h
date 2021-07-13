//
//  WBVKLogManager.h
//  WUBAVideoKit
//
//  Created by 58 on 2017/5/22.
//  Copyright © 2017年 58. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, VRVCLOGLEVEL) {
    VRVC_LOG_INFO,
    VRVC_LOG_WARNING,
    VRVC_LOG_ERROR,
    VRVC_LOG_NONE,
};

@interface VRVCLogManager : NSObject

+ (instancetype)sharedInstance;

- (void)logMessage:(VRVCLOGLEVEL)level Info:(NSString *)logInfo;

- (void)setMinLogLevel:(VRVCLOGLEVEL)level;

@end
