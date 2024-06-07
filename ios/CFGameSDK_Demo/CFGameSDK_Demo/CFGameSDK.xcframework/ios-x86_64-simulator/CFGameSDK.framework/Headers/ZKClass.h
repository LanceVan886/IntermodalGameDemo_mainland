//
//  ZKClass.h
//
//

#import <Foundation/Foundation.h>
#import <CFGameSDK/ZKArgList.h>
#import <CFGameSDK/ZKMethod.h>

@interface ZKClass : NSObject

+ (ZKClass *)newClass:(Class)aClass withJSObjName:(NSString *)aJSClzName;

- (Class)getNavClass;
- (NSString *)getJSClz;

- (void)loadMethods;

- (void)addJSMethod:(NSString *)aJSMethodName args:(ZKArgList *)aArgList;
- (NSArray*)getMethods:(NSString *)aJSMethodName;

@end
