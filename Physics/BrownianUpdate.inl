#ifndef __PHYSICS_BROWNIAN_UPDATE_INL__
#define __PHYSICS_BROWNIAN_UPDATE_INL__

namespace DLS {
namespace Physics {

DLS_INLINE void BrownianUpdate::operator()(
    const double timestep_in_seconds,
    const double root_mean_squared_velocity,
    std::vector< Math::Point3D< double > > & particle_list )
{

	// update in a random amount in x, y, and z
	// normalizing to the rms velocity and timestep

	double particle_displacment = root_mean_squared_velocity * timestep_in_seconds;

    for ( size_t particle = 0; particle < particle_list.size(); ++particle ) {
		// can these be negative?
		// because we want them to be able to be negative
		double random_x = ( ( double ) rand() ) / ( ( double ) RAND_MAX );
		double random_y = ( ( double ) rand() ) / ( ( double ) RAND_MAX );
		double random_z = ( ( double ) rand() ) / ( ( double ) RAND_MAX );

		const double norm_squared =
			random_x * random_x +
			random_y * random_y +
			random_z * random_z;

		const double norm = sqrt( norm_squared );
		const double displacement_factor = particle_displacment / norm;

		random_x *= displacement_factor;
		random_y *= displacement_factor;
		random_z *= displacement_factor;

	}
}

} // namespace Physics
} // namespace DLS

#endif /* __PHYSICS_BROWNIAN_UPDATE_INL__ */