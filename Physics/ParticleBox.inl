#ifndef __PHYSICS_PARTICLE_BOX_INL__
#define __PHYSICS_PARTICLE_BOX_INL__

#include "Physics/Configuration.h"
#include "Physics/Constant.h"

namespace DLS {
namespace Physics {

DLS_INLINE ParticleBox::ParticleBox(
    const std::vector< ParticleType< double > > particle_types,
    const std::vector< size_t > counts_of_each_particle,
    const double box_dimensions[ 3 ] )
{
    box_dimensions_[ 0 ] = box_dimensions[ 0 ];
    box_dimensions_[ 1 ] = box_dimensions[ 1 ];
    box_dimensions_[ 2 ] = box_dimensions[ 2 ];

    DLS_ASSERT(
        particle_types.size() == counts_of_each_particle.size(),
        "There needs to be a count specified for each particle" );

    particle_types_ = particle_types;
    counts_of_each_particle_ = counts_of_each_particle;

    Setup();

}

DLS_INLINE void ParticleBox::Setup()
{
    using namespace Math;

    particle_locations_.clear();

    // seed random number generator
    srand( time( NULL ) );

    for ( size_t type = 0; type < particle_types_.size(); ++type ) {

        std::vector< Point3D< double > > particle_list;// = particle_locations_[ type ];
        particle_list.resize( counts_of_each_particle_[ type ] );

        for ( size_t particle = 0; particle < particle_list.size(); ++particle ) {
            // randomly place the particles in the box - i.e. random location in each direction
            
            double random_x = ( ( double ) rand() ) / ( ( double ) RAND_MAX );
            double random_y = ( ( double ) rand() ) / ( ( double ) RAND_MAX );
            double random_z = ( ( double ) rand() ) / ( ( double ) RAND_MAX );

            double x_location = random_x * box_dimensions_[ 0 ];
            double y_location = random_y * box_dimensions_[ 1 ];
            double z_location = random_z * box_dimensions_[ 2 ];

            particle_list[ particle ] = Point3D< double >( x_location, y_location, z_location );

        }
        particle_locations_.push_back( particle_list );
    }
}

template< typename UpdateFunctor >
DLS_INLINE void ParticleBox::Update(
    double timestep,
    UpdateFunctor update_model )
{
    using namespace Math;

    for ( size_t type = 0; type < particle_locations_.size(); ++type ) {
        
        const double particle_mass = particle_types_[ type ].mass;
        const double root_mean_squared_velocity =
            sqrt(
                3 * Constant::kBoltzmannConstant * Configuration::kKelvinTemperature /
                particle_mass );

        std::vector< Point3D< double > > & particle_list = particle_locations_[ type ];
        update_model(
            timestep,
            root_mean_squared_velocity,
            particle_list );
    }
}

DLS_INLINE std::vector< Math::Point3D< double > > & ParticleBox::GetLocationList(
    const particle_id particle_number )
{
    const size_t number_location_lists = particle_locations_.size();

    DLS_ASSERT(
        particle_number < number_location_lists,
        "This particle ID is out of bounds and thus not accounted for" );

    return particle_locations_[ particle_number ];
}

} // namespace Physics
} // namespace DLS

#endif /* __PHYSICS_PARTICLE_BOX_INL__ */
