//
//  CFGameSDK+Private.h
//  CFGameSDK
//
//  Created by mac on 2023/7/19.
//

#import "CFGameSDK.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CFGameSDK ()


@property (nonatomic,weak,readonly) id<CFGameSDKDelegate> delegate;

@property (nonatomic,weak,readonly) id<CFGameSDKLoginDelegate> loginDelegate;

@property (nonatomic,weak,readonly) id<CFGameLifeCycleDelegate> gameLifecycleDelegate;


@property (nonatomic,weak,readonly) id<CFGameSDKRTCDelegate> rtcDelegate;

@property (nonatomic,weak,readonly) ZKLogger *logger;

@property (nonatomic,assign,readonly) BOOL isProduct;


+(CFGameSDK *)getInstance;


-(UIApplication *)getApplication;

-(void)startLoginTokenTimer:(int)remainTime;

@end

NS_ASSUME_NONNULL_END
