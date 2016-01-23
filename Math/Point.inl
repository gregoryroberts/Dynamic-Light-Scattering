#ifndef __MATH_POINT_INL__
#define __MATH_POINT_INL__

namespace DLS {
namespace Math {

template< typename Type >
DLS_INLINE Point2D< Type >::Point2D()
: x( Type( 0 ) ),
y( Type( 0) ) 
{
    // empty
}

template< typename Type >
DLS_INLINE Point2D< Type >::Point2D( Type _x, Type _y )
: x( _x ),
y( _y )
{
    // empty
}


template< typename Type >
DLS_INLINE Point3D< Type >::Point3D()
: x( Type( 0 ) ),
y( Type( 0 ) ),
z( Type( 0 ) )
{
    // empty
}

    
template< typename Type >
DLS_INLINE Point3D< Type >::Point3D( Type _x, Type _y, Type _z)
: x( _x ),
y( _y ),
z( _z )
{
    // empty
}

} // namespace Math
} // namespace DLS

#endif /* __MATH_POINT_INL__ */
