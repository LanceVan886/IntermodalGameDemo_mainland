//
//  ZKClassParser.h
//

#import <Foundation/Foundation.h>
#import <CFGameSDK/ZKArgList.h>

@interface ZKClassParser : NSObject

+ (ZKClassParser *)createParser:(NSDictionary *)dic;

- (NSString *)getJSClzName;
- (NSString *)getJSMethodName;
- (ZKArgList *)getArgList;

@end
