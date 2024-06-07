//
//  ZKArg.h
//

#import <Foundation/Foundation.h>

@interface ZKArg : NSObject

+ (id)newArgWithObject:(id)aValue name:(NSString*)aName;

- (id)initWithObject:(id)aValue name:(NSString *)aName;
- (NSString *)getArgName;
- (id)getValue;
- (Class)getType;
- (NSString *)toString;
@end
