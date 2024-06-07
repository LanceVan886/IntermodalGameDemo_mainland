//
//  CFGameListItemCell.h
//  Tofee
//
//  Created by mac on 2023/7/9.
//

#import <UIKit/UIKit.h>
#import <CFGameSDK/CFGameModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface CFGameListItemCell : UICollectionViewCell

@property (nonatomic,strong) CFGameModel *model;

@end

NS_ASSUME_NONNULL_END
