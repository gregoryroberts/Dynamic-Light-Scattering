#include "Common/Status.h"
#include "Laser.h"
#include "ParticleBox.h"
#include "Utils/ReadFile.h"

int main( int argc, char * argv[] )
{

	printf( "Hello, Dynamic Light Scattering\n" );

	// todo: need to fix the path problem. maybe the
	// best way to do it is to have the path be passed to the data
	// folder be passed in as an argument to the program
	std::string filename( "Data/test.out" );
	std::vector< double > values;

	const Status read_status = ReadFile( filename, values );

	for ( size_t v = 0; v < values.size(); ++v ) {
		printf( "The next value is %.30f\n", values[ v ] );
	}

	printf("The result of the reading was a %s\n",
		read_status == Status::Success ? "success" : "failure");


}
