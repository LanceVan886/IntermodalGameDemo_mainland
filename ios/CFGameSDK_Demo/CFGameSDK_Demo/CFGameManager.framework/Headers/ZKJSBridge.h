//
//  ZKJSBridge.h
//

#import <Foundation/Foundation.h>
#import "ZKWebView.h"
#import "ZKRegister.h"

@interface ZKJSBridge : NSObject

- (id)initWithWebView:(ZKWebView *)aWebView delegate:(id)delegate;

#pragma mark - register
+ (ZKClass*)registJSBridgeClient:(Class)aClass;
+ (ZKClass*)registClass:(ZKClass *)aClass;
+ (ZKClass*)registClass:(Class)aClass jsObjName:(NSString *)aJSObjectName;
+ (ZKClass*)registObject:(ZKJSObject*)aObject;
+ (ZKClass*)removeObject:(ZKJSObject*)aObject;
+ (ZKClass*)removeClass:(NSString*)aJSObjName;
+ (ZKClass*)getClass:(NSString*)aJSObjName;
//NOTE:4.6.2 by sawyer
+ (void)registerHandler:(NSString *)handlerName handler:(DYJSCallOCHandler)handler;
+ (void)removeHandler:(NSString *)handlerName;
+ (NSDictionary <NSString *,DYJSCallOCHandler>*)getHandlers;

#pragma mark - callJS
+ (void)callJSOnMainThread:(ZKWebView *)aWebView jsString:(NSString *)aJS;
+ (void)callJSFunctionOnMainThread:(ZKWebView *)aWebView funName:(NSString *)aFunName args:(NSString *)aArgs;

+ (void)callJS:(ZKWebView *)aWebView jsString:(NSString *)aJS;
+ (void)callJSFunction:(NSString *)function withJSONObject:(NSDictionary *)jsonObj WebView:(ZKWebView*)webview;
+ (void)callJSFunction:(NSString *)function withJSONString:(NSString *)jsonObj WebView:(ZKWebView*)webview;

+ (void)callbackJS:(ZKWebView *)aWebView callBackID:(NSString *)aCallbackId;
+ (void)callbackJS:(ZKWebView *)aWebView callBackID:(NSString *)aCallbackId jsonString:(NSString *)aStr;
+ (void)callbackJS:(ZKWebView *)aWebView callBackID:(NSString *)aCallbackId string:(NSString *)aStr;

#pragma mark - config
+ (void)openGlobalJSLog:(BOOL)aIsOpenJSLog;
+ (void)setIsOpenJSLog:(ZKWebView*)aWebview isOpenJSLog:(BOOL)aIsOpenJSLog;

@end
