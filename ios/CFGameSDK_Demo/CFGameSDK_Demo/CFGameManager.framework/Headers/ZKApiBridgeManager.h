//
//  ZKApiBridgeManager.h
//
//

#import <Foundation/Foundation.h>
#import "ZKClass.h"
#import "ZKWebView.h"
#import "ZKArgList.h"

@interface ZKApiBridgeManager : NSObject


+(void)testJSBrige:(ZKWebView*)aWebView argList:(ZKArgList*)args;
+(void)commonApi:(ZKWebView*)aWebView argList:(ZKArgList*)args;

@end
