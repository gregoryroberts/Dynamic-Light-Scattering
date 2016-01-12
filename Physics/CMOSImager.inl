#ifndef __PHYSICS_CMOS_IMAGER_INL__
#define __PHYSICS_CMOS_IMAGER_INL__

namespace DLS {
namespace Physics {
namespace Internal {

/*
	Returns the location in the grid closest to the value
	(i.e. - discretizes the value)
*/
template< typename Type >
DLS_INLINE Type SnapToGrid( const Type value, const Type granularity )
{
	const Type lower_value = granularity * floor( value / granularity );
	const Type value_to_lower_value = value - lower_value;

	const Type granularity_by_two = 0.5 * granularity;

	return value_to_lower_value > granularity_by_two ?
		lower_value + granularity :
		lower_value;
}

} // namespace Internal

template<
	typename IntensityType, typename CoordinateType,
	size_t CellsPerRow, size_t CellsPerColumn >
DLS_INLINE CMOSImager< IntensityType, CoordinateType, CellsPerRow, CellsPerColumn >::CMOSImager(
	const CoordinateType resolution_x, const CoordinateType resolution_y )
: resolution_x_( resolution_x ),
resolution_y_( resolution_y )
{
	this->Shutter();
}

template<
	typename IntensityType, typename CoordinateType,
	size_t CellsPerRow, size_t CellsPerColumn >
DLS_INLINE IntensityType & CMOSImager< IntensityType, CoordinateType, CellsPerRow, CellsPerColumn >::operator()(
	const size_t cell_row, const size_t cell_column )
{
	DLS_ASSERT( cell_row < kCellsPerColumn, "Requested cell row is invalid");
	DLS_ASSERT( cell_column < kCellsPerRow, "Requested cell column is invalid");
	
	return cells_[ cell_row * kCellsPerColumn + cell_column ];
}


template<
	typename IntensityType, typename CoordinateType,
	size_t CellsPerRow, size_t CellsPerColumn >
DLS_INLINE const IntensityType CMOSImager< IntensityType, CoordinateType, CellsPerRow, CellsPerColumn >::operator()(
	const size_t cell_row, const size_t cell_column ) const
{
	DLS_ASSERT( cell_row < kCellsPerColumn, "Requested cell row is invalid");
	DLS_ASSERT( cell_column < kCellsPerRow, "Requested cell column is invalid");
	
	return cells_[ cell_row * kCellsPerColumn + cell_column ];
}

template<
	typename IntensityType, typename CoordinateType,
	size_t CellsPerRow, size_t CellsPerColumn >
DLS_INLINE void CMOSImager< IntensityType, CoordinateType, CellsPerRow, CellsPerColumn >::Shutter()
{
	memset( cells_, CellIntensityType( 0 ), kTotalCells * sizeof( CellIntensityType ) );
}

template<
	typename IntensityType, typename CoordinateType,
	size_t CellsPerRow, size_t CellsPerColumn >
DLS_INLINE void CMOSImager< IntensityType, CoordinateType, CellsPerRow, CellsPerColumn >::IncidentRay(
	const CoordinateType x_coordinate,
	const CoordinateType y_coordinate,
	const IntensityType intensity )
{
	const CoordinateType x_coordinate_grid = Internal::SnapToGrid( x_coordinate, resolution_x_ );
	const CoordinateType y_coordinate_grid = Internal::SnapToGrid( y_coordinate, resolution_y_ );

	const size_t x_cell_location = static_cast< size_t >( x_coordinate_grid / resolution_x_ );
	const size_t y_cell_location = static_cast< size_t >( y_coordinate_grid / resolution_y_ );

	if ( ( x_cell_location > kCellsPerRow ) || ( y_cell_location > kCellsPerColumn ) ) {
		// the incident ray isn't inside of the imaging element
		return;
	}

	cells_[ y_cell_location * kCellsPerRow + x_cell_location ] += intensity;

}

} // namespace Physics
} // namespace DLS




#endif /* __PHYSICS_CMOS_IMAGER_INL__ */
