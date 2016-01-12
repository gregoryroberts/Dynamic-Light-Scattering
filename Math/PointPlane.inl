#ifndef __MATH_POINTPLANE_INL__
#define __MATH_POINTPLANE_INL__

template< typename Type >
DLS_INLINE Type PointPlane(
	const Type x_coordinate,
	const Type y_coordinate,
	const Type z_coordinate,
	const Type x_normal,
	const Type y_normal,
	const Type z_normal,
	const Type plane_offset)
{
	const Type plane_normal_magnitude_squared =
		x_normal * x_normal + y_normal * y_normal + z_normal * z_normal;
	const Type plane_normal_magnitude = sqrt( plane_normal_magnitude_squared );
	
	// maybe bigger than an epsilon would be good here
	DLS_ASSERT( plane_normal_magnitude > 0, "The normal to the plane is a zero vector" );

	const Type projection =
		x_coordinate * x_normal +
		y_coordinate * y_normal +
		z_coordinate * z_normal +
		plane_offset;

	return fabs( projection / plane_normal_magnitude );
}


#endif /* __MATH_POINTPLANE_INL__ */
