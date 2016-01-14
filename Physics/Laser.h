#ifndef __PHYSICS_LASER_H__
#define __PHYSICS_LASER_H__

#include "Common/Common.h"

namespace DLS {
namespace Physics {

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
  	Laser(
      const double sigma,
      const double mean_x,
      const double mean_y,
      const double max_intensity );

  	double operator()(
      const double coordinate_x,
      const double coordinate_y );
  	void operator()(
  		const double * const coordinates_x,
      const double * const coordinates_y,
  		const size_t number_of_coordinates,
  		double * const intensities );

  private:
  	double sigma_;
    double mean_x_;
    double mean_y_;
  	double max_intensity_;
    // 1 / ( 2 * pi * sigma^2 ) --> normalization over plane
  	double prefactor_;
    // 1 / ( 2 * sigma^2 ) --> exponent always multiplied by this quantity
  	double exponent_divisor_;

};

} // namespace Physics
} // namespace DLS

#include "Physics/Laser.inl"

#endif /* __PHYSICS_LASER_H__ */