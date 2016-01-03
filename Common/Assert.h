#ifndef __COMMON_ASSERT_H__
#define __COMMON_ASSERT_H__

#include <assert.h>

#define DLS_ASSERT( condition, message ) assert( condition && message )

#endif /* __COMMON_ASSERT_H__ */