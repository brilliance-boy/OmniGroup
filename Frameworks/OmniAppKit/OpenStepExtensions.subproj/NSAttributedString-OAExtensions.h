// Copyright 1997-2005, 2007-2009, 2011-2013 Omni Development, Inc. All rights reserved.
//
// This software may only be used and reproduced according to the
// terms in the file OmniSourceLicense.html, which should be
// distributed with this project and can also be found at
// <http://www.omnigroup.com/developer/sourcecode/sourcelicense/>.
//
// $Id$

#if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE
    #import <UIKit/NSAttributedString.h>
    #import <CoreGraphics/CGGeometry.h>
#else
    #import <AppKit/NSAttributedString.h>
    #import <Foundation/NSGeometry.h>
#endif

#import <OmniAppKit/OATextAttachment.h>

@interface NSAttributedString (OAExtensions)

+ (NSString *)attachmentString;

- (BOOL)containsAttribute:(NSString *)attributeName;
- (BOOL)containsAttribute:(NSString *)attributeName inRange:(NSRange)range;

- (BOOL)containsAttachments;
- (id)attachmentAtCharacterIndex:(NSUInteger)characterIndex;

- (void)eachAttachment:(void (^)(OATextAttachment *, BOOL *stop))applier;

#if !defined(TARGET_OS_IPHONE) || !TARGET_OS_IPHONE
+ (NSAttributedString *)attributedStringWithImage:(NSImage *)anImage;

- (NSData *)rtf;

// See <bug:///79949> (Update NSAttributedString extension method drawInRectangle:alignment:verticallyCentered:)
- (void)drawInRectangle:(CGRect)rectangle alignment:(NSTextAlignment)alignment verticallyCentered:(BOOL)verticallyCenter;

- (void)drawCenteredShrinkingToFitInRect:(CGRect)rect;
#endif

@end
