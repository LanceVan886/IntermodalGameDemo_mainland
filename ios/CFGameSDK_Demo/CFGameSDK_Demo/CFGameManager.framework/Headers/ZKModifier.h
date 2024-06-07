//
//  ZKModifier.h
//

#import <Foundation/Foundation.h>


@interface ZKModifier : NSObject

- (void)markStatic;
- (void)markPublic;
- (void)markPrivate;

- (BOOL)isEqual:(ZKModifier*)aModifier;

+ (int)methodModifiers;
- (BOOL)isStatic;
- (int)getModifiers;

@end
