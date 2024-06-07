//
//  ZKTaskQueue.h
//


#import <Foundation/Foundation.h>
#import "ZKSingleton.h"

#define PRIORITY_HIGH DISPATCH_QUEUE_PRIORITY_HIGH
#define PRIORITY_DEFAULT DISPATCH_QUEUE_PRIORITY_DEFAULT
#define PRIORITY_LOW DISPATCH_QUEUE_PRIORITY_LOW
#define PRIORITY_BACKGROUND DISPATCH_QUEUE_PRIORITY_BACKGROUND

#pragma mark -

#define FOREGROUND_BEGIN	[[ZKTaskQueue sharedInstance] foreground:^{
#define FOREGROUND_DELAY(x)	[[ZKTaskQueue sharedInstance] foregroundWithDelay:(dispatch_time_t)x block:^{
#define FOREGROUND_COMMIT	}];

#define BACKGROUND_BEGIN	[[ZKTaskQueue sharedInstance] background:^{
#define BACKGROUND_DELAY(x)	[[ZKTaskQueue sharedInstance] backgroundWithDelay:(dispatch_time_t)x block:^{
#define BACKGROUND_COMMIT	}];

#define BACKGROUND_GLOBAL_BEGIN(priority) dispatch_async(dispatch_get_global_queue(priority, 0), ^{
#define BACKGROUND_GLOBAL_COMMIT });

#pragma mark -

@interface ZKTaskQueue : NSObject
{
	dispatch_queue_t m_foreQueue;
	dispatch_queue_t m_backQueue;
}

AS_SINGLETON( ZKTaskQueue );

-(id)initWithName:(NSString*)aName;
-(id)initWithName:(NSString*)aName Att:(dispatch_queue_attr_t)aAtt;

- (dispatch_queue_t)foreQueue;
- (dispatch_queue_t)backQueue;

- (void)foreground:(dispatch_block_t)aBlock;
- (void)background:(dispatch_block_t)aBlock;
- (void)foregroundWithDelay:(dispatch_time_t)ms block:(dispatch_block_t)block;
- (void)backgroundWithDelay:(dispatch_time_t)ms block:(dispatch_block_t)block;

@end
