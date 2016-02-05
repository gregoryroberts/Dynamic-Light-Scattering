#include "Common/Common.h"
#include "Math/Constant.h"
#include "Math/Geometry/PlaneAngle.h"

int main( int argc, char * argv[] )
{
	using namespace DLS;
	using namespace Math;
	using namespace Geometry;

	printf( "\n-------- PlaneAngle --------\n\n" );

	double p0[ 3 ] = { 0.0, 0.0, 3.0 };
	double p1[ 3 ] = { 2.0, 2.0, 3.0 };
	double p2[ 3 ] = { 2.0, 0.0, 3.0 };

	double angle = PlaneAngleRadians(
		p0[ 0 ], p0[ 1 ], p0[ 2 ],
		p1[ 0 ], p1[ 1 ], p1[ 2 ],
		p2[ 0 ], p2[ 1 ], p2[ 2 ] );

	constexpr double kAngleExpected = Constant::kPi - Constant::kPi / 4;

	const double error = fabs( angle - kAngleExpected );

	DLS_ASSERT( error < 0.01, "Angle is not correct" );

	constexpr double kXShift = 1.0;
	constexpr double kYShift = -1.5;

	double angle_shift = PlaneAngleRadians(
		p0[ 0 ] + kXShift, p0[ 1 ] + kYShift, p0[ 2 ],
		p1[ 0 ] + kXShift, p1[ 1 ] + kYShift, p1[ 2 ],
		p2[ 0 ] + kXShift, p2[ 1 ] + kYShift, p2[ 2 ] );

	// the shifting should not affect the angle
	constexpr double kAngleExpectedShift = kAngleExpected;

	const double error_shift = fabs( angle_shift - kAngleExpectedShift );

	DLS_ASSERT( error_shift < 0.01, "Angle is not correct" );

	printf( "PASS\n" );

	printf( "\n-------- PlaneAngle --------\n\n" );

}