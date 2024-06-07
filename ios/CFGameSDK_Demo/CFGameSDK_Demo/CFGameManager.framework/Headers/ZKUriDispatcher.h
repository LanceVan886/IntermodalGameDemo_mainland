//
//  ZKUriDispatcher.h
//  hybird
//
//  Created by kerry on 17/3/3.
//  Copyright © 2017年 kerry. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZKUriActionDelegate.h"
#import "ZKURI.h"


@interface ZKUriDispatcher : NSObject

+(BOOL) registerAction:(NSString*)key action:(id<ZKUriActionDelegate>)aAction;
+(BOOL) unregisterAction:(NSString*)key;
+(void) dispatcher:(NSString*)aUriString;
+(void) dispatcher:(NSString*)aUriString object1:(id)aObject1;
+(void) dispatcher:(NSString*)aUriString object1:(id)aObject1 object2:(id)aObject2;
+(void) dispatcher:(NSString*)aUriString object1:(id)aObject1 object2:(id)aObject2 object3:(id)aObject3;
+(void) dispatcher:(NSString*)aUriString object1:(id)aObject1 object2:(id)aObject2 object3:(id)aObject3 object4:(id)aObject4;
+(void) dispatcher:(NSString*)aUriString object1:(id)aObject1 object2:(id)aObject2 object3:(id)aObject3 object4:(id)aObject4 object5:(id)aObject5;
+(void) dispatcher:(NSString*)aUriString object1:(id)aObject1 object2:(id)aObject2 object3:(id)aObject3 object4:(id)aObject4 object5:(id)aObject5  object6:(id)aObject6;
@end
