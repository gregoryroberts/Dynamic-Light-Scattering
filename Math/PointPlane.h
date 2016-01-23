#ifndef __MATH_POINTPLANE_H__
#define __MATH_POINTPLANE_H__

/*
	Distance from a point to plane in Cartesian coordinates.

	Reference: http://mathworld.wolfram.com/Point-PlaneDistance.html

	Plane is given by the description:

		a*x + b*y + c*z + d = 0

		Normal vector to plane is: [a, b, c], where in the function
		below, a, b, and c are denoted as x_normal, y_normal, and
		z_normal, respectively.

		d is a plane offset (denoted below as plane_offset)
*/

template< typename Type >
Type PointPlane(
	const Type x_coordinate,
	const Type y_coordinate,
	const Type z_coordinate,
	const Type x_normal,
	const Type y_normal,
	const Type z_normal,
	const Type plane_offset );



#endif /* __MATH_POINTPLANE_H__ */
