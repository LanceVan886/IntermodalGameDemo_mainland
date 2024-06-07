//
//  ZKConfig.h
//  hybird
//
//  Created by kerry on 17/3/3.
//  Copyright © 2017年 kerry. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZKConfig : NSObject

@property (nonatomic,assign)NSString *appId;
@property (nonatomic,assign)NSString *name;
@property (nonatomic,assign)NSString *url;
@property (nonatomic,assign)long version;
@property (nonatomic,assign)int screenWidth;
@property (nonatomic,assign)int screenHeight;

@end
