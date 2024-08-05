//
//  CFGameSDK.h
//  CFGameSDK
//
//  Created by mac on 2023/7/10.
//

#import <Foundation/Foundation.h>
#import "CFGameModel.h"
#import "ZKLog.h"

typedef struct {
    CGFloat top;
    CGFloat left;
    CGFloat bottom;
    CGFloat right;
    CGFloat minScaleLimit;
} CFGameEdgeInsets;

@class CFGameEngine;

typedef void(^GetGameListSuccessBlk)(NSArray<CFGameModel *> *gameList);
typedef void(^GetGameListFailureBlk)(int code ,NSString *msg);

@protocol CFGameSDKDelegate <NSObject>
@required

/**
 *
 * sdk回调渠道方，拉起渠道方的充值页面
 */
- (void)openChargePage;

/**
 *
 * Returns：当前用户所在的房间号，如果没有互动玩法可直接返回空字符串
 */
- (NSString *)onGetCurrentRoomId;
/**
 *
 * Returns：如果平台无需指定游戏管理员可直接返回false
 */
- (BOOL)onIsRoomOwner;
/**
 *
 * Returns：游戏视图的安全区域，若无要求可返回null
 */
- (CFGameEdgeInsets)onWindowSafeArea;

@end


@protocol CFGameSDKLoginDelegate <NSObject>
@required

/**
 *
 * 用户登录成功回调
 */
- (void)onLoginSuccess;

/**
 *
 * 用户登录失败回调
 */
- (void)onLoginFailCode:(int)code message:(NSString *)msg;
/**
 *
 * token 更新后回调，接入方通常无需关注此接口
 */
- (void)onRefreshToken:(NSString *)token;

@end

NS_ASSUME_NONNULL_BEGIN

@interface CFGameSDK : NSObject


/*
 *  @param app : UIApplication 当前application
 *  @param appId : 创发提供的appId
 *  @param appKey : 创发提供的appKey
 */
+(void)setUpSDKWithApplication:(UIApplication *)app appId:(NSInteger)appId language:(NSString *)language isProduct:(BOOL)isProduct;


/*
 *  @param userId : 接入方的用户id
 *  @param userCode : 接入方的用户code,用于创发向接入方校验用户的合法性
 */
+(void)setUserInfo:(NSString *)userId code:(NSString *)userCode loginCallBack:(id<CFGameSDKLoginDelegate>)loginCallBack;

/*
 *  拉起游戏列表弹窗
 */
+(void)showGameList;

/*
 *  获取游戏列表
 */
+(void)getGameListWithSuccess:(GetGameListSuccessBlk)successBlk failure:(GetGameListFailureBlk)failBlk;

/*
 *  加载半屏游戏
 *  @param gameId : 游戏id
 *  @url   url : 游戏url
 */
+(void)loadHalfWindowGame:(NSString *)gameId url:(NSString *)url;

/*
 *  加载全屏游戏
 *  @param gameId : 游戏id
 *  @url   url : 游戏url
 */
+(void)loadFullWindowGame:(NSString *)gameId url:(NSString *)url;

/*
 *  销毁游戏窗口
 */
+(void)finishGameWindow;

/*
 *  通过js通知游戏刷新用户资产信息
 */
+(void)refreshUserInfo;

/*
 *  设置接入方回调
 */
+(void)setBizCallback:(id<CFGameSDKDelegate>)callback;

/*
 *  设置日志
 */
+(void)setLogger:(ZKLogger *)logger;

+(CFGameEngine *)getEngine;


/*
 * 释放sdk
 */
+(void)releaseSDK;




/*
 * 获取当前版本号
 */
+ (NSString *)sdkVersion;


@end

NS_ASSUME_NONNULL_END
