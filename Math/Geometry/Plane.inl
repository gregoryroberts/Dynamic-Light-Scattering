#ifndef __MATH_GEOMETRY_PLANE_INL__
#define __MATH_GEOMETRY_PLANE_INL__

namespace DLS {
namespace Math {
namespace Geometry {

template< typename Type >
DLS_INLINE Plane< Type >::  Plane(
  	const Type _normal_x,
  	const Type _normal_y,
  	const Type _normal_z,
  	const Type _point_x,
  	const Type _point_y,
  	const Type _point_z )
: normal_x( _normal_x ),
normal_y( _normal_y ),
normal_z( _normal_z )
{
	offset =
		-_normal_x * _point_x - _normal_y * _point_y - _normal_z * _point_z;
}

} // namespace Geometry
} // namespace Math
} // namespace DLS


#endif /* __MATH_GEOMETRY_PLANE_INL__ */
