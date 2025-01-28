#include "ScalarConverter.hpp"

/*

Objectif : 
Approfondir la compréhension du casting de types en C++, en particulier les conversion de type explicites
Convertir une représentation sous forme de chaîne de caractères de différents types scalaires en leur types scalaires respectifs en c++ (char, int, float, double)

Méthodes statiques, classes non instanciables (méthodes statiques et constructeur supprimé/privé)

*/

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return 1;
	}

	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
