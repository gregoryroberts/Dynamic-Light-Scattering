#include "Common/Common.h"
#include "Utils/StringToNumber.h"

int main( int argc, char * argv[] )
{

	using namespace DLS;
	using namespace Utils;

	printf( "\n-------- StringToNumber --------\n\n" );

	std::string floating( "1.32123f" );
	float test_float = StringToFloatingType< float >( floating );
	double test_double = StringToFloatingType< double >( floating );

	std::string integral( "-123" );
	int test_int = StringToIntegralType< int >( integral );

	printf( "FLOATING:: %f, %f\n", test_float, test_double );
	printf( "INTEGRAL:: %d\n", test_int );

	DLS_ASSERT( test_float == 1.32123f, "Float Failure" );
	DLS_ASSERT( test_double == 1.32123, "Double Failure" );
	DLS_ASSERT( test_int == -123, "Integer Failure" );

	printf( "PASS\n" );

	printf( "\n-------- StringToNumber --------\n\n" );

}