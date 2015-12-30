#ifndef __PARTICLE_BOX_H__
#define __PARTICLE_BOX_H__

#include <stddef.h>
#include <vector>

#include "ParticleType.h"
#include "Math/Point.h"

template< size_t ParticleCount, size_t MaxNumberParticles >
class ParticleBox
{

  public:

    static constexpr size_t kParticleCount = ParticleCount;
    static constexpr size_t kMaxNumberParticles = MaxNumberParticles;

    /* Constructors */
    ParticleBox() = delete;
    ParticleBox(
        ParticleType * particle_types,
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
    // templated on ParticleType to grab out the locations for a particle of
    // a specific type -- is this the best way to do that
    template< typename ParticleType >
    void GetLocationList( std::vector< Point3D< double > > & locations );

  private:
    ParticleType * particle_types_;
    size_t * particle_counts_;

    double box_dimensions_[ 3 ];

    std::vector< std::vector< Point3D< double > > > particle_locations_;

};





#include "ParticleBox.inl"

#endif /* __PARTICLE_BOX_H__ */