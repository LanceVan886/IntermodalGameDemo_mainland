创发游戏安卓sdk接入文档，版本1.3.0。

## 一、开发环境要求
在开始运行工程之前，请您准备以下开发环境：

- Android SDK API 等级 21 或以上。
- Android 系统 5.0 或以上版本的移动设备。


## 二、导入SDK到项目中

**1.导入SDK**
- 克隆或者直接下载[Demo仓库源码](https://github.com/CFGameTech/IntermodalGameDemo)
- 找到 `Android/app/libs/cfgamelib.aar` 文件；
- 将该aar文件拷贝到工程的app/libs目录下；
- 在 app/build.gradle 中，添加引用 aar 包的代码:
```java
dependencies {
    api fileTree(include: ['*.jar', '*.aar'], dir: 'libs')
}
```
**2.配置App权限**
在 AndroidManifest.xml 中配置 App 的权限，LUKSDK 需要以下权限：
```
<uses-permission android:name="android.permission.INTERNET"/>
```

**3.设置混淆规则**
在 proguard-rules.pro 文件，将 LUKSDK 相关类加入不混淆名单：
```
-keep class com.cftech.** { *; }
```

## 三、接入指引

### 1. 初始化SDK（必接）
初始化接口建议在`Application.onCreate()`中进行调用。
> 说明：初始化接口并不会发起网络请求或申请权限，无需担心合规问题。
{.is-success}

**1）接口说明**
```java
/**
 * application: Application
 * appId: LUKSDK提供的appId
 * language: 游戏内使用的语言
 */
public static void initSDK(Application application, int appId, String language)
```  

**2）参数说明**

| 参数名称        | 字段含义          | 补充说明       | 数据类型     |
| :---           | :---            | :---          |  :---         |
| application    | 安卓Application  | 无  |  Application     |
| appId          | 渠道ID           | 渠道号，您可向LUKSDK对接人员获取该ID     |    数字     |
| language       | 游戏语言         | 游戏内语言类型，您可向LUKSDK对接人员获取期望语种对应的值  |  字符串     |


**3）调用参考**
```
CFGameSDK.initSDK(getApplication(), 10010,  "en");
```

### 2.设置用户信息接口（必接）
即用户登录LUKSDK接口，调用该接口获取用户token用于进入游戏等操作。
> 该接口需在初始化接口之后调用，该接口调用后会获取用户token，可参考[数据流说明](https://wiki.luk.live/home)了解`code`和`token`生成逻辑。
{.is-warning}

**1）接口说明**

```java
/**
 * @param userId: 接入方的用户id
 * @param userCode: 接入方的用户code，用于LUKSDK向接入方校验用户的合法性
 */
public static void setUserInfo(String userId, String userCode)
``` 

**2）参数说明**

| 参数名称        | 字段含义    | 补充说明       | 数据类型     |
| :---           | :---       | :---          |  :---         |
| userId         | 用户 ID     | 即用户名，注意 LUKSDK 不支持同一个 userId 在两台不同的设备上同时进入游戏，否则会相互干扰。  |  字符串     |
| userCode       | 用户code    | 由接入方服务端生成，用于LUKSDK向接入方校验用户的合法性    |    字符串     |



**3）调用参考**
```
CFGameSDK.setUserInfo("9005600", "eJyrVareCeYrSy1SslI");
```

### 3. 刷新游戏里的用户信息接口
游戏进行中时，如果用户的信息（如名字、头像、资产等）发生变更，接入方可通过调用此接口更新游戏中的用户信息。
**1）接口说明**

```java
public void refreshUserInfo()
``` 

**2）参数说明**

*无*


**3）调用参考**
```
CFGameSDK.refreshUserInfo();
```

### 4. 设置CFGame业务回调接口（必接）
该接口用于为游戏提供游戏所需的必要数据，进入游戏时LUKSDK会回调相关接口获取数据。

**1）接口说明**
```java
/**
 * @param logger: ICFBizCallback
 */
public static void setBizCallback(ICFBizCallback callback)

public interface ICFBizCallback {
        void onOpenChargePage();
        String onGetCurrentRoomId();
        boolean onIsRoomOwner();
        Rect onWindowSafeArea();
}
``` 

**2）参数说明**

| 回调接口名称          | 说明                             | 
| :---                | :---                             | 
| onOpenChargePage    | 从游戏内拉起平台方的充值页面         | 
| onGetCurrentRoomId  | 获取当前房间的房间ID                | 
| onIsRoomOwner       | 当前用户是否为游戏房的房主，房主拥有游戏设置、开始游戏等权限，可有多个房主   | 
| onWindowSafeArea    | 游戏的安全区域,Rect的值如图标柱  <img src="/draw.png" width="100"/>  | 


**3）调用参考**

```java
CFGameSDK.setBizCallback(new CFGameSDK.ICFBizCallback() {
    @Override
    public void onOpenChargePage() {
        // 拉起充值页面
    }

    @Override
    public String onGetCurrentRoomId() {
        // 返回当前的房间id
        return RoomId;
    }

    @Override
    public boolean onIsRoomOwner() {
        // 返回是否游戏房房主，同一游戏房内可有多名房主
        return false;
    }

    @Override
    public Rect onWindowSafeArea() {
        // CFGWebView的padding，如果返回空则使用游戏默认值
        return new Rect(left, top, right, bottom);
    }
});
``` 



### 5. 拉起游戏列表弹窗
通过该接口可拉起一个游戏列表弹窗，其中包含接入方已获得授权的所有游戏。点击其中游戏，可直接进入游戏界面。接入方`可根据需要调用` 此接口。

> 该接口需在[设置用户信息接口](###2.设置用户信息接口)后调用。
{.is-warning}

**1）接口说明**

```java
/**
 * @param activity
 */
public static void showGameListDialog(Activity activity)
``` 

**2）参数说明**

| 参数名称        | 字段含义        | 补充说明       | 数据类型     |
| :---           | :---           | :---          |  :---         |
| activity       | 安卓Activity   |  显示该弹窗的Activity  |  Activity      |




**3）调用参考**
```
CFGameSDK.showGameListDialog(this);
```




### 6. 获取游戏列表
通过该接口获得接入方已获得授权的所有游戏列表数据

> 该接口需在[设置用户信息接口](###2.设置用户信息接口)后调用。
{.is-warning}


**1）接口说明**

```java
/**
 * @param callback: ICFGameListCallback
 */
public static void getGameList(ICFGameListCallback callback)

public interface ICFGameListCallback {
    public void onSuccess(List<CFGameList.GameInfo> gameList);
    public void onError(int code, String errorMsg);
}
```  
> ICFGameListCallback的回调方法在主线程被回调。
{.is-warning}

**2）CFGameList.GameInfo参数说明**

| 参数名称        | 字段含义        | 补充说明       | 数据类型     |
| :---           | :---           | :---          |  :---         |
| g_id           | 游戏id         |  无  |  数字      |
| g_name         | 游戏名称        |  无  |  字符串      |
| g_icon         | 游戏icon       |  无  |  字符串      |
| g_url          | 游戏地址        |  无  |  字符串      |




**3）调用参考**

```java
CFGameSDK.getGameList(new ICFGameListCallback() {
            @Override
            public void onSuccess(List<CFGameList.GameInfo> gameList) {
                adapter.setData(gameList);
            }

            @Override
            public void onError(int code, String errorMsg) {
                CFL.error(TAG, String.format(Locale.getDefault(), "getGameList error: code=%d, msg=%s", code, errorMsg));
            }
});
``` 


### 7. 加载半屏游戏
接入方可通过该接口拉起一个如下图所示半屏的游戏页面。
<img src="/domino_half.jpg" width="200"/>

**1）接口说明**

```java
public static void startHalfWindowGame(Activity activity, int gameId, String url)
```  


**2）参数说明**

| 参数名称        | 字段含义        | 补充说明            | 数据类型     |
| :---           | :---           | :---              |  :---         |
| activity       | 安卓Activity   |  无                |  Activity      |
| gameId         | 游戏Id         |  通过[获取游戏列表](###5.获取游戏列表)接口获取 |  数字      |
| url            | 游戏url        |  通过[获取游戏列表](###5.获取游戏列表)接口获取  |  字符串      |




**3）调用参考**

```java
CFGameSDK.startHalfWindowGame(ownerAct, gameInfo.g_id, gameInfo.g_url);
```   

### 8. 加载全屏游戏
接入方可通过该接口拉起一个如下图所示全屏的游戏页面。
<img src="/domino_full.jpg" width="200"/>

**1）接口说明**

```java
public static void startFullWindowGame(Activity activity, int gameId, String url)
```  


**2）参数说明**

| 参数名称        | 字段含义        | 补充说明            | 数据类型     |
| :---           | :---           | :---              |  :---         |
| activity       | 安卓Activity   |  无                |  Activity      |
| gameId         | 游戏Id         |  通过[获取游戏列表](###5.获取游戏列表)接口获取 |  数字      |
| url            | 游戏url        |  通过[获取游戏列表](###5.获取游戏列表)接口获取  |  字符串      |




**3）调用参考**

```java
CFGameSDK.startFullWindowGame(ownerAct, gameInfo.g_id, gameInfo.g_url);
```   


### 9. 设置日志回调
接入方通过该接口获得LUKSDK日志，并将其写入接入方的日志文件中，用于线上环境的问题排查。

**1）接口说明**
```kotlin
/**
 * @param logger: ICFLogger
 */
public static void setLogger(ICFLogger logger)

public interface ICFLogger {
    void onDebug(String tag, String msg);
    void onInfo(String tag, String msg);
    void onWarn(String tag, String msg);
    void onError(String tag, String msg);
}
``` 

**2）参数说明**

*无*

**3）调用参考**

```java
 CFGameSDK.setLogger(new CFGameSDK.ICFLogger() {
        @Override
        public void onDebug(String tag, String msg) {

        }

        @Override
        public void onInfo(String tag, String msg) {

        }

        @Override
        public void onWarn(String tag, String msg) {

        }

        @Override
        public void onError(String tag, String msg) {

        }
});
``` 



### 10. 释放sdk
该接口将释放LUKSDK的所有资源。

**1）接口说明**
```java
public static void releaseSDK()
```

**2）参数说明**

*无*

**3）调用参考**

```java
CFGameSDK.releaseSDK();
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
2. 接入方将SDK内提供的`CFGWebView.java`添加到自己的视图内，并调用其`loadGame`接口
```java
cfgWebView.loadGame(gameId, gameUrl);
```



## 五、常见问题
### 1. Flutter项目可以接入吗
可以，参考[Flutter相关文档](https://docs.flutter.cn/platform-integration/android/platform-views)




