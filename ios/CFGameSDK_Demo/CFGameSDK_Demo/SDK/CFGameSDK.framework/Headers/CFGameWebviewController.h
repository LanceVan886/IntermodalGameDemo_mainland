//
//  CFGameWebviewController.h
//  Tofee
//
//  Created by mac on 2023/7/9.
//

#import <UIKit/UIKit.h>
#import <CFGameSDK/ZKWebView.h>

NS_ASSUME_NONNULL_BEGIN

@interface CFGameWebviewController : UIViewController

@property (strong, nonatomic) ZKWebView *webView;

@property (copy, nonatomic) NSString *webUrl;

@property (nonatomic,assign) int g_id;

@property (assign,nonatomic) BOOL isHalfScreen;


-(void)sentExtToGame:(NSString *)extStr;

// 刷新用户信息
-(void)refreshUserInfo;

-(void)terminateGame;

-(void)joinGame:(int)position;

-(void)gameStartMethod;

-(void)gamePlayerRemoveMethedWithUid:(NSString *)uid;

-(void)gameBGMMusicSet:(BOOL)mode;

-(void)gameSoundSet:(BOOL)mode;

@end

NS_ASSUME_NONNULL_END
