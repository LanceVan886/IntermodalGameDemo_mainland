//
//  ZKUtilURI.h
//

#import <Foundation/Foundation.h>

@interface ZKUtilURI : NSObject

/**
 * TODO refactor this algorithm, it's a bit chunky and not so readable
 *
 * @param aPath
 * @return
 */
+ (NSString*) removeDotSegments:(NSString*)aPath;

@end
