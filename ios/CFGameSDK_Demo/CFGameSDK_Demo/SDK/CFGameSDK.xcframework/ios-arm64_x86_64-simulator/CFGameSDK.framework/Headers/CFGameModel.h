//
//  CFGameModel.h
//  Tofee
//
//  Created by mac on 2023/7/9.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CFGameModel : NSObject

// 游戏id
@property (nonatomic,assign) NSInteger g_id;
// 游戏名称
@property (nonatomic,copy) NSString *g_name;
// 游戏icon
@property (nonatomic,copy) NSString *g_icon;
// 游戏地址
@property (nonatomic,copy) NSString *g_url;

@end


@interface CFGameAudioInfo : NSObject

// 音频路径
@property (nonatomic,copy) NSString *url;
// 音频名称
@property (nonatomic,copy) NSString *name;
// 音频格式
@property (nonatomic,copy) NSString *type;



@end




@interface CFGameInitSDKModel : NSObject

//  当前application
@property (nonatomic, nonnull) UIApplication *app;
//  创发提供的appId
@property (nonatomic,copy,nonnull) NSString *appId;
//  游戏语言
@property (nonatomic,copy,nonnull) NSString *language;
//  发布地区
@property (nonatomic,copy,nonnull) NSString *area;

@property (nonatomic,assign) BOOL isProduct;

@property (nonatomic,assign) BOOL isGameSoundPlay;
;


@end



NS_ASSUME_NONNULL_END
