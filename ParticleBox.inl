#ifndef __PARTICLE_BOX_INL__
#define __PARTICLE_BOX_INL__

// todo(groberts): these should be separated out
#include <cstdlib>

template< size_t ParticleCount, size_t MaxNumberParticles >
ParticleBox< ParticleCount, MaxNumberParticles >::ParticleBox(
    ParticleType * particle_types,
    size_t * particle_counts,
    double box_dimensions[ 3 ] )
: particle_types_( particle_types ),
particle_counts_( particle_counts )
{
    box_dimensions_[ 0 ] = box_dimensions[ 0 ];
    box_dimensions_[ 1 ] = box_dimensions[ 1 ];
    box_dimensions_[ 2 ] = box_dimensions[ 2 ];

    particle_locations_.clear();
}

template< size_t ParticleCount, size_t MaxNumberParticles >
void ParticleBox< ParticleCount, MaxNumberParticles >::Reset()
{

    // seed random number generator
    srand( time( NULL ) );

    for ( size_t type = 0; type < particle_locations_.size(); ++type ) {
        
        std::vector< Point3D< double > > & particle_list = particle_locations_[ type ];
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
    }
}

template< size_t ParticleCount, size_t MaxNumberParticles >
template< typename UpdateFunctor >
void ParticleBox< ParticleCount, MaxNumberParticles >::Update(
    double timestep,
    UpdateFunctor update_model )
{
    for ( size_t type = 0; type < particle_locations_.size(); ++type ) {
        
        std::vector< Point3D< double > > & particle_list = particle_locations_[ type ];
        for ( size_t particle = 0; particle < particle_list.size(); ++particle ) {

            Point3D< double > & current_particle_location = particle_list[ particle ];
            update_model( timestep, current_particle_location, box_dimensions_ );
        }
    }
}


#endif /* __PARTICLE_BOX_INL__ */