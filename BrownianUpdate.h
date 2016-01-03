#ifndef __BROWNIAN_UPDATE_H__
#define __BROWNIAN_UPDATE_H__

#include "Common/Common.h"
#include "Math/Point.h"

/*
    Update the particles in a random direction
    according to rms velocity at this temperature.

    This is updated assuming the particle moves
    along a single trajectory during the timestep.
    If the timestep is larger, we may need to make
    this update along several different trajectories.
*/

struct BrownianUpdate {

    void operator()(
        const double timestep_in_seconds,
        const double root_mean_squared_velocity,
        std::vector< Point3D< double > > & particle_list );
};


#include "BrownianUpdate.inl"

#endif /* __BROWNIAN_UPDATE_H__ */