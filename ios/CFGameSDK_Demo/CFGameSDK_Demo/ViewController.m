//
//  ViewController.m
//  CFGameSDK_Demo
//
//  Created by apple developer on 2024/6/5.
//

#import "ViewController.h"
#import <CFGameSDK/CFGameSDK.h>

@interface ViewController () <CFGameSDKDelegate,CFGameSDKRTCDelegate,CFGameSDKLoginDelegate,CFGameLifeCycleDelegate>
@property (weak, nonatomic) IBOutlet UITextField *languageTF;
@property (weak, nonatomic) IBOutlet UITextField *channelTF;
@property (weak, nonatomic) IBOutlet UITextField *userIDTF;
@property (weak, nonatomic) IBOutlet UITextField *roomIDTF;
@property (weak, nonatomic) IBOutlet UITextField *isOwnerTF;
@property (weak, nonatomic) IBOutlet UIButton *envBtn;


@property (copy,nonatomic) NSString *selectLanguage;


@property (nonatomic,assign) BOOL isProduct;


@property (weak, nonatomic) IBOutlet UITextField *topPaddingTF;
@property (weak, nonatomic) IBOutlet UITextField *leftPaddingTF;
@property (weak, nonatomic) IBOutlet UITextField *bottomPaddingTF;
@property (weak, nonatomic) IBOutlet UITextField *rightPaddingTF;
@property (weak, nonatomic) IBOutlet UITextField *scalePaddingTF;
@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [CFGameSDK cfGameSDKLog:^(NSString * _Nonnull logMsg) {
        NSLog(@"sdk log %@",logMsg);
    }];
    
}

- (IBAction)loginAction:(id)sender {
    [self.view endEditing:YES];
        
    if (self.userIDTF.text.length == 0){
        
        UIAlertController *alertVc = [UIAlertController alertControllerWithTitle:@"提示" message:@"用户id为必填项" preferredStyle:(UIAlertControllerStyleAlert)];
        UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
           }];
        [alertVc addAction:okAction];
        [self presentViewController:alertVc animated:TRUE completion:nil];
        return;
    }
    [CFGameSDK setUserInfo:self.userIDTF.text code:@"" loginCallBack:self];
    
}

- (IBAction)initAction:(id)sender {
    if (self.channelTF.text.length == 0){

        UIAlertController *alertVc = [UIAlertController alertControllerWithTitle:@"提示" message:@"渠道号为必填项" preferredStyle:(UIAlertControllerStyleAlert)];
        UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
           }];
        [alertVc addAction:okAction];
        [self presentViewController:alertVc animated:TRUE completion:nil];
        return;
    }
    
    if (self.languageTF.text.length == 0){
       
        UIAlertController *alertVc = [UIAlertController alertControllerWithTitle:@"提示" message:@"语言为必填项" preferredStyle:(UIAlertControllerStyleAlert)];
        UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
           }];
        [alertVc addAction:okAction];
        [self presentViewController:alertVc animated:TRUE completion:nil];
        return;
    }
 
    [self.view endEditing:YES];

    
    [CFGameSDK setUpSDKWithApplication:UIApplication.sharedApplication appId:self.channelTF.text language:_languageTF.text isProduct:true];
    
    [CFGameSDK setBizCallback:self];
    
    [CFGameSDK setCFGameLifecycleCallback:self];
    [CFGameSDK setRTCCallback:self];
    
}

- (IBAction)gameListAction:(id)sender {
    [self.view endEditing:YES];

    if (self.roomIDTF.text.length == 0){
       
        UIAlertController *alertVc = [UIAlertController alertControllerWithTitle:@"提示" message:@"房间id为必填项" preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
           }];
        [alertVc addAction:okAction];

        [self presentViewController:alertVc animated:TRUE completion:nil];
        return;
    }
    
   
    
    if (self.isOwnerTF.text.length == 0){
        
        UIAlertController *alertVc = [UIAlertController alertControllerWithTitle:@"提示" message:@"是否房主为必填项" preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
           }];
        [alertVc addAction:okAction];

        [self presentViewController:alertVc animated:TRUE completion:nil];
        
        return;
    }
    [CFGameSDK showGameList];
}

- (IBAction)envAction:(id)sender {
    [self.view endEditing:YES];
    
    UIAlertController *alertVc = [UIAlertController alertControllerWithTitle:@"请选择环境" message:@"" preferredStyle:UIAlertControllerStyleActionSheet];
    UIAlertAction *testAction = [UIAlertAction actionWithTitle:@"测试环境" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        
        self.isProduct = FALSE;
        [self.envBtn setTitle:@"测试环境" forState:UIControlStateNormal];
        
       }];
    UIAlertAction *productAction = [UIAlertAction actionWithTitle:@"生产环境" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        
        self.isProduct = TRUE;
        [self.envBtn setTitle:@"生产环境" forState:UIControlStateNormal];
       }];
    
    [alertVc addAction:testAction];
    [alertVc addAction:productAction];
                                  
    [self presentViewController:alertVc animated:TRUE completion:nil];
}



- (NSString *)onGetCurrentRoomId {
    return self.roomIDTF.text;
}

- (BOOL)onIsRoomOwner {
    return [self.isOwnerTF.text isEqualToString:@"1"];
}

- (CFGameEdgeInsets)onWindowSafeArea {
    CFGameEdgeInsets insets;
    insets.top = self.topPaddingTF.text.floatValue;
    insets.left = self.leftPaddingTF.text.floatValue;
    insets.bottom = self.bottomPaddingTF.text.floatValue;
    insets.right = self.rightPaddingTF.text.floatValue;
    insets.minScaleLimit = self.scalePaddingTF.text.floatValue;
    return insets;
}

- (void)openChargePage {
    
}


/**
 *
 * 用户登录成功回调
 */
- (void)onLoginSuccess{
    
    NSLog(@"CFGameSDKLoginCallBack login success");
}

/**
 *
 * 用户登录失败回调
 */
- (void)onLoginFailCode:(int)code message:(NSString *)msg{
    
    
    NSLog(@"CFGameSDKLoginCallBack login fail code = %d msg = %@",code,msg);
}
/**
 *
 * token 更新后回调，接入方通常无需关注此接口
 */
- (void)onRefreshToken:(NSString *)token{
    NSLog(@"CFGameSDKLoginCallBack onRefreshToken success");
}
/**
 *
 * 游戏加载失败
 */
- (void)onGameLoadFail{
    NSLog(@"CFViewController callback onGameLoadFail ");

}


/**
 *
 * 用户自动上麦加入游戏
 */
- (BOOL)onPreJoinGame:(NSString *)uid seatIndex:(int)seatIndex{
    NSLog(@"CFViewController callback  onPreJoinGame uid = %@ , seatIndex = %d",uid,seatIndex);
    return YES;
}


/**
 *
 * 用户准备游戏
 */
- (void)onGamePrepare:(NSString *)uid{
    NSLog(@"CFViewController callback uid = %@, gamePrepare ",uid);

}

/**
 *
 * 用户取消准备
 */
- (void)onCancelPrepare:(NSString *)uid{
    NSLog(@"CFViewController callback uid = %@, CancelPrepare ",uid);

}



/**
 *
 * 游戏结束
 */
- (void)onGameOver{
    NSLog(@"CFViewController callback game over ");
}

- (void)gameDidFinishLoad { 
    
}



- (BOOL)onCFGamePushSelfRTC:(BOOL)push{
    return YES;
}

- (BOOL)onCFGamePullOtherRTC:(NSString *)uid pull:(BOOL)pull{
    return YES;
}






@end
