#include "Common/Common.h"
#include "Math/Constant.h"
#include "Math/Geometry/PlaneAngle.h"

int main( int argc, char * argv[] )
{
	using namespace DLS;
	using namespace Math;
	using namespace Geometry;

	printf( "\n-------- PlaneAngle --------\n\n" );

	float p0[ 3 ] = { 0.0, 0.0, 3.0 };
	float p1[ 3 ] = { 2.0, 2.0, 3.0 };
	float p2[ 3 ] = { 2.0, 0.0, 3.0 };

	float angle = PlaneAngleRadians(
		p0[ 0 ], p0[ 1 ], p0[ 2 ],
		p1[ 0 ], p1[ 1 ], p1[ 2 ],
		p2[ 0 ], p2[ 1 ], p2[ 2 ] );

	constexpr float kAngleExpected = Constant::kPi - Constant::kPi / 4;

	const float error = fabs( angle - kAngleExpected );

	DLS_ASSERT( error < 0.01, "Angle is not correct" );

	constexpr float kXShift = 1.0;
	constexpr float kYShift = -1.5;

	float angle_shift = PlaneAngleRadians(
		p0[ 0 ] + kXShift, p0[ 1 ] + kYShift, p0[ 2 ],
		p1[ 0 ] + kXShift, p1[ 1 ] + kYShift, p1[ 2 ],
		p2[ 0 ] + kXShift, p2[ 1 ] + kYShift, p2[ 2 ] );

	// the shifting should not affect the angle
	constexpr float kAngleExpectedShift = kAngleExpected;

	const float error_shift = fabs( angle_shift - kAngleExpectedShift );

	DLS_ASSERT( error_shift < 0.01, "Angle is not correct" );

	printf( "PASS\n" );

	printf( "\n-------- PlaneAngle --------\n\n" );

}