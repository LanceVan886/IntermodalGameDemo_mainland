//
//  ViewController.m
//  CFGameSDK_Demo
//
//  Created by apple developer on 2024/6/5.
//

#import "ViewController.h"
#import <CFGameManager/CFGameSDK.h>

@interface ViewController ()
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
    [CFGameSDK setUserInfo:self.userIDTF.text code:@""];
    
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

    
    [CFGameSDK setUpSDKWithApplication:UIApplication.sharedApplication appId:[self.channelTF.text integerValue] language:_languageTF.text isProduct:self.isProduct];
    
    [CFGameSDK setBizCallback:self];
    ZKLogger *logger = [[ZKLogger alloc] init];
    [CFGameSDK setLogger:logger];
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


@end
