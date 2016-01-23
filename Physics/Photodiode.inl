#ifndef __PHYSICS_PHOTODIODE_INL__
#define __PHYSICS_PHOTODIODE_INL__

namespace DLS {
namespace Physics {

template< typename IntensityType >
DLS_INLINE Photodiode< IntensityType >::Photodiode()
: accumulated_intensity_( IntensityType( 0 ) )
{
	// empty
}

template< typename IntensityType >
DLS_INLINE const IntensityType Photodiode< IntensityType >::AccumulatedIntensity() const
{
	return accumulated_intensity_;
}

template< typename IntensityType >
DLS_INLINE IntensityType & Photodiode< IntensityType >::AccumulatedIntensity()
{
	return accumulated_intensity_;
}

template< typename IntensityType >
DLS_INLINE const IntensityType Photodiode< IntensityType >::Drain()
{
	const IntensityType intensity = accumulated_intensity_;
	accumulated_intensity_ = IntensityType( 0 );
	return intensity;
}

template< typename IntensityType >
DLS_INLINE void Photodiode< IntensityType >::IncidentRay( const IntensityType ray_intensity )
{
	accumulated_intensity_ += ray_intensity;
}

} // namespace Physics
} // namespace DLS




#endif /* __PHYSICS_PHOTODIODE_INL__ */
