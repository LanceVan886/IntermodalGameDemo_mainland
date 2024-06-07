//
//  ZKUriActionDelegate.h
//  hybird
//
//  Created by kerry on 17/3/3.
//  Copyright © 2017年 kerry. All rights reserved.
//

#ifndef ZKUriActionDelegate_h
#define ZKUriActionDelegate_h

#import <Foundation/Foundation.h>

@protocol ZKUriActionDelegate <NSObject>

/**
 * Determine whether to perform custom operations protocol,if accept return true,else return false.
 */
-(BOOL) accept:(NSString*)aHost path:(NSString*)aPath;

/**
 * if accept function return true,invokeAction can be called,you call do something here
 */
-(void) invokeAction:(NSDictionary*)aParams object:(id)aObject, ...;



@end

#endif /* ZKUriActionDelegate_h */
