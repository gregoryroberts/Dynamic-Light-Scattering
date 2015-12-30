#ifndef __MATH_COMPLEX_INL__
#define __MATH_COMPLEX_INL__

#include <cmath>

template< typename Type >
ComplexRectangular< Type >::ComplexRectangular( Type real_part, Type imaginary_part )
: real_part_( real_part ),
imaginary_part_( imaginary_part )
{
	// empty
}

template< typename Type >
void ComplexRectangular< Type >::operator = ( const ComplexPolar< Type > & polar_form )
{

}


template< typename Type >
ComplexPolar< Type >::ComplexPolar( Type magnitude, Type angle )
: magnitude_( magnitude ),
angle_( angle )
{
	// empty
}

template< typename Type >
void ComplexPolar< Type >::operator = ( const ComplexRectangular< Type > & rectangular_form )
{
	const Type real_part = rectangular_form.Real();
	const Type imag_part = rectangular_form.Imaginary();
}

#endif /* __MATH_COMPLEX_INL__ */