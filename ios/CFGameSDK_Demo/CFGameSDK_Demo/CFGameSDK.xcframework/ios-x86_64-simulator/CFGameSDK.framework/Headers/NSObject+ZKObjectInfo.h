//
//  NSObject+ZKObjectInfo.h
//


#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>
#import <UIKit/UIKit.h>
#import <objc/runtime.h>

#define ZK_VALUE(struct) ({ __typeof__(struct) __struct = struct; [NSValue valueWithBytes:&__struct objCType:@encode(__typeof__(__struct))]; })

#define ZK_MAKELIVE(_CLASSNAME_)	Class _CLASSNAME_ = NSClassFromString((NSString *)CFSTR(#_CLASSNAME_));

#define ZK_VERIFIED_CLASS(_CLASSNAME_) ((_CLASSNAME_ *) NSClassFromString(@"" # _CLASSNAME_))


typedef IMP *IMPPointer;
BOOL class_swizzleMethodAndStore(Class aClass, SEL aOriginal, IMP aReplacement, IMPPointer aStore);

@interface NSObject (ZKObjectInfo)

// A work in progress
+ (NSString *) typeForString: (const char *) aTypeName;

// Return all superclasses of class or object
+ (NSArray *) superclasses;
- (NSArray *) superclasses;

// Examine
+ (NSString *) dump;
- (NSString *) dump;

// Access to object essentials for run-time checks. Stored by class in dictionary.
// Return an array of all an object's selectors
+ (NSArray *) getMetaSelectorListForClass;
+ (NSArray *) getSelectorListForClass;
+ (NSArray *) getPropertyListForClass;
+ (NSArray *) getIvarListForClass;
+ (NSArray *) getProtocolListForClass;



// Return a dictionary with class/selectors entries, all the way up to NSObject
@property (readonly) NSDictionary *selectors;
@property (readonly) NSDictionary *properties;  //you can see KCProperty class
@property (readonly) NSDictionary *ivars;
@property (readonly) NSDictionary *protocols;

// Check for properties, ivar. Use respondsToSelector: and conformsToProtocol: as well
- (BOOL) hasProperty: (NSString *) aPropertyName;
- (BOOL) hasIvar: (NSString *) aIvarName;
+ (BOOL) classExists: (NSString *) aClassName;
+ (id) instanceOfClassNamed: (NSString *) aClassName;

+ (void)swizzleMethod:(SEL)aOrigSel withMethod:(SEL)aAltSel;
+ (BOOL)swizzle:(SEL)aOriginal with:(IMP)aReplacement store:(IMPPointer)aStore;
+ (void)exchangeMethond:(SEL)aSel1 :(SEL)aSel2;
+(IMP)replaceMethod :(SEL)aOldMethond :(IMP)aNewIMP;

@end


// Method swizzling
void ZKSwapClassMethods(Class cls, SEL original, SEL replacement);
void ZKSwapInstanceMethods(Class cls, SEL original, SEL replacement);

// Module subclass support
BOOL ZKClassOverridesClassMethod(Class cls, SEL selector);
BOOL ZKClassOverridesInstanceMethod(Class cls, SEL selector);


