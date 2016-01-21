#ifndef __PHYSICS_PARTICLE_TYPE_H__
#define __PHYSICS_PARTICLE_TYPE_H__

#include "Common/Common.h"
#include "Math/Complex.h"

namespace DLS {
namespace Physics {

typedef size_t particle_id;

template< typename Type >
struct ParticleType {
	Math::ComplexRectangular< Type > index_of_refraction;
	Type mass;
};

} // namespace Physics
} // namespace DLS

#endif /* __PHYSICS_PARTICLE_TYPE_H__ */