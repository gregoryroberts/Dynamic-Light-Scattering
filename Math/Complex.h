#ifndef __MATH_COMPLEX_H__
#define __MATH_COMPLEX_H__

#include "Common/Common.h"

namespace DLS {
namespace Math {

/* Forward declarations */
template< typename Type >
struct ComplexRectangular;

template< typename Type >
struct ComplexPolar;

template< typename Type >
struct ComplexRectangular {

  typedef Type ValueType;

  ComplexRectangular() = default;
  ComplexRectangular( Type real_part, Type imaginary_part );

  void operator = ( const ComplexPolar< ValueType > & polar_form );

  Type &          Imaginary();
  const Type &    Imaginary() const;
  Type &          Real();
  const Type &    Real() const;

  private:
    Type real_part_;
    Type imaginary_part_;

};

template< typename Type >
struct ComplexPolar {

  typedef Type ValueType;

  ComplexPolar() = default;
  ComplexPolar( Type magnitude, Type angle );

  void operator = ( const ComplexRectangular< ValueType > & rectangular_form );

  Type &        Angle();
  const Type &  Angle() const;
  Type &        Magnitude();
  const Type &  Magnitude() const;

  private:
    Type magnitude_;
    Type angle_;

};

} // namespace Math
} // namespace DLS

#include "Math/Complex.inl"

#endif /* __MATH_COMPLEX_H__ */