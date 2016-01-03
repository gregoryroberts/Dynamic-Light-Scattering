#ifndef __MATH_POINT_H__
#define __MATH_POINT_H__

#include "Common/Common.h"

namespace DLS {
namespace Math {

template< typename T >
struct Point2D {
    Point2D( T _x, T _y )
    : x( _x ),
    y( _y )
    {
        // empty
    }

    T x;
    T y;
};

template< typename T >
struct Point3D {
    Point3D( T _x, T _y, T _z)
    : x( _x ),
    y( _y ),
    z( _z )
    {
        // empty
    }

    T x;
    T y;
    T z;
};

} // namespace Math
} // namespace DLS

#endif /* __MATH_POINT_H__ */