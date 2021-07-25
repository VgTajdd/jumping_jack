// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// StringMethods.h                                                           //
// ========================================================================= //

#ifndef STRING_METHODS_H_
#define STRING_METHODS_H_

#include <string>

namespace univer::utils
{
class StringMethods
{
public:
	static int toInt( const std::string& str, bool* ok );
	static double toDouble( const std::string& str, bool* ok );
	static std::string number( int value );
	static std::string number( unsigned short value );
	static std::string number( unsigned int value );
	static std::string number( unsigned long long value );
	static std::string number( int64_t value );
	static std::string number( double value );
	static std::string number( float value, int precision );
	static std::string number( double value, int precision );
};
}

#endif