#ifndef __MATH_GEOMETRY_CROSS_PRODUCT_INL__
#define __MATH_GEOMETRY_CROSS_PRODUCT_INL__

namespace DLS {
namespace Math {
namespace Geometry {

template< typename Type >
DLS_INLINE void CrossProduct(
  const Type x0,
  const Type y0,
  const Type z0,
  const Type x1,
  const Type y1,
  const Type z1.
  Type & x_cross,
  Type & y_cross,
  Type & z_cross )
{
	x_cross = y0 * z1 - z0 * y1;
	y_cross = z0 * x1 - x0 * z1;
	z_cross = x0 * y1 - y0 * x1;
}

} // namespace Geometry
} // namespace Math
} // namespace DLS


#endif /* __MATH_GEOMETRY_CROSS_PRODUCT_INL__ */
