//
//  CFUserModel.h
//  Tofee
//
//  Created by mac on 2023/7/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CFUserModel : NSObject

// 渠道用户id
@property (nonatomic,copy) NSString *c_uid;

@property (nonatomic,copy) NSString *userCode;

// 用户token
@property (nonatomic,copy) NSString *token;

// 渠道用户昵称
@property (nonatomic,copy) NSString *c_username;


// 渠道用户头像
@property (nonatomic,copy) NSString *avatar;

// 渠道用户金币
@property (nonatomic,assign) int64_t coins;

@end

NS_ASSUME_NONNULL_END
