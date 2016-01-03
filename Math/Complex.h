#ifndef __MATH_COMPLEX_H__
#define __MATH_COMPLEX_H__

#include "Common/Common.h"

template< typename Type >
struct ComplexRectangular {

  typedef Type ValueType;

  ComplexRectangular() = default;
  ComplexRectangular( Type real_part, Type imaginary_part );

  void operator = ( const ComplexPolar< ValueType > & polar_form );

  Type Real();
  Type Imaginary();

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

  Type Magnitude();
  Type Angle();

  private:
    Type magnitude_;
    Type angle_;

};


#include "Math/Complex.inl"

#endif /* __MATH_COMPLEX_H__ */