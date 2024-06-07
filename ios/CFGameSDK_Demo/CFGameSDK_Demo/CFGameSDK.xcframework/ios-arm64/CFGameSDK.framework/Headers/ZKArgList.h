//
//  ZKArgList.h
//

#import <Foundation/Foundation.h>
#import <CFGameSDK/ZKArg.h>
#import <CFGameSDK/ZKJSCallback.h>


@interface ZKArgList : NSObject

- (BOOL)addArg:(ZKArg *)aArg;
- (BOOL)has:(NSString*)aKey;
- (id)getArgValule:(NSString*)aKey __attribute__((deprecated("use 'getObject:' in deepContent instead")));;
- (id)getObject:(NSString *)aKey;
- (NSString*)getString:(NSString*)aKey;
- (ZKJSCallback*)getCallback;
- (BOOL)getBoolean:(NSString*)aKey;
- (NSString *)toString;
- (NSInteger)count;

@end
