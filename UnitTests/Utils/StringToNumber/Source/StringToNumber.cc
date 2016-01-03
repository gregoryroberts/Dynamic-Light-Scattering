#include "Utils/StringToNumber.h"

int main( int argc, char * argv[] )
{

	printf( "\n-------- StringToNumber --------\n\n" );

	std::string floating( "1.32123f" );
	float test_float = StringToFloatingType< float >( floating );
	double test_double = StringToFloatingType< double >( floating );

	std::string integral( "-123" );
	int test_int = StringToIntegralType< int >( integral );


	printf( "FLOATING:: %f, %f\n", test_float, test_double );
	printf( "INTEGRAL:: %d\n", test_int );

	printf( "\n\n-------- StringToNumber --------\n\n" );

}