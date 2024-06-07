//
//  ZKApiBridgeManager.h
//
//

#import <Foundation/Foundation.h>
#import <CFGameSDK/ZKClass.h>
#import <CFGameSDK/ZKWebView.h>
#import <CFGameSDK/ZKArgList.h>

@interface ZKApiBridgeManager : NSObject


+(void)testJSBrige:(ZKWebView*)aWebView argList:(ZKArgList*)args;
+(void)commonApi:(ZKWebView*)aWebView argList:(ZKArgList*)args;

@end
