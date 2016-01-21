#ifndef __MATH_GEOMETRY_DOT_PRODUCT_H__
#define __MATH_GEOMETRY_DOT_PRODUCT_H__

#include "Common/Common.h"

namespace DLS {
namespace Math {
namespace Geometry {

/*
  Find the dot product between the two vectors.
*/

template< typename Type >
const Type DotProduct(
  const Type x0,
  const Type y0,
  const Type z0,
  const Type x1,
  const Type y1,
  const Type z1 );

template< typename Type >
const Type DotProduct(
  const Type x0,
  const Type y0,
  const Type x1,
  const Type y1 );

} // namespace Geometry
} // namespace Math
} // namespace DLS

#include "Math/Geometry/DotProduct.inl"

#endif /* __MATH_GEOMETRY_DOT_PRODUCT_H__ */
