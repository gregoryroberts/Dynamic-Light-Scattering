#ifndef __MATH_GEOMETRY_PLANE_ANGLE_H__
#define __MATH_GEOMETRY_PLANE_ANGLE_H__

#include "Common/Common.h"

namespace DLS {
namespace Math {
namespace Geometry {

/*
    Given three distinct points, form a plan and then find
    the angle formed between the following segments:
        -- first point and middle point
        AND
        -- middle point and last point

    Note: the function will not check for distinctness of the
    three points for performance reasons (this function will
    be called many times), so they should be guaranteed to be
    distinct when passed into the function.
*/
template< typename Type >
const Type PlaneAngleRadians(
    const Type first_point_x,
    const Type first_point_y,
    const Type first_point_z,
    const Type middle_point_x,
    const Type middle_point_y,
    const Type middle_point_z,
    const Type last_point_x,
    const Type last_point_y,
    const Type last_point_z );

} // namespace Geometry
} // namespace Math
} // namespace DLS

#include "Math/Geometry/PlaneAngle.inl"

#endif /* __MATH_GEOMETRY_PLANE_ANGLE_H__ */
