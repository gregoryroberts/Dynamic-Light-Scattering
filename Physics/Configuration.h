#ifndef __PHYSICS_CONFIGURATION_H__
#define __PHYSICS_CONFIGURATION_H__

#include "Common/Common.h"

namespace DLS {
namespace Physics {

struct Configuration {

	// room temperature for now
	static constexpr double kKelvinTemperature = 298;

};

} // namespace Physics
} // namespace DLS

#endif /* __PHYSICS_CONFIGURATION_H__ */