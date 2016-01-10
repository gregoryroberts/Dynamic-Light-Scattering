#ifndef __PHYSICS_CONSTANT_H__
#define __PHYSICS_CONSTANT_H__

#include "Common/Common.h"

namespace DLS {
namespace Physics {

struct Constant {

	// in m^2 * kg / ( s^2 * K )
	static constexpr double kBoltzmannConstant = 1.38064852e-23;

};

} // namespace Physics
} // namespace DLS

#endif /* __PHYSICS_CONSTANT_H__ */