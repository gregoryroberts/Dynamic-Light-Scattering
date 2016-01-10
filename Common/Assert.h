#ifndef __COMMON_ASSERT_H__
#define __COMMON_ASSERT_H__

#include <assert.h>

namespace DLS {

#define DLS_ASSERT( condition, message ) assert( condition && message )

} // namespace DLS

#endif /* __COMMON_ASSERT_H__ */