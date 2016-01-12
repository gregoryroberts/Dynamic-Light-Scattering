#ifndef __PHYSICS_CMOS_IMAGER_H__
#define __PHYSICS_CMOS_IMAGER_H__

#include "Common/Common.h"

namespace DLS {
namespace Physics {

/*
	Simulates a CMOS imaging device.  It has a bunch of cells,
	or pixels, that can accumulate intensity until the next shutter.
	Intensity is values are snapped to the nearest cell instead of
	divided out over all nearby cells.
*/

template<
	typename IntensityType, typename CoordinateType,
	size_t CellsPerColumn, size_t CellsPerRow >
class CMOSImager {

  public:

  	typedef IntensityType CellIntensityType;
  	typedef CoordinateType CellCoordinateType;
  	static constexpr size_t kCellsPerColumn = CellsPerColumn;
  	static constexpr size_t kCellsPerRow = CellsPerRow;
  	static constexpr size_t kTotalCells = kCellsPerColumn * kCellsPerRow;

	CMOSImager() = delete;
	CMOSImager(
		const CellCoordinateType resolution_x,
		const CellCoordinateType resolution_y );

	/*
		Access the cell intensity value at the given coordinates.
	*/
	CellIntensityType & operator()( const size_t cell_row, const size_t cell_column );
	const CellIntensityType operator()( const size_t cell_row, const size_t cell_column ) const;

	/*
		Simulates a camera shutter where cell values are reset
		so that they can accumulate again.
	*/
	void Shutter();
	/*
		Incident ray on the imager where the value accumulates
		in the most nearby cell.
	*/
	void IncidentRay(
		const CellCoordinateType x_coordinate,
		const CellCoordinateType y_coordinate,
		const CellIntensityType intensity );

  private:
  	/*
  		Laid out row-by-row.
  	*/
  	CellIntensityType cells_[ kTotalCells ];
  	CellCoordinateType resolution_x_;
  	CellCoordinateType resolution_y_;

};

} // namespace Physics
} // namespace DLS



#include "Physics/CMOSImager.inl"

#endif /* __PHYSICS_CMOS_IMAGER_H__ */