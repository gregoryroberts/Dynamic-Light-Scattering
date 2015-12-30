#ifndef __LASER_INL__
#define __LASER_INL__

Laser::Laser()
: sigma_( 1.0f ),
max_intensity_( 1.0f );
{
	prefactor_ = 1.0f / ( sqrt( 2 * M_PI ) * /* sigma */ 1.0f );
	exponent_divisor_ = 1.0f / ( 2 * /* sigma */ 1.0f * /* sigma */ 1.0f );
}

Laser::Laser( const double sigma, const double max_intensity )
: sigma_( sigma ),
max_intensity_( max_intensity )
{
	assert( sigma_ >= 0.0f );

	prefactor_ = 1.0f / ( sqrt( 2 * M_PI ) * sigma );
	exponent_divisor_ = 1.0f / ( 2 * sigma * sigma );
}

void double Laser::operator()( const double coordinate ) {

	return
		max_intensity_ *
		prefactor_ *
		exp( coordinate * coordinate * exponent_divisor_ );

}

#endif /* __LASER_INL__ */