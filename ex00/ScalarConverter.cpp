#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &str)
{
	switch (getType(str))
	{
	case _char:
		charConversion(str.at(0));
		break;
	case _int:
		intConversion(std::atoi(str.c_str()));
		break;
	case _float:
		if (isPseudoLiteral(str))
			pseudoConversion(_float, str);
		else
			floatConversion(std::strtof(str.c_str(), NULL)); // Fix here
		break;
	case _double:
		if (isPseudoLiteral(str))
			pseudoConversion(_double, str);
		else
			doubleConversion(std::strtod(str.c_str(), NULL)); // Fix here
		break;
	default:
		std::cout << "Type incorrect" << std::endl;
		break;
	}
}

literal_type ScalarConverter::getType(const std::string &str)
{
	if (isChar(str))
		return _char;
	if (isInt(str))
		return _int;
	if (isFloat(str))
		return _float;
	if (isDouble(str))
		return _double;
	return error;
}

bool ScalarConverter::isChar(const std::string &str)
{
	return str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]);
}

bool ScalarConverter::isInt(const std::string &str)
{
	char *end;
	long result = std::strtol(str.c_str(), &end, 10);
	return *end == '\0' && result >= std::numeric_limits<int>::min() && result <= std::numeric_limits<int>::max();
}

bool ScalarConverter::isFloat(const std::string &str)
{
	char *end;
	std::strtof(str.c_str(), &end);
	return *end == 'f' && end == str.c_str() + str.length() - 1;
}

bool ScalarConverter::isDouble(const std::string &str)
{
	char *end;
	std::strtod(str.c_str(), &end);
	return *end == '\0';
}

bool ScalarConverter::isPseudoLiteral(const std::string &str)
{
	return str == "nan" || str == "+inf" || str == "-inf" || str == "nanf" || str == "+inff" || str == "-inff";
}

void ScalarConverter::charConversion(char c)
{
	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}

void ScalarConverter::intConversion(int i)
{
	if (std::isprint(i))
		std::cout << "char: '" << static_cast<char>(i) << "'\n";
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f\n";
	std::cout << "double: " << static_cast<double>(i) << "\n";
}

void ScalarConverter::floatConversion(float f)
{
	if (std::isprint(static_cast<int>(f)))
		std::cout << "char: '" << static_cast<char>(f) << "'\n";
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << static_cast<int>(f) << "\n";
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
	std::cout << "double: " << static_cast<double>(f) << "\n";
}

void ScalarConverter::doubleConversion(double d)
{
	if (std::isprint(static_cast<int>(d)))
		std::cout << "char: '" << static_cast<char>(d) << "'\n";
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << static_cast<int>(d) << "\n";
	std::cout << "float: " << static_cast<float>(d) << "f\n";
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
}

void ScalarConverter::pseudoConversion(literal_type type, const std::string &str)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	if (type == _float)
	{
		std::cout << "float: " << str << "\n";
		std::cout << "double: " << str.substr(0, str.length() - 1) << "\n";
	}
	else if (type == _double)
	{
		std::cout << "float: " << str + "f" << "\n";
		std::cout << "double: " << str << "\n";
	}
}
