//
//  ZKRegister.h
//

#import <Foundation/Foundation.h>
#import <CFGameSDK/ZKClass.h>
#import <CFGameSDK/ZKJSObject.h>

//NOTE:4.6.2 by sawyer
typedef void (^DYJSBridgeCallback)(NSDictionary * responseDictionary);
typedef void (^DYJSCallOCHandler)(ZKArgList* argList,DYJSBridgeCallback responseCallback);

@interface ZKRegister : NSObject

+ (ZKClass*)registObject:(ZKJSObject*)aObject;
+ (ZKClass*)removeObject:(ZKJSObject*)aObject;
+ (ZKClass*)registClass:(ZKClass*)aClass;
+ (ZKClass*)registClass:(Class)aClass withJSObjName:(NSString*)aJSObjName;
+ (ZKClass*)removeClass:(NSString*)aJSObjName;
+ (ZKClass*)getClass:(NSString*)aJSObjName;
+ (ZKJSObject*)getJSObject:(NSString*)aJSObjName;

+ (void)registerHandler:(NSString *)handlerName handler:(DYJSCallOCHandler)handler;
+ (void)removeHandler:(NSString *)handlerName;
+ (NSDictionary <NSString *,DYJSCallOCHandler>*)getHandlers;

@end
