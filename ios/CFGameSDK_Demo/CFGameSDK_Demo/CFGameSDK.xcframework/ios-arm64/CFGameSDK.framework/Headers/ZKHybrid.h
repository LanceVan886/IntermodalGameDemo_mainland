//
//  ZKHybrid.h
//  hybird
//
//  Created by kerry on 17/3/3.
//  Copyright © 2017年 kerry. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CFGameSDK/ZKConfig.h>
#import <CFGameSDK/ZKURI.h>
#import <CFGameSDK/ZKWebView.h>

@interface ZKHybrid : NSObject

@property (strong, nonatomic) UINavigationController *navigationController;
+ (ZKHybrid*) instance;

+(void) run:(NSString*)appid zipPath:(NSString*)zipPath block:(void(^)(ZKConfig* aConfig))aBlock;
+(void) run:(NSString*)appid block:(void(^)(ZKConfig* aConfig))aBlock;
+(void) runAsset:(NSString*)appid block:(void(^)(ZKConfig* aConfig))aBlock;
+(void) runDebug:(NSString*)appid block:(void(^)(ZKConfig* aConfig))aBlock;
-(void) run:(NSString*)appid zipPath:(NSString*)zipPath block:(void(^)(ZKConfig* aConfig)) aBlock;
-(void) run:(NSString*)appid block:(void(^)(ZKConfig* aConfig))aBlock;
-(void) runAsset:(NSString*)appid block:(void(^)(ZKConfig* aConfig))aBlock;
-(void) runDebug:(NSString*)appid block:(void(^)(ZKConfig* aConfig))aBlock;



+(void) dispatcher:(ZKConfig*)aConfig webView:(ZKWebView*)aWebView;
+(void) dispatcherPath:(NSString*)aPath webView:(ZKWebView*)aWebView;
+(void) dispatcherDebug:(ZKConfig*)aConfig webView:(ZKWebView*)aWebView;
+(void) dispatcherDebugPath:(NSString*)aPath webView:(ZKWebView*)aWebView;
+(void) dispatcherUrl:(NSString*)aUrl webView:(ZKWebView*)aWebView;
+(void) dispatcherUri:(ZKURI*)aUrl webView:(ZKWebView*)aWebView;
+(void) dispatcherHttp:(NSString*)aUrl webView:(ZKWebView*)aWebView;
+(void) dispatcherScheme:(NSString*)aUrl webView:(ZKWebView*)aWebView;


/**
 *  跳转界面
 */
+ (void)push:(NSDictionary *)params;
@end
