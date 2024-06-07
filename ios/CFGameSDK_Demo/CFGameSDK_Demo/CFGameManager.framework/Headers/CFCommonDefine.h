//
//  CFCommonDefine.h
//  Tofee
//
//  Created by mac on 2023/7/9.
//

#ifndef CFCommonDefine_h
#define CFCommonDefine_h



#ifndef    weakify
#if __has_feature(objc_arc)

#define weakify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
autoreleasepool{} __weak __typeof__(x) __weak_##x##__ = x; \
_Pragma("clang diagnostic pop")

#else

#define weakify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
autoreleasepool{} __block __typeof__(x) __block_##x##__ = x; \
_Pragma("clang diagnostic pop")

#endif
#endif

#ifndef    strongify
#if __has_feature(objc_arc)

#define strongify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
try{} @finally{} __typeof__(x) x = __weak_##x##__; \
_Pragma("clang diagnostic pop")

#else

#define strongify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
try{} @finally{} __typeof__(x) x = __block_##x##__; \
_Pragma("clang diagnostic pop")
#endif
#endif

#define iPhoneX (((int)((kScreemHeight/kScreemWidth)*100) == 216) ? YES : NO)
//屏幕宽度高度
#define kScreemWidth [UIScreen mainScreen].bounds.size.width
#define kScreemHeight [UIScreen mainScreen].bounds.size.height


// 状态栏高度
#define STATUS_BAR_HEIGHT (iPhoneX ? 44.f : 20.f)
// 导航栏高度
#define NAVIGATION_BAR_HEIGHT (iPhoneX ? 88.f : 64.f)



#define UIUTILS_iPhoneX (((int)((kScreemHeight/kScreemWidth)*100) == 216) ? YES : NO)

// 状态栏高度
#define UIUTILS_STATUS_BAR_HEIGHT (UIUTILS_iPhoneX ? 44.f : 20.f)
// 导航栏高度
#define UIUTILS_NAVIGATION_BAR_HEIGHT (UIUTILS_iPhoneX ? 88.f : 64.f)
// tabBar高度
#define UIUTILS_TAB_BAR_HEIGHT (UIUTILS_iPhoneX ? (49.f+34.f) : 49.f)
// home indicator
#define UIUTILS_HOME_INDICATOR_HEIGHT (UIUTILS_iPhoneX ? 34.f : 0.f)


#endif /* CommonDefine_h */
