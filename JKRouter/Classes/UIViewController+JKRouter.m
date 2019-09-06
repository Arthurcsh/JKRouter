//
//  UIViewController+JKRouter.m
//  
//
//  Created by jack on 17/1/20.
//  Copyright © 2017年 localadmin. All rights reserved.
//

#import "UIViewController+JKRouter.h"
#import "JKRouterTool.h"
#import <objc/runtime.h>

@implementation UIViewController (JKRouter)

static char moduleIDKey;

- (NSString *)moduleID
{
    return objc_getAssociatedObject(self, &moduleIDKey);
}

- (void)setModuleID:(NSString *)moduleID
{
    objc_setAssociatedObject(self, &moduleIDKey, moduleID, OBJC_ASSOCIATION_COPY_NONATOMIC);
}


+ (instancetype)jkRouterViewController
{
    return [[[self class] alloc] init];
}



+ (instancetype)jkRouterViewControllerWithJSON:(NSDictionary *)dic
{
    JKRouterOptions *options = [JKRouterOptions optionsWithDefaultParams:dic];
    return [JKRouterTool configVCWithClass:[self class] options:options];
}

- (void)jkRouterViewControllerWithJSON:(NSDictionary *)dic
{
    JKRouterOptions *options = [JKRouterOptions optionsWithDefaultParams:dic];
    return [JKRouterTool configTheVC:self options:options];
}

+ (BOOL)validateTheAccessToOpenWithOptions:(JKRouterOptions *)options
{
    return YES;
}

+ (void)handleNoAccessToOpenWithOptions:(JKRouterOptions *)options
{
    
}

- (BOOL)jkRouterSpecialTransformWithNaVC:(UINavigationController *)naVC
{
    return NO;
}

- (RouterTransformVCStyle)jkRouterTransformStyle
{
    return RouterTransformVCStylePush;
}

-(void)setValue:(id)value forUndefinedKey:(NSString *)key
{
    
}

- (void)jkRouterRefresh
{

}

- (BOOL)jkNeedRefresh
{
    return NO;
}

+ (BOOL)jkIsTabBarItemVC
{
    return NO;
}

+ (NSInteger)jkTabIndex
{
    return 0;
}


@end
