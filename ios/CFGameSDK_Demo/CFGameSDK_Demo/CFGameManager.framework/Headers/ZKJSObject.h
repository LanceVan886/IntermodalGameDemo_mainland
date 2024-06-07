//
//  ZKJSObject.h
//

#import <Foundation/Foundation.h>

@protocol ZKJSObject <NSObject>

- (NSString*)getJSObjectName;

@end

@interface ZKJSObject : NSObject <ZKJSObject>


@end
