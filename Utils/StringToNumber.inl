#ifndef __UTILS_STRING_TO_NUMBER_INL__
#define __UTILS_STRING_TO_NUMBER_INL__

// specifically for integral types
template< typename IntegralType >
IntegralType StringToIntegralType( const std::string & input_string )
{
	return static_cast< IntegralType >( std::stoi( input_string ) );
}

// for floating point values
template< typename FloatingType >
FloatingType StringToFloatingType( const std::string & input_string )
{
	return static_cast< FloatingType >( std::stod( input_string ) );	
}

#endif /* __UTILS_STRING_TO_NUMBER_INL__ */