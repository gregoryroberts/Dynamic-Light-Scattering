#ifndef __MATH_GEOMETRY_DOT_PRODUCT_INL__
#define __MATH_GEOMETRY_DOT_PRODUCT_INL__

namespace DLS {
namespace Math {
namespace Geometry {

template< typename Type >
DLS_INLINE const Type DotProduct(
  const Type x0,
  const Type y0,
  const Type z0,
  const Type x1,
  const Type y1,
  const Type z1 )
{
  return x0 * y0 + x1 * y1 + z0 * z1;
}

template< typename Type >
DLS_INLINE const Type DotProduct(
  const Type x0,
  const Type y0,
  const Type x1,
  const Type y1 )
{
  return x0 * y0 + x1 * y1;
}

} // namespace Geometry
} // namespace Math
} // namespace DLS


#endif /* __MATH_GEOMETRY_DOT_PRODUCT_INL__ */
