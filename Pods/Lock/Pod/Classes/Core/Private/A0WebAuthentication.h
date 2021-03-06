//  A0WebAuthentication.h
//
// Copyright (c) 2014 Auth0 (http://auth0.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

@class A0UserProfile, A0Token, A0Application, A0Strategy;

/**
 *  Handle logic for Web Authentication using Auth0 backend.
 *  It will check if the URL has a valid URL with the format: `a0<ClientId>://<strategy>.auth0.com/authorize` and the authentication result as query parameters or fragment (with the '#' character).
 */
@interface A0WebAuthentication : NSObject

/**
 *  Callback URL for web authentication using either Safari or embedded UIWebView.
 */
@property (readonly, nonatomic) NSURL *callbackURL;

/**
 *  Initialise an instance with Auth0's information and for a specific strategy (e.g. linkedin).
 *
 *  @param application Auth0 Applicaiton information to initialise the object.
 *  @param strategy    strategy that will be handled by this object.
 *
 *  @return the instance initialised.
 */
- (instancetype)initWithApplication:(A0Application *)application strategy:(A0Strategy *)strategy;

/**
 *  Checks if the URL has the valid callback format and is for the strategy this object is configured.
 *
 *  @param url a NSURL to validate
 *
 *  @return YES if the URL is valid and for this objetc's `A0Strategy`, NO otherwise.
 */
- (BOOL)validateURL:(NSURL *)url;


/**
 *  Returns the token information from the URL query parameters or fragment.
 *
 *  @param url   where the token information is obtaned
 *  @param error if the parsing fails or the URL contains an error message
 *
 *  @return an instance of `A0Token` with the token information or nil if an error occurs.
 */
- (A0Token *)tokenFromURL:(NSURL *)url error:(NSError **)error;

@end
