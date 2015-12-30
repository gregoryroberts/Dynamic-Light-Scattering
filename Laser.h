#ifndef __LASER_H__
#define __LASER_H__

#include <stdlib.h>

/*
	For now, this is governed by a 1D Gaussian drop-off
	in intensity with distance from the beam center.  This
	is assumed constant across the entire box.

	You should be able to query the laser with a coordinate
	or an array of coordinates and it should tell you the
	intensity there (including its approximation for effective
	extinction of intensity).

	Also assuming that do not need the x_0 parameter for the
	Gaussian because it will be situated at the center of the
	coordinate system.  This is the equation for a 1D Gaussian
	elongated along the entire box.
*/

class Laser {

  public:
  	Laser();
  	Laser( const double sigma, const double max_intensity );

  	double operator()( const double coordinate );
  	void operator()(
  		const double * const coordinates,
  		const size_t number_of_coordinates,
  		double * const intensities );

  private:
  	double sigma_;
  	double max_intensity_;
  	double prefactor_;
  	double exponent_divisor_;

};

#include "Laser.inl"

#endif /* __LASER_H__ */