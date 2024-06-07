//
//  ZKJSExecutor.h
//

#import <Foundation/Foundation.h>
#import "ZKBaseDefine.h"
#import "ZKWebView.h"

#define kJSToJSONString(js) @"JSON.stringify("#js")"

NS_ASSUME_NONNULL_BEGIN

@interface ZKJSExecutor : NSObject


+ (void)callJSFunction:(NSString *)aFunction withJSONObject:(NSDictionary *)aJsonObj inWebView:(ZKWebView*)aWebView completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))aCompletionHandler;

+ (void)callJSFunctionOnMainThread:(NSString *)aFunction withJSONObject:(NSDictionary *)aJsonObj inWebView:(ZKWebView*)aWebView completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))aCompletionHandler;

+ (void)callJSFunctionOnMainThread:(NSString *)aFunction withJSONString:(NSString *)aJsonString inWebView:(ZKWebView*)aWebView completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))aCompletionHandler;


+ (void)callJSFunction:(NSString *)aFunction withArg:(NSString *)aArg inWebView:(ZKWebView*)aWebView completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))aCompletionHandler;

+ (void)callJSFunction:(NSString *)aFunction withJSONString:(NSString *)aJsonString inWebView:(ZKWebView*)aWebView completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))aCompletionHandler;

+ (void)callJSFunction:(NSString *)aFunction  inWebView:(ZKWebView*)aWebView completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))aCompletionHandler;

+ (void)callJS:(NSString *)aJS inWebView:(ZKWebView*)aWebView completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))aCompletionHandler;

+ (void)callJSOnMainThread:(NSString*)aJS inWebView:(ZKWebView*)aWebView completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))aCompletionHandler;


#pragma mark -
#pragma mark callbackJS
+ (void)callbackJS:(ZKWebView*)aWebview callbackId:(NSString *)aCallbackId;
+ (void)callbackJSOnMainThread:(ZKWebView*)aWebview callbackId:(NSString *)aCallbackId;


+ (void)callbackJS:(ZKWebView*)aWebview callbackId:(NSString *)aCallbackId jsonString:(NSString *)aJsonString;
+ (void)callbackJSOnMainThread:(ZKWebView*)aWebview callbackId:(NSString *)aCallbackId jsonString:(NSString *)aJsonString;

+ (void)callbackJS:(ZKWebView*)aWebview callbackId:(NSString *)aCallbackId string:(NSString *)aString;
+ (void)callbackJS:(ZKWebView*)aWebview callbackId:(NSString *)aCallbackId unquotedString:(NSString *)aUnquotedString;

@end

NS_ASSUME_NONNULL_END
