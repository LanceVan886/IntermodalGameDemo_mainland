//
//  CFGameWebviewController.h
//  Tofee
//
//  Created by mac on 2023/7/9.
//

#import <UIKit/UIKit.h>
#import "ZKWebView.h"

NS_ASSUME_NONNULL_BEGIN

@interface CFGameWebviewController : UIViewController

@property (strong, nonatomic) ZKWebView *webView;

@property (copy, nonatomic) NSString *webUrl;

@property (assign,nonatomic) BOOL isHalfScreen;


// 刷新用户信息
-(void)refreshUserInfo;

@end

NS_ASSUME_NONNULL_END
