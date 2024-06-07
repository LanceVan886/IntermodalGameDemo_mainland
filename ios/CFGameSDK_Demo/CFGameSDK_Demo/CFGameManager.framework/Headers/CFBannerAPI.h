//
//  CFBannerAPI.h
//  Tofee
//
//  Created by mac on 2023/7/9.
//

#import <Foundation/Foundation.h>
#import "ZKWebView.h"
#import "ZKArgList.h"

NS_ASSUME_NONNULL_BEGIN

@interface CFBannerAPI : NSObject

// 获取用户信息
+(void)getBaseInfo:(ZKWebView*)aWebView argList:(ZKArgList*)args;

// 打开充值页面
+(void)openChargePage:(ZKWebView*)aWebView argList:(ZKArgList*)args;

// 关闭游戏页面
+(void)closeGamePage:(ZKWebView*)aWebView argList:(ZKArgList*)args;

@end

NS_ASSUME_NONNULL_END
