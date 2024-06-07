//
//  ZKWebView.h
//  hybird
//
//  Created by kerry on 17/3/1.
//  Copyright © 2017年 kerry. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol WKScriptMessageHandler;
@class ZKWebView;

@protocol ZKWebViewDelegate <NSObject>
@optional

- (void)webViewDidStartLoad:(ZKWebView*)aWebView;
- (void)webViewDidFinishLoad:(ZKWebView*)aWebView;
- (void)webView:(ZKWebView*)aWebView didFailLoadWithError:(NSError*)aError;
- (BOOL)webView:(ZKWebView*)aWebView shouldStartLoadWithRequest:(NSURLRequest*)aRequest navigationType:(WKNavigationType)aNavigationType;

//alert代理
- (void)webView:(ZKWebView *)webView runJavaScriptAlertPanelWithMessage:(NSString *)message initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(void))completionHandler;

//confirm代理
- (void)webView:(ZKWebView *)webView runJavaScriptConfirmPanelWithMessage:(NSString *)message initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(BOOL))completionHandler;

- (void)webView:(ZKWebView*)aWebView decidePolicyForNavigationAction:(WKNavigationAction*)navigationAction decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler;
@end

// automatically choose to use WKWebView
@interface ZKWebView : UIView

- (instancetype)initWithFrame:(CGRect)aFrame;

@property (nonatomic, readonly) id realWebView;

// Will agent to WKUIDelegate WKNavigationDelegate internal unrealized callback.
@property (weak, nonatomic) id<ZKWebViewDelegate> delegate;

//@property (weak, nonatomic) id<ZKWebViewProgressDelegate> progressDelegate;

//Estimate the page loaded
@property (nonatomic, readonly) double estimatedProgress;

//WKWebView interact with JS
- (void)addScriptMessageHandler:(id<WKScriptMessageHandler>)aScriptMessageHandler name:(NSString*)aName;
- (void)removeScriptMessageHandlerForName:(NSString *)aName;

- (NSInteger)countOfHistory;
- (void)gobackWithStep:(NSInteger)aStep;

@property (nonatomic, copy) void(^callBack)(id Obj);
//@property (nonatomic, readonly) NSString* originUserAgent;



#pragma mark - API
@property (nonatomic, readonly) UIScrollView* scrollView;

- (id)loadRequest:(NSURLRequest*)aRequest;
- (id)loadFileURL:(NSURL *)aURL allowingReadAccessToURL:(NSURL *)aReadAccessURL API_AVAILABLE(macosx(10.11), ios(9.0));
- (id)loadHTMLString:(NSString*)aString baseURL:(nullable NSURL*)aBaseURL;

@property (nonatomic, readonly, copy) NSString* title;
@property (nonatomic, readonly) NSURLRequest* originRequest;
@property (nonatomic, readonly) NSURLRequest* currentRequest;
@property (nonatomic, readonly) NSURL* URL;

@property (nonatomic, readonly, getter=isLoading) BOOL loading;
@property (nonatomic, readonly) BOOL canGoBack;
@property (nonatomic, readonly) BOOL canGoForward;

- (id)goBack;
- (id)goForward;
- (id)reload;
- (id)reloadFromOrigin;
- (void)stopLoading;

#pragma mark --
- (void)documentReady:(BOOL)aIsReady;
- (BOOL)isDocumentReady;
- (void)setHitPageBottomThreshold:(float)aThreshold;
- (void)setIsPageScrollOn:(BOOL)aIsPageScrollOn;

- (int)getWebViewID;
- (id)getAttach;
- (void)setAttach:(id)aAttch;

/* @abstract Evaluates the given JavaScript string.
 @param javaScriptString The JavaScript string to evaluate.
 @param completionHandler A block to invoke when script evaluation completes or fails.
 @discussion The completionHandler is passed the result of the script evaluation or an error.
 */
- (void)evaluateJavaScript:(NSString *)aJavaScriptString completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))aCompletionHandler;

// default is YES
@property (nonatomic) BOOL scalesPageToFit;

@end

NS_ASSUME_NONNULL_END
