#ifndef __UTILS_STRING_TO_NUMBER_INL__
#define __UTILS_STRING_TO_NUMBER_INL__

// specifically for integral types
template< typename ValueType >
typename std::enable_if< std::is_integral< ValueType >::value >::type
StringToNumber( const std::string & input_string )
{
	return static_cast< ValueType >( std::stoi( input_string ) );
}

// for floating point values (generic version, non-integral type)
template< typename ValueType >
ValueType StringToNumber( const std::string & input_string )
{
	return static_cast< ValueType >( std::stod( input_string ) );	
}

#endif /* __UTILS_STRING_TO_NUMBER_INL__ */