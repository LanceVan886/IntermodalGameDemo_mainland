//
//  ZKMethod.h
//

#import <Foundation/Foundation.h>
#import <CFGameSDK/ZKArgList.h>
#import <CFGameSDK/ZKModifier.h>

@interface ZKMethod : NSObject

+ (ZKMethod *)createMethod:(SEL)aMethod modifier:(ZKModifier*)aModifier;

- (NSString *)createIdentity:(NSString *)aClzName methodName:(NSString *)aMethodName argsKeys:(NSArray *)aArgsKeys;
- (NSString *)getIdentity;
- (SEL)getNavMethod;
- (NSString*)getJSMethodName;
- (BOOL)isSameMethod:(SEL)aMethod modifier:(ZKModifier*)aModifier;

- (ZKModifier*)modifier;
- (BOOL)isStatic;

// arg list can support internal types
- (id)invoke:(id)aReceiver, ...;

@end
