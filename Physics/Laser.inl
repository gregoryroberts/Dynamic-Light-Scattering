#ifndef __PHYSICS_LASER_INL__
#define __PHYSICS_LASER_INL__

namespace DLS {
namespace Physics {

DLS_INLINE Laser::Laser()
: sigma_( 1.0f ),
mean_x_( 0.0f ),
mean_y_( 0.0f ),
max_intensity_( 1.0f )
{
	prefactor_ = 1.0f / ( sqrt( 2 * M_PI ) * /* sigma */ 1.0f );
	exponent_divisor_ = 1.0f / ( 2 * /* sigma */ 1.0f * /* sigma */ 1.0f );
}

DLS_INLINE Laser::Laser(
	const double sigma,
	const double mean_x,
	const double mean_y,
	const double max_intensity )
: sigma_( sigma ),
mean_x_( mean_x ),
mean_y_( mean_y ),
max_intensity_( max_intensity )
{
	DLS_ASSERT( sigma_ >= 0.0f, "Invalid sigma given for Gaussian" );

	prefactor_ = 1.0f / ( sqrt( 2 * M_PI ) * sigma );
	exponent_divisor_ = 1.0f / ( 2 * sigma * sigma );
}

DLS_INLINE double Laser::operator()(
	const double coordinate_x,
	const double coordinate_y )
{
	const double x_difference = coordinate_x - mean_x_;
	const double x_difference_squared = x_difference * x_difference;

	const double y_difference = coordinate_y - mean_y_;
	const double y_difference_squared = y_difference * y_difference;

	return
		max_intensity_ *
		prefactor_ *
		exp( -( x_difference_squared + y_difference_squared ) * exponent_divisor_ );
}

DLS_INLINE void Laser::operator()(
	const double * const coordinates_x,
	const double * const coordinates_y,
	const size_t number_of_coordinates,
	double * const intensities )
{

	for ( size_t coordinate = 0; coordinate < number_of_coordinates; ++coordinate ) {
		intensities[ coordinate ] = this->operator()(
			coordinates_x[ coordinate ],
			coordinates_y[ coordinate ] );
	}

}

} // namespace Physics
} // namespace DLS

#endif /* __PHYSICS_LASER_INL__ */