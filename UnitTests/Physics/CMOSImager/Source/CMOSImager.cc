#include "Common/Common.h"
#include "Physics/CMOSImager.h"

int main( int argc, char * argv[] )
{

	using namespace DLS;
	using namespace Physics;

	printf( "\n-------- CMOSImager --------\n\n" );

	CMOSImager< double, double, 100, 100 > imager( 0.1, 0.1 );

	imager.Shutter();
	imager.IncidentRay( double( 5.32 ), double( 4.12 ), double( 5.0 ) );
	
	DLS_ASSERT( imager( 41, 53 ) == 5.0, "Intensity not properly accumulated" );

	imager.Shutter();

	DLS_ASSERT( imager( 41, 53 ) == 0.0, "Intensity not properly reset" );

	printf( "PASS\n" );

	printf( "\n-------- CMOSImager --------\n\n" );

}