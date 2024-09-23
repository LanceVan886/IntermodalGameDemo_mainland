创发游戏iOS SDK接入文档，版本1.3.6

## 一、开发环境要求
在开始运行工程之前，请您准备以下开发环境：

- Xcode 15.0 或以上。
- iPhone 系统版本13.0 或以上版本的移动设备。


## 二、导入SDK到项目中

**1.导入SDK**
- 克隆或者直接下载[Demo仓库源码](https://github.com/CFGameTech/IntermodalGameDemo)
- 找到 `iOS/app/libs/cfgamelib.framework` 文件；
- 将该framework文件拷贝到工程的app目录下；
- 在 Project -> build setting 中，添加引用 framework 包，并设置为 Embed & Sign 方式引入
- 将Demo工程中- Project - 下的 Resource 文件夹拖入主工程中

## 三、接入指引

### 1. 初始化SDK（必接）
初始化接口建议在`Appdelegate 的 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions`中进行调用。
> 说明：初始化接口并不会发起网络请求或申请权限，无需担心合规问题。

**1）接口说明**
```oc
/**
 * application: UIApplication
 * appId: CFGame提供的appId
 * language: 游戏内使用的语言
 * isProduct: 是否生产环境
 */
+(void)setUpSDKWithApplication:(UIApplication *)app appId:(NSInteger)appId language:(NSString *)language isProduct:(BOOL)isProduct;
```  

**2）参数说明**

| 参数名称        | 字段含义          | 补充说明       | 数据类型     |
| :---           |:--------------| :---          |  :---         |
| application    | UIApplication | 无  |  UIApplication     |
| appId          | 渠道ID          | 渠道号，您可向CFGame SDK对接人员获取该ID     |    数字     |
| language       | 游戏语言          | 游戏内语言类型，您可向CFGame SDK对接人员获取期望语种对应的值  |  字符串     |


**3）调用参考**
```
[CFGameSDK setUpSDKWithApplication:UIApplication.sharedApplication appId:10010 language:@"en" isProduct:TRUE];

```

### 2.设置用户信息接口（必接）
即用户登录CFGame SDK接口，调用该接口获取用户token用于进入游戏等操作。
> 该接口需在初始化接口之后调用，该接口调用后会获取用户token，可参考[数据流说明](https://wiki.luk.live/home)了解`code`和`token`生成逻辑。
{.is-warning}

**1）接口说明**

```oc
/**
 * @param userId: 接入方的用户id
 * @param userCode: 接入方的用户code，用于CFGame向接入方校验用户的合法性
 * @param loginCallBack: SDK登录回调
 */
+ (void)setUserInfo:(NSString *)userId code:(NSString *)userCode loginCallBack:(id<CFGameSDKLoginDelegate>)loginCallBack;



@protocol CFGameSDKLoginDelegate <NSObject>
@required

/**
 *
 * 用户登录成功回调
 */
- (void)onLoginSuccess;

/**
 *
 * 用户登录失败回调
 */
- (void)onLoginFailCode:(int)code message:(NSString *)msg;
/**
 *
 * token 更新后回调，接入方通常无需关注此接口
 */
- (void)onRefreshToken:(NSString *)token;

@end

``` 



**2）参数说明**

| 参数名称        | 字段含义    | 补充说明       | 数据类型     |
| :---           | :---       | :---          |  :---         |
| userId         | 用户 ID     | 即用户名，注意 CFGame 不支持同一个 userId 在两台不同的设备上同时进入游戏，否则会相互干扰。  |  字符串     |
| userCode       | 用户code    | 由接入方服务端生成，用于CFGame向接入方校验用户的合法性    |    字符串     |
| loginCallBack  | SDK登录回调  | 用于通知接入方 SDK 登录及token刷新情况                |  id<CFGameSDKLoginDelegate>|



**3）调用参考**
```
    [CFGameSDK setUserInfo:@"9005600".text code:@"eJyrVareCeYrSy1SslI" loginCallBack:self];

```

### 3. 刷新游戏里的用户信息接口
游戏进行中时，如果用户的信息（如名字、头像、资产等）发生变更，接入方可通过调用此接口更新游戏中的用户信息。
**1）接口说明**

```oc
+(void)refreshUserInfo;
``` 

**2）参数说明**

*无*


**3）调用参考**
```
[CFGameSDK refreshUserInfo];
```

### 4. 设置CFGame业务回调接口（必接）
该接口用于为游戏提供游戏所需的必要数据，进入游戏时CFGame SDK会回调相关接口获取数据。

**1）接口说明**
```oc
/**
 * @param logger: ICFBizCallback
 */
+(void)setBizCallback:(id<CFGameSDKDelegate>)callback;

@protocol CFGameSDKDelegate <NSObject>
@required
- (void)openChargePage;

- (NSString *)onGetCurrentRoomId;

- (BOOL)onIsRoomOwner;

- (CFGameEdgeInsets)onWindowSafeArea;

@end
``` 

**2）参数说明**

| 回调接口名称          | 说明                             | 
| :---                | :---                             | 
| onOpenChargePage    | 从游戏内拉起平台方的充值页面         | 
| onGetCurrentRoomId  | 获取当前房间的房间ID                | 
| onIsRoomOwner       | 当前用户是否为游戏房的房主，房主拥有游戏设置、开始游戏等权限，可有多个房主   | 
| onWindowSafeArea    | 游戏的安全区域,Rect的值如图标柱  <img src="/draw.png" width="100"/>  | 


**3）调用参考**

```oc

   [CFGameSDK setBizCallback:self];


    - (void)openChargePage {
        // 拉起充值页面
    }

    - (NSString *)onGetCurrentRoomId {
        // 返回当前的房间id
         return RoomId;
    }

    - (BOOL)onIsRoomOwner {
         // 返回是否游戏房房主，同一游戏房内可有多名房主
        return false;
    }

    - (CFGameEdgeInsets)onWindowSafeArea {
        // CFGWebView的padding，如果返回空则使用游戏默认值
        //  minScaleLimit 为最小缩放比例
            CFGameEdgeInsets insets;
            insets.top = self.topPaddingTF.text.floatValue;
            insets.left = self.leftPaddingTF.text.floatValue;
            insets.bottom = self.bottomPaddingTF.text.floatValue;
            insets.right = self.rightPaddingTF.text.floatValue;
            insets.minScaleLimit = self.scalePaddingTF.text.floatValue;
            return insets;
    }

       
``` 



### 5. 拉起游戏列表弹窗
通过该接口可拉起一个游戏列表弹窗，其中包含接入方已获得授权的所有游戏。点击其中游戏，可直接进入游戏界面。接入方`可根据需要调用` 此接口。

> 该接口需在[设置用户信息接口](###2.设置用户信息接口)后调用。
{.is-warning}

**1）接口说明**

```oc

+(void)showGameList;
``` 

**2）参数说明**
无




**3）调用参考**
```
    [CFGameSDK showGameList];
```




### 6. 获取游戏列表
通过该接口获得接入方已获得授权的所有游戏列表数据

> 该接口需在[设置用户信息接口](###2.设置用户信息接口)后调用。
{.is-warning}


**1）接口说明**

```oc

     typedef void(^GetGameListSuccessBlk)(NSArray<CFGameModel *> *gameList);
     typedef void(^GetGameListFailureBlk)(int code ,NSString *msg);
     
     +(void)getGameListWithSuccess:(GetGameListSuccessBlk)successBlk failure:(GetGameListFailureBlk)failBlk;

```  
> ICFGameListCallback的回调方法在主线程被回调。
{.is-warning}

**2）CFGameList.GameInfo参数说明**

| 参数名称        | 字段含义        | 补充说明       | 数据类型     |
| :---           | :---           | :---          |  :---         |
| g_id           | 游戏id         |  无  |  int      |
| g_name         | 游戏名称        |  无  |  NSString      |
| g_icon         | 游戏icon       |  无  |  NSString      |
| g_url          | 游戏地址        |  无  |  NSString      |




**3）调用参考**

```oc
    [CFGameSDK getGameListWithSuccess:successBlk failure:failBlk];
``` 


### 7. 加载半屏游戏
接入方可通过该接口拉起一个如下图所示半屏的游戏页面。
<img src="/domino_half.jpg" width="200"/>

**1）接口说明**

```oc
-(void)loadHalfWindowGame:(NSString *)gameId url:(NSString *)url{
```  


**2）参数说明**

| 参数名称        | 字段含义        | 补充说明            | 数据类型     |
| :---           | :---           | :---              |:---------|
| gameId         | 游戏Id         |  通过[获取游戏列表](###5.获取游戏列表)接口获取 | NSString |
| url            | 游戏url        |  通过[获取游戏列表](###5.获取游戏列表)接口获取  | NSString      |




**3）调用参考**

```oc
    [CFGameSDK loadHalfWindowGame:gameInfo.g_id url: gameInfo.g_url];

```   

### 8. 加载全屏游戏
接入方可通过该接口拉起一个如下图所示全屏的游戏页面。
<img src="/domino_full.jpg" width="200"/>

**1）接口说明**

```oc
+(void)loadFullWindowGame:(NSString *)gameId url:(NSString *)url;
```  


**2）参数说明**

| 参数名称        | 字段含义        | 补充说明            | 数据类型     |
| :---           | :---           | :---              |  :---         |
| activity       | 安卓Activity   |  无                |  Activity      |
| gameId         | 游戏Id         |  通过[获取游戏列表](###5.获取游戏列表)接口获取 |  数字      |
| url            | 游戏url        |  通过[获取游戏列表](###5.获取游戏列表)接口获取  |  字符串      |




**3）调用参考**

```oc
    [CFGameSDK loadFullWindowGame:gameInfo.g_id url: gameInfo.g_url];
```   


### 9. 设置日志回调
接入方通过该接口获得CFGame SDK日志，并将其写入接入方的日志文件中，用于线上环境的问题排查。

**1）接口说明**
```oc
 + (void)cfGameSDKLog:(void(^)(NSString *logMsg))handler;

``` 

**2）参数说明**
  sdk日志打印接口
  logMsg:日志信息

**3）调用参考**

```oc
    [CFGameSDK cfGameSDKLog:^(NSString * _Nonnull logMsg) {
        
        NSLog(@"log:%@",logMsg);
    }];
``` 



### 10. 释放sdk
该接口将释放CFGame SDK的所有资源。

**1）接口说明**
```oc
+(void)releaseSDK;
```

**2）参数说明**

*无*

**3）调用参考**

```oc
 [CFGameSDK releaseSDK];

```

### 11. 透传参数上报
接入方通过此接口上报透传参数（如有的话），最后会以服务器的方式传回给接入方
**1）接口说明**
```oc
	+(void)sentExtToGame:(NSString *)extString;
```
**2）参数说明**
	extString : 透传参数 (传字符串类型，内容由平台自定义)
**3）调用参考**
```oc
[CFGameSDK sentExtToGame:@"Good"];
```


### 12. 开始游戏
调用此接口，游戏会立马开始
**1）接口说明**
```oc
	+(void)gameStart;
```
**2）参数说明**
无
**3）调用参考**
```oc
[CFGameSDK gameStart];
```

### 13. 踢人
调用此接口，房主可以把普通玩家踢出房间
**1）接口说明**
```oc
	+(void)playerRemoveWithUid:(NSString *)uid;
```
**2）参数说明**
	uid : 被踢玩家的用户id
**3）调用参考**
```oc
[CFGameSDK playerRemoveWithUid:@"10086"];
```

### 14. 打开/关闭 背景音乐
调用此接口，可以控制游戏打开/关闭背景音乐
**1）接口说明**
```oc
	+(void)gameBackgroundMusicSet:(BOOL *)mode;
```
**2）参数说明**
 mode ： YES 打开 NO 关闭
**3）调用参考**
```oc
[CFGameSDK gameBackgroundMusicSet:YES];
```


### 15. 打开/关闭 游戏音效
调用此接口，可以控制游戏打开/关闭游戏音效
**1）接口说明**
```oc
	+(void)gameSoundSet:(BOOL *)mode;
```
**2）参数说明**
 mode ： YES 打开 NO 关闭
**3）调用参考**
```oc
[CFGameSDK gameSoundSet:YES];
```


## 四、加载游戏的方式
### 方案一：傻瓜式托管方案
接入方可直接调用[拉起游戏列表弹窗](#起游戏列表弹窗)接口，拉起SDK内部的游戏列表弹窗，然后用户点击游戏自动进入相应的全屏游戏或半屏游戏。
| 游戏列表弹窗 | 进入全屏游戏 | 进入半屏游戏 |
|------------|------------|------------|
| <img src="/domino_full.jpg" width="250"> | <img src="/domino_full.jpg" width="250"/> |<img src="/domino_half.jpg" width="250"/>



### 方案二：自定义游戏列表方案
1. 接入方调用[获取游戏列表]()接口拿到游戏列表后，自定义游戏列表展示逻辑
2. 用户点击游戏后，调用[加载半屏游戏]()或[加载全屏游戏]()拉起游戏
> [加载半屏游戏]()和[加载全屏游戏]()会将游戏视图加载到最上层
{.is-warning}



### 方案三：完全自定义方案
1. 接入方调用[获取游戏列表]()接口拿到游戏列表后，自定义游戏列表展示逻辑
2. 接入方将SDK内提供的`CFGameWebViewController.view`添加到自己的视图内，并调用其`loadGame`接口
```oc
CFGameWebViewController *gameVc = [CFGameWebViewController new];
gameVc.g_id = gameId;
gameVc.webUrl = gameId;
[self addChildViewController:gameVc];
[self.view addSubview:vc.view];

```



## 五、常见问题
### 1. Flutter项目可以接入吗
可以，参考[Flutter相关文档](https://docs.flutter.cn/platform-integration/ios/platform-views) 或 根据 SDK接口跟主工程中 js文件自行接入WebView




