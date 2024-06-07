//
//  ZKJSCallback.h
//

#import <Foundation/Foundation.h>
#import "ZKJSType.h"
#import "ZKJSExecutor.h"

@interface ZKJSCallback : ZKJSType

+ (id)create:(NSString*)aCallbackId;

- (id)initWithCallbackId:(NSString*)aCallbackId;
- (NSString*)getCallbackId;

- (void)callbackJS:(ZKWebView*)aWebview;
- (void)callbackJS:(ZKWebView*)aWebview jsonString:(NSString *)aJsonString;

@end
