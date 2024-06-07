//
//  NetworkMgr.h
//  Tofee
//
//  Created by mac on 2023/7/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^NetWorkSuccessBlk)(id responseObj);
typedef void(^NetWorkFailureBlk)(NSError *error);

@interface CFNetworkMgr : NSObject


+ (CFNetworkMgr *)sharedObject;

-(void)requestGameListCompleteBlk:(NetWorkSuccessBlk)successBlock failBlk:(NetWorkFailureBlk)failBlk;

-(void)requestGetSDKTokenCompleteBlk:(NetWorkSuccessBlk)successBlock failBlk:(NetWorkFailureBlk)failBlk;

-(void)requestCheckToEnterGameWithGameId:(NSInteger )gameId completeBlk:(NetWorkSuccessBlk)successBlock failBlk:(NetWorkFailureBlk)failBlk;

@end

NS_ASSUME_NONNULL_END
