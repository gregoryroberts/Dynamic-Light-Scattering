#ifndef __PHYSICS_PARTICLE_BOX_H__
#define __PHYSICS_PARTICLE_BOX_H__

#include "Common/Common.h"
#include "Math/Point.h"
#include "Physics/ParticleType.h"

namespace DLS {
namespace Physics {

class ParticleBox
{

  public:

    /* Constructors */
    ParticleBox() = delete;
    ParticleBox(
        const std::vector< ParticleType< double > > particle_types,
        const std::vector< size_t > counts_of_each_particle,
        const double box_dimensions[ 3 ] );

    /* Box Update Functions */
    // setup the box, adding all particles at a randome location
    void Setup();
    // allow each particle to be updated via a custom function
    // update functor.  The update functor should take as
    // arguments a timestep, an rms velocity for all the particles
    // in the list and a list of positions to update
    template< typename UpdateFunctor >
    void Update(
        double timestep,
        UpdateFunctor update_model );

    /* Member accessor */
    std::vector< Math::Point3D< double > > & GetLocationList(
        const particle_id particle_number );

  private:
    std::vector< ParticleType< double > > particle_types_;
    std::vector< size_t > counts_of_each_particle_;

    double box_dimensions_[ 3 ];

    std::vector< std::vector< Math::Point3D< double > > > particle_locations_;

};

} // namespace Physics
} // namespace DLS

#include "Physics/ParticleBox.inl"

#endif /* __PHYSICS_PARTICLE_BOX_H__ */
