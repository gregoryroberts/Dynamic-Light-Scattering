#ifndef __UTILS_READ_FILE_H__
#define __UTILS_READ_FILE_H__

#include "Common/Status.h"

#include <string>

/*
	Reads the values from the file into the given std::vector
	container.  It returns a Failure Status if something goes wrong
	with the operation (i.e. - the filename doesn't exist for example).
	It will also return a failure if it doesn't find any of the specified
	value type in the file.

	This operation does not clear the input vector.  It assumes you have
	passed an empty vector in to be filled up or that you want to append
	new values on the end of the vector that was passed into the function.
*/

template< typename ValueType >
Status ReadFile( const std::string & filename, std::vector< ValueType > & values );

#include "Utils/ReadFile.inl"

#endif /* __UTILS_READ_FILE_H__ */