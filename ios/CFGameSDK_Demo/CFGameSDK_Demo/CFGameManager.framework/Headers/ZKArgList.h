//
//  ZKArgList.h
//

#import <Foundation/Foundation.h>
#import "ZKArg.h"
#import "ZKJSCallback.h"


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
