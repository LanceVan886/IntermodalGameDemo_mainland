//
//  CFUserManager.h
//  Tofee
//
//  Created by mac on 2023/7/10.
//

#import <Foundation/Foundation.h>
#import "CFUserModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface CFUserManager : NSObject

+ (CFUserManager *)shareMgr;


-(CFUserModel *)getCurrentUser;

@end

NS_ASSUME_NONNULL_END
