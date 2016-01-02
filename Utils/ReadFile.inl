#ifndef __UTILS_READ_FILE_INL__
#define __UTILS_READ_FILE_INL__

#include "Utils/StringToNumber.h"

#include <fstream>
#include <stdlib.h>

// todo: get some namespaces in here for readability and
// organization (especially if you have sub-folders like this)

template< typename ValueType >
Status ReadFile( const std::string & filename, std::vector< ValueType > & values )
{
	std::ifstream input_file( filename );

	if ( !input_file.is_open() ) {
		return Status::Failure;
	}

	std::string next_number_as_string;
	size_t parsed_values = 0u;

	while ( std::getline( input_file, next_number_as_string ) ) {
		values.push_back( StringToNumber< ValueType >( next_number_as_string ) );
		++parsed_values;
	}

	if ( parsed_values == 0u ) {
		return Status::Failure;
	} else {
		return Status::Success;
	}
}

#endif /* __UTILS_READ_FILE_INL__ */