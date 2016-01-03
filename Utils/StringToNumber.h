#ifndef __UTILS_STRING_TO_NUMBER_H__
#define __UTILS_STRING_TO_NUMBER_H__

#include <string>

template< typename IntegralType >
IntegralType StringToIntegralType( const std::string & input_string );

template< typename FloatingType >
FloatingType StringToFloatingType( const std::string & input_string );

#include "Utils/StringToNumber.inl"

#endif /* __UTILS_STRING_TO_NUMBER_H__ */