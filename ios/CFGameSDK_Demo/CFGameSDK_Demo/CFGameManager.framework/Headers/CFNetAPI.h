//
//  CFNetAPI.h
//  CFGameSDK
//
//  Created by mac on 2023/7/10.
//

#ifndef CFNetAPI_h
#define CFNetAPI_h

// 获取游戏列表
static NSString * const kNetAPI_GetGameList = @"/sdk/get_game_list";

// 获取demo token
static NSString * const kNetAPI_GetSDKToken = @"/sdk/get_token";

// 刷新token
static NSString * const kNetAPI_RefreshUserToken = @"/sdk/refresh_token";

// 进入游戏前校验
static NSString * const kNetAPI_CheckEnterGame = @"/sdk/enter_game";

#endif /* CFNetAPI_h */
