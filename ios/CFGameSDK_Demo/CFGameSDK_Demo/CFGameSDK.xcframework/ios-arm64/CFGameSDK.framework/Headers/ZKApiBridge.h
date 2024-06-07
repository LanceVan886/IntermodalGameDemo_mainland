//
//  ZKApiBridge.h
//
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CFGameSDK/ZKWebView.h>
#import <CFGameSDK/ZKRegister.h>

@protocol ZKApiBridgeDelegate <ZKWebViewDelegate>

@optional
-(void) parseCustomApi:(NSURL*)aURL;

@end


@interface ZKApiBridge : NSObject <ZKWebViewDelegate>

@property(nonatomic, strong) NSString *attachApiScheme;//附加的协议主题 需要实现parseCustomApi接口


+ (id)apiBridgeWithWebView:(ZKWebView *)aWebView delegate:(id)userDelegate;

//- (void)destroy;// destroy webview

+ (void)callbackJSOnHitPageBottom:(ZKWebView*)aWebView y:(CGFloat)aY;
+ (void)callbackJSOnPageScroll:(ZKWebView*)aWebView x:(CGFloat)aX y:(CGFloat)aY width:(CGFloat)aWidth height:(CGFloat)aHeight;

+ (void)openGlobalJSLog:(BOOL)aIsOpenJSLog;
+ (void)setIsOpenJSLog:(ZKWebView*)aWebview isOpenJSLog:(BOOL)aIsOpenJSLog;

@end
