#ifndef __MATH_GEOMETRY_PLANE_ANGLE_INL__
#define __MATH_GEOMETRY_PLANE_ANGLE_INL__

#include "Math/Geometry/DotProduct.h"

namespace DLS {
namespace Math {
namespace Geometry {

template< typename Type >
DLS_INLINE const Type PlaneAngle(
    const Type first_point_x,
    const Type first_point_y,
    const Type first_point_z,
    const Type middle_point_x,
    const Type middle_point_y,
    const Type middle_point_z,
    const Type last_point_x,
    const Type last_point_y,
    const Type last_point_z )
{

	const Type incoming_x = first_point_x - middle_point_x;
	const Type incoming_y = first_point_y - middle_point_y;
	const Type incoming_z = first_point_z - middle_point_z;

	const Type outgoing_x = last_point_x - middle_point_x;
	const Type outgoing_y = last_point_y - middle_point_y;
	const Type outgoing_z = last_point_z - middle_point_z;

	const Type dot_product_between_vectors =
		DotProduct(
			incoming_x,
			incoming_y,
			incoming_z,
			outgoing_x,
			outgoing_y,
			outgoing_z );

	/*
		The dot product is equal to the product
		of the magnitudes of the two vectors and
		the cosine of of the angle between them.
	*/

	const Type incoming_magnitude =
		sqrt( DotProduct(
			incoming_x,
			incoming_y,
			incoming_z,
			incoming_x,
			incoming_y,
			incoming_z ) );

	const Type outgoing_magnitude =
		sqrt( DotProduct(
			outgoing_x,
			outgoing_y,
			outgoing_z,
			outgoing_x,
			outgoing_y,
			outgoing_z ) );

	const Type reciprocal_magnitude_product =
		Type( 1 ) / ( incoming_magnitude * outgoing_magnitude );

	const Type angle = acos(
		dot_product_between_vectors * reciprocal_magnitude_product );

	return angle;

}

} // namespace Geometry
} // namespace Math
} // namespace DLS


#endif /* __MATH_GEOMETRY_PLANE_ANGLE_INL__ */
