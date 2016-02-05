#ifndef __PHYSICS_BROWNIAN_UPDATE_INL__
#define __PHYSICS_BROWNIAN_UPDATE_INL__

namespace DLS {
namespace Physics {

DLS_INLINE void BrownianUpdate::operator()(
    const double timestep_in_seconds,
    const double root_mean_squared_velocity,
    std::vector< Math::Point3D< double > > & particle_list )
{
	const double max_displacement =
		timestep_in_seconds * root_mean_squared_velocity;

	constexpr double kMean = 0.0;
	const double kStandardDeviation =
		( 1. / sqrt( 3. ) ) * max_displacement;

    std::normal_distribution< double > x_distribution( kMean, kStandardDeviation );
    std::normal_distribution< double > y_distribution( kMean, kStandardDeviation );
    std::normal_distribution< double > z_distribution( kMean, kStandardDeviation );

  	std::default_random_engine x_generator;
  	std::default_random_engine y_generator;
  	std::default_random_engine z_generator;

	x_distribution.reset();
	y_distribution.reset();
	z_distribution.reset();

    for ( size_t particle = 0; particle < particle_list.size(); ++particle ) {

    	double next_x = x_distribution( x_generator );
    	double next_y = y_distribution( y_generator );
    	double next_z = z_distribution( z_generator );

		particle_list[ particle ].x += next_x;x_distribution( x_generator );
		particle_list[ particle ].y += next_y;y_distribution( y_generator );
		particle_list[ particle ].z += next_z;z_distribution( z_generator );

	}
}

} // namespace Physics
} // namespace DLS

#endif /* __PHYSICS_BROWNIAN_UPDATE_INL__ */