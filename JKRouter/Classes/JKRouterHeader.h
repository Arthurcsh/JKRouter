//
//  JKRouterHeader.h
//  JKRouter
//
//  Created by JackLee on 2017/12/11.
//

#ifndef JKRouterHeader_h
#define JKRouterHeader_h

#ifdef DEBUG
#define JKRouterLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#define JKRouterLog(...)
#endif

static NSString * const JKRouterErrorDomain = @"JKRouterError";

typedef NS_ENUM(NSInteger,RouterTransformVCStyle){
    RouterTransformVCStyleDefault =-1, ///< 不指定转场方式，使用自带的转场方式
    RouterTransformVCStylePush,        ///< push方式转场
    RouterTransformVCStylePresent,     ///< present方式转场
    RouterTransformVCStyleOther        ///< 用户自定义方式转场
};///< ViewController的转场方式

typedef NS_ENUM(NSInteger,RouterCreateStyle) {
    RouterCreateStyleNew,               ///< 默认创建方式，创建一个新的ViewController对象
    RouterCreateStyleReplace,           ///< 创建一个新的ViewController对象，然后替换navigationController当前的viewController
    RouterCreateStyleRefresh,           ///<  当前的viewController就是目标viewController就不创建，而是执行相关的刷新操作。如果当前的viewController不是目标viewController就执行创建操作
    RouterCreateStyleNewWithNaVC        ///< 用于present转场时目标present的目标是VC也有导航栏
    
};///< ViewController的创建方式

typedef NS_ENUM(NSInteger,JKRouterError) {
  JKRouterErrorClassNameIsNil = 10000,          ///< className is nil
  JKRouterErrorClassNil,                        ///< class is nil
  JKRouterErrorURLIsNil,                        ///< url is nil
  JKRouterErrorSandBoxPathIsNil,                ///< sandboxPath is nil
  JKRouterErrorSystemUnSupportURL,              ///< system unsupport this url
  JKRouterErrorSystemUnSupportURLScheme,        ///< JKRouter unsupport this scheme
  JKRouterErrorUnSupportAction,                 ///< unsupport this action
  JKRouterErrorNORightToAccess,                 ///< no right to access
  JKRouterErrorUnSupportTransform,              ///< unsupport this transform
  JKRouterErrorUnSupportSwitchTabBar,           ///< unsupport switch tabbar
  JKRouterErrorBlackNameURL,                    ///< url is in blackName list
  JKRouterErrorUnSupportPushTransform,          ///< unsupport push transform
  JKRouterErrorUnSupportReplaceTransform,       ///< unsupport replace transform
  JKRouterErrorUnSupportPopAtcion,              ///< unsupport pop action
  JKRouterErrorUnSupportRouterClass,            ///< unsuport class in JKRouter
  JKRouterErrorNoVCInRouter,                    ///< the vc is not contained in Router

};



@protocol JKRouterDelegate <NSObject>

@optional
/**
 通过工厂方法初始化viewController
 
 @param dic 工厂方法需要的参数
 @return 初始化的viewController
 */
+ (UIViewController *)jkRouterFactoryViewControllerWithJSON:(NSDictionary *)dic;

@end

#endif /* JKRouterHeader_h */
