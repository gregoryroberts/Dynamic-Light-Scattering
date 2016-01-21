#ifndef __MATH_GEOMETRY_PLANE_H__
#define __MATH_GEOMETRY_PLANE_H__

#include "Common/Common.h"

namespace DLS {
namespace Math {
namespace Geometry {

/*
  A description of a 2D plane in 3D space.  See:
  http://mathworld.wolfram.com/Plane.html
*/

template< typename Type >
struct Plane {
  
  typedef Type PlaneType;

  /*
  	Construct a plane with the specified
  	normal vector and that passes through
  	the specified point.
  */
  Plane(
  	const Type _normal_x,
  	const Type _normal_y,
  	const Type _normal_z,
  	const Type _point_x,
  	const Type _point_y,
  	const Type _point_z );

  	PlaneType normal_x;
  	PlaneType normal_y;
  	PlaneType normal_z;
  	PlaneType offset;

};

} // namespace Geometry
} // namespace Math
} // namespace DLS

#include "Math/Geometry/Plane.inl"

#endif /* __MATH_GEOMETRY_PLANE_H__ */
