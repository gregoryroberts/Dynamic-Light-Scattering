#ifndef __PHYSICS_PARTICLE_BOX_H__
#define __PHYSICS_PARTICLE_BOX_H__

#include "Common/Common.h"
#include "Math/Point.h"
#include "Physics/ParticleType.h"

namespace DLS {
namespace Physics {

template< size_t ParticleCount, size_t MaxNumberParticles >
class ParticleBox
{

  public:
    static constexpr size_t kParticleCount = ParticleCount;
    static constexpr size_t kMaxNumberParticles = MaxNumberParticles;

    /* Constructors */
    ParticleBox() = delete;
    ParticleBox(
        ParticleType< double > * particle_types,
        size_t * particle_counts,
        double box_dimensions[ 3 ] );

    /* Box Update Functions */
    void Reset();
    // allow each particle to be updated via a custom function
    // update functor should have an overloaded () operator that
    // is templated/overloadable on the particle type and is
    // templated on the box descriptor
    template< typename UpdateFunctor >
    void Update(
        double timestep,
        UpdateFunctor update_model );

    /* Member accessor */
     void GetLocationList(
        std::vector< Math::Point3D< double > > & locations,
        const particle_id particle_number );

  private:
    ParticleType< double > * particle_types_;
    size_t * particle_counts_;

    double box_dimensions_[ 3 ];

    std::vector< std::vector< Math::Point3D< double > > > particle_locations_;

};

} // namespace Physics
} // namespace DLS

#include "Physics/ParticleBox.inl"

#endif /* __PHYSICS_PARTICLE_BOX_H__ */
