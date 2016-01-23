#ifndef __PHYSICS_PHOTODIODE_H__
#define __PHYSICS_PHOTODIODE_H__

#include "Common/Common.h"

namespace DLS {
namespace Physics {

/*
	Very simple photodiode.
*/

template< typename IntensityType >
struct Photodiode {

  /* Constructor */
  Photodiode();

  /* Member functions */
  const IntensityType 	AccumulatedIntensity() const;
  IntensityType & 		  AccumulatedIntensity();

  // Drain the photodiode by reading it
  // which resets the value to zero
  const IntensityType 		    Drain();

  void 					        IncidentRay( const IntensityType ray_intensity );

  private:
  	IntensityType accumulated_intensity_;

};

} // namespace Physics
} // namespace DLS


#include "Physics/Photodiode.inl"

#endif /* __PHYSICS_PHOTODIODE_H__ */