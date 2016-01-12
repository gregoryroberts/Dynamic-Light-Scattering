#ifndef __MATH_COMPLEX_INL__
#define __MATH_COMPLEX_INL__

namespace DLS {
namespace Math {

template< typename Type >
DLS_INLINE ComplexRectangular< Type >::ComplexRectangular( Type real_part, Type imaginary_part )
: real_part_( real_part ),
imaginary_part_( imaginary_part )
{
	// empty
}

template< typename Type >
DLS_INLINE void ComplexRectangular< Type >::operator = ( const ComplexPolar< Type > & polar_form )
{
	this->real_part_ = magnitude_ * cos( angle_ );
	this->imaginary_part_ = magnitude_ * sin( angle_ );
}

template< typename Type >
DLS_INLINE Type & ComplexRectangular< Type >::Imaginary() {
	return imaginary_part_;
}

template< typename Type >
DLS_INLINE const Type & ComplexRectangular< Type >::Imaginary() const {
	return imaginary_part_;
}

template< typename Type >
DLS_INLINE Type & ComplexRectangular< Type >::Real() {
	return real_part_;
}

template< typename Type >
DLS_INLINE const Type & ComplexRectangular< Type >::Real() const {
	return real_part_;
}

template< typename Type >
DLS_INLINE ComplexPolar< Type >::ComplexPolar( Type magnitude, Type angle )
: magnitude_( magnitude ),
angle_( angle )
{
	// empty
}

template< typename Type >
DLS_INLINE void ComplexPolar< Type >::operator = ( const ComplexRectangular< Type > & rectangular_form )
{
	const Type real_part = rectangular_form.Real();
	const Type imaginary_part = rectangular_form.Imaginary();

	this->magnitude_ = sqrt( real_part * real_part + imaginary_part * imaginary_part );
	this->angle_ = atan2( imaginary_part, real_part );
}

template< typename Type >
DLS_INLINE Type & ComplexPolar< Type >::Angle() {
	return angle_;
}

template< typename Type >
DLS_INLINE const Type & ComplexPolar< Type >::Angle() const {
	return angle_;
}

template< typename Type >
DLS_INLINE Type & ComplexPolar< Type >::Magnitdue() {
	return magnitude_;
}

template< typename Type >
DLS_INLINE const Type & ComplexPolar< Type >::Magnitdue() const {
	return magnitude_;
}

} // namespace Math
} // namespace DLS

#endif /* __MATH_COMPLEX_INL__ */