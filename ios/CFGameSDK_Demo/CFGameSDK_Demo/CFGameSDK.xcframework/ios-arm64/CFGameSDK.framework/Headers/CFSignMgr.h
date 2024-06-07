//
//  CFSignMgr.h
//  Tofee
//
//  Created by mac on 2023/7/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CFSignMgr : NSObject

+ (CFSignMgr *)shareMgr;


- (NSString *)generateSignatureWithParameters:(NSDictionary *)parameters apiKey:(NSString *)apiKey;

@end

NS_ASSUME_NONNULL_END
