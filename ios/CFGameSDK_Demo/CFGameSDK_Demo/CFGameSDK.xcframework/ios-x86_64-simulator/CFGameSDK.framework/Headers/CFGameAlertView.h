//
//  CFGameAlertView.h
//  Tofee
//
//  Created by mac on 2023/7/9.
//

#import <UIKit/UIKit.h>
@class CFGameModel;


typedef void(^SingleGameClickBlk)(CFGameModel *);

NS_ASSUME_NONNULL_BEGIN

@interface CFGameAlertView : UIView

+(instancetype)gameListAlertViewClickBlk:(SingleGameClickBlk)clickBlock;

-(void)show;

@end

NS_ASSUME_NONNULL_END
