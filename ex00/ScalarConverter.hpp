#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>

enum literal_type
{
	error,
	_pseudo_literal,
	_char,
	_int,
	_float,
	_double,
};

class ScalarConverter
{
public:
	// point d'entrée principal
	static void convert(const std::string &str);

private:
	// Not instantiable by the users = constructor, destructor, copy constructor, and assignment operator private, so the class cannot be instantiated or copied.
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &);
	ScalarConverter &operator=(const ScalarConverter &);

	static literal_type getType(const std::string &str);
	static bool isChar(const std::string &str);
	static bool isInt(const std::string &str);
	static bool isFloat(const std::string &str);
	static bool isDouble(const std::string &str);
	static bool isPseudoLiteral(const std::string &str);

	static void charConversion(char c);
	static void intConversion(int i);
	static void floatConversion(float f);
	static void doubleConversion(double d);
	static void pseudoConversion(literal_type type, const std::string &str);
};

#endif
