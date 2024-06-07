//
//  CFGameSDK+Private.h
//  CFGameSDK
//
//  Created by mac on 2023/7/19.
//

#import <CFGameSDK/CFGameSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface CFGameSDK ()


@property (nonatomic,weak,readonly) id<CFGameSDKDelegate> delegate;

@property (nonatomic,weak,readonly) ZKLogger *logger;

@property (nonatomic,assign,readonly) BOOL isProduct;


+(CFGameSDK *)getInstance;


-(UIApplication *)getApplication;

@end

NS_ASSUME_NONNULL_END
