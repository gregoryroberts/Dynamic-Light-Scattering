#ifndef __UTILS_STRING_TO_NUMBER_H__
#define __UTILS_STRING_TO_NUMBER_H__

#include "Common/Common.h"

namespace DLS {
namespace Utils {

template< typename IntegralType >
IntegralType StringToIntegralType( const std::string & input_string );

template< typename FloatingType >
FloatingType StringToFloatingType( const std::string & input_string );

} // namespace Utils
} // namespace DLS

#include "Utils/StringToNumber.inl"

#endif /* __UTILS_STRING_TO_NUMBER_H__ */
