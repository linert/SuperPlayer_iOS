#ifdef LITEAV
#import "TXVodPlayer.h"
#import "TXLivePlayer.h"
#import "TXImageSprite.h"
#import "TXLiveBase.h"
#else
#import <TXLiteAVSDK_Player/TXLiteAVSDK.h>
#endif

#import "SuperPlayerView.h"
#import "SuperPlayerModel.h"
#import "SuperPlayerControlView.h"
#import "SuperPlayerControlViewDelegate.h"
#import "SuperPlayerWindow.h"
#import "SPDefaultControlView.h"
#import "SPWeiboControlView.h"

// player的单例
#define SuperPlayerShared                   [SuperPlayerSharedView sharedInstance]
// 屏幕的宽
#define ScreenWidth                         [[UIScreen mainScreen] bounds].size.width
// 屏幕的高
#define ScreenHeight                        [[UIScreen mainScreen] bounds].size.height
// 颜色值RGB
#define RGBA(r,g,b,a)                       [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
// 图片路径
#define SuperPlayerImage(file)              [UIImage imageNamed:[@"SuperPlayer.bundle" stringByAppendingPathComponent:file]]

#define IsIPhoneX                           SuperPlayer_iPhoneX()//(ScreenHeight >= 812 || ScreenWidth >= 812)

// 小窗单例
#define SuperPlayerWindowShared             [SuperPlayerWindow sharedInstance]

#define TintColor RGBA(252, 89, 81, 1)

#define LOG_ME NSLog(@"%s", __func__);

static inline BOOL SuperPlayer_iPhoneX() {
    static BOOL iPhoneX = NO;
    if (@available(iOS 11.0, *)) {
        iPhoneX = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0.0;
    } else {
        iPhoneX = NO;
    }
    if ([UIDevice.currentDevice.model isEqualToString: @"iPad"]) {
        iPhoneX = NO;
    }
    return iPhoneX;
}
