//
//  CFUserModel.h
//  Tofee
//
//  Created by mac on 2023/7/10.
//

#import <Foundation/Foundation.h>
#import <CFGameSDK/CFGameModel.h>
#import <CFGameSDK/CFGameWebviewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface CFGameEngine : NSObject



@property (nonatomic,assign) NSInteger appId;

@property (nonatomic,copy) NSString *language;


/*
 *  open game list
 */
-(void)showGameList;

/*
 *  set user info and code
 */
-(void)setUserInfo:(NSString *)userId userCode:(NSString *)userCode;


-(void)getGameListWithSuccess:(void(^)(NSArray<CFGameModel *> *gameList))successBlk failure:(void(^)(int code, NSString *msg))failBlk;


-(void)loadHalfWindowGame:(NSString *)gameId url:(NSString *)url;

-(void)loadFullWindowGame:(NSString *)gameId url:(NSString *)url;

- (void)sentExtToGame:(NSString *)extStr;

/*
 *  finish game window
 */
-(void)finishGameWindow;

/*
 *  terminate current game
 */
-(void)terminateGame;

/*
 *  joinGame with position
 */
-(void)joinGame:(int)position;

/*
 *  开始游戏
 */
- (void)gameStart;

/*
 *  踢人  uid : 用户id
 */
 
- (void)playerRemoveWithUid:(NSString *)uid;

/*
 *   打开/关闭 背景音乐 mode : YES 开 NO 关
 */
- (void)gameBackgroundMusicSet:(BOOL)mode;


/*
 *   打开/关闭音效 mode : YES 开 NO 关
 */
- (void)gameSoundSet:(BOOL)mode;

/*
 *  refresh game userInfo
 */
-(void)refreshUserInfo;

-(CFGameWebviewController *)createGameWebViewWithUrl:(NSString *)gameUrl gameId:(int)gameId;

@end

NS_ASSUME_NONNULL_END
