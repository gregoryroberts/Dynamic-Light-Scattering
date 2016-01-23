#ifndef __MATH_POINT_H__
#define __MATH_POINT_H__

#include "Common/Common.h"

namespace DLS {
namespace Math {

template< typename Type >
struct Point2D {

    /* Constructors */
    Point2D();
    Point2D( Type _x, Type _y );

    Type x;
    Type y;
};

template< typename Type >
struct Point3D {

    /* Constructors */
    Point3D();
    Point3D( Type _x, Type _y, Type _z);

    Type x;
    Type y;
    Type z;
};

} // namespace Math
} // namespace DLS

#include "Math/Point.inl"

#endif /* __MATH_POINT_H__ */
