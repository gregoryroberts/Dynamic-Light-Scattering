#ifndef __MATH_GEOMETRY_CROSS_PRODUCT_H__
#define __MATH_GEOMETRY_CROSS_PRODUCT_H__

#include "Common/Common.h"

namespace DLS {
namespace Math {
namespace Geometry {

/*
  Find the cross product between the two vectors.
*/

template< typename Type >
void CrossProduct(
  const Type x0,
  const Type y0,
  const Type z0,
  const Type x1,
  const Type y1,
  const Type z1,
  Type & x_cross,
  Type & y_cross,
  Type & z_cross );

} // namespace Geometry
} // namespace Math
} // namespace DLS

#include "Math/Geometry/CrossProduct.inl"

#endif /* __MATH_GEOMETRY_CROSS_PRODUCT_H__ */
