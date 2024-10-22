//
//  CFGameWebviewController.h
//  Tofee
//
//  Created by mac on 2023/7/9.
//

#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface CFGameWebviewController : UIViewController 

@property (copy, nonatomic) NSString *webUrl;

@property (nonatomic,assign) int g_id;

@property (assign,nonatomic) BOOL isHalfScreen;


@end

NS_ASSUME_NONNULL_END
