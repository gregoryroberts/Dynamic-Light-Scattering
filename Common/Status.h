#ifndef __COMMON_STATUS_H__
#define __COMMON_STATUS_H__

#include "Common/Common.h"

namespace DLS {

enum class Status : uint8_t {
	Failure = 0,
	Success = 1
};

} // namespace DLS

#endif /* __COMMON_STATUS_H__ */