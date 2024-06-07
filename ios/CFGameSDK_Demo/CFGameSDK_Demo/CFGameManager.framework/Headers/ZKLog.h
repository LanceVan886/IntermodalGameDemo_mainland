//
//  ZKLog.h
//



#import <Foundation/Foundation.h>
#import "ZKSingleton.h"
#import "ZKBaseDefine.h"


#pragma mark -

#if __ZK_LOG__


#undef	KC_PRINT
#define KC_PRINT( ... )		[[ZKLogger sharedInstance] level:KCLogLevelNone format:__VA_ARGS__];

#undef	KC_INFO
#define KC_INFO( ... )		[[ZKLogger sharedInstance] level:KCLogLevelInfo format:__VA_ARGS__];

#undef	KC_PERF
#define KC_PERF( ... )		[[ZKLogger sharedInstance] level:KCLogLevelPerf format:__VA_ARGS__];

#undef	KC_WARN
#define KC_WARN( ... )		[[ZKLogger sharedInstance] level:KCLogLevelWarn format:__VA_ARGS__];

#undef	KC_ERROR
#define KC_ERROR( ... )	[[ZKLogger sharedInstance] level:KCLogLevelError format:__VA_ARGS__];

#undef	KCPrint
#define KCPrint( ... )	[[ZKLogger sharedInstance] level:KCLogLevelNone format:__VA_ARGS__];

#undef	KC_DUMP_VAR
#define KC_DUMP_VAR( __obj )	KCPrint( [__obj description] );

#undef	KC_DUMP_OBJ
#define KC_DUMP_OBJ( __obj )	KCPrint( [__obj dump] );

#undef	KC_PRINT_CALLSTACK
#define KC_PRINT_CALLSTACK( __n )	 [KCLogger printCallstack:__n];

#undef KC_PRINT_RUNTIME_BEGIN
#define KC_PRINT_RUNTIME_BEGIN  [KCLogger printRuntime:^{

#undef KC_PRINT_RUNTIME_COMMIT
#define KC_PRINT_RUNTIME_COMMIT } prefix:[NSString stringWithFormat:(@"[Runtime] %s #%d\n"), __PRETTY_FUNCTION__, __LINE__]];


#else	// #if __KC_LOG__

#undef	KC_PRINT
#define KC_PRINT( ... )

#undef	KC_INFO
#define KC_INFO( ... )

#undef	KC_PERF
#define KC_PERF( ... )

#undef	KC_WARN
#define KC_WARN( ... )

#undef	KC_ERROR
#define KC_ERROR( ... )

#undef	KCPrint
#define KCPrint( ... )

#undef	KC_DUMP_VAR
#define KC_DUMP_VAR( __obj )

#undef	KC_DUMP_OBJ
#define KC_DUMP_OBJ( __obj )

#undef	KC_PRINT_CALLSTACK
#define KC_PRINT_CALLSTACK( __n )

#undef KC_PRINT_RUNTIME_BEGIN
#define KC_PRINT_RUNTIME_BEGIN

#undef KC_PRINT_RUNTIME_COMMIT
#define KC_PRINT_RUNTIME_COMMIT

#endif	// #if __KC_LOG__

#undef	KC_TODO
#define KC_TODO( desc, ... )

#pragma mark -


typedef enum
{
	ZKLogLevelNone		= 0,
	ZKLogLevelInfo		= 100,
	ZKLogLevelPerf		= 200,
	ZKLogLevelWarn		= 300,
	ZKLogLevelError	= 400
} ZKLogLevel;

#pragma mark -

@interface ZKLogger : NSObject

AS_SINGLETON( ZKLogger );

@property (nonatomic, assign) BOOL				showLevel;
@property (nonatomic, assign) BOOL				showModule;
@property (nonatomic, assign) BOOL				enabled;
@property (nonatomic, retain) NSMutableArray *	backlogs;  //not implement
@property (nonatomic, assign) NSUInteger		indentTabs;

- (void)toggle;
- (void)enable;
- (void)disable;

- (void)indent;
- (void)indent:(NSUInteger)tabs;
- (void)unindent;
- (void)unindent:(NSUInteger)tabs;

- (void)level:(ZKLogLevel)level format:(NSString *)format, ...;
- (void)level:(ZKLogLevel)level format:(NSString *)format args:(va_list)args;

+ (void)printCallstack:(NSUInteger)depth;

//prefix string added before print run time
+ (void)printRuntime:(void (^)(void))block prefix:(NSString*)pre;

#pragma mark - file log
- (void)startFileLog;
- (void)stopFileLog;
- (NSString*)fileLogPath;
- (BOOL)deleteFileLog;

@end

#pragma mark -

#if __cplusplus
extern "C" {
#endif


#if __KC_LOG__Brief__
    #  define ZKLog(fmt, ...) ZKLogBrief(fmt, ##__VA_ARGS__)
#else
    #  define ZKLog(fmt, ...) ZKLoger(fmt, ##__VA_ARGS__)
#endif
    

#  define ZKLoger(fmt, ...) ZKLogBrief((@"%s #%d\n\t\t" fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
	void ZKLogBrief( NSString * format, ... );
	
#if __cplusplus
};
#endif


