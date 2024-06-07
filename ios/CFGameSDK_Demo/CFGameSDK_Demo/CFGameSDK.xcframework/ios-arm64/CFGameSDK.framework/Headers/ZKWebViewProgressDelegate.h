//
// Created by kerry on 17/3/1.
// Copyright (c) 2017 kerry. All rights reserved.
//

#ifndef ZKWebViewProgressDelegate_h
#define ZKWebViewProgressDelegate_h

@class ZKWebView;

@protocol ZKWebViewProgressDelegate <NSObject>
@optional
-(void)webView:(id)aWebView identifierForInitialRequest:(NSURLRequest*)aInitialRequest;
-(void)webView:(id)aWebView didReceiveResourceNumber:(int)aResourceNumber totalResources:(int)aTotalResources;
-(void)webView:(id)aWebView didReceiveTitle:(NSString *)aTitle;
@end

#endif /* ZKWebViewProgressDelegate_h */