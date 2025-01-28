#include "functions.hpp"

/*

Polymorphisme, cast dynamiques, utilisation références/pointeurs dans fonctions

Créer une instance aléatoire de A, B ou C et la retourner en tant que pointeur de type Base*
*/

int main()
{
	srand(time(0)); // use to init the PRNG (pseudorandom num generator)
	// give the current time since Unix epoch
	// => current time keeps changing so different seed ("valeur d'initialisation") each time the program runs
	// sequence of numbers generated different each time the program is executed
	// ow we'll have the same sequence everytime we run the program

	// Generate and identify types multiple times
	for (int i = 0; i < 5; ++i)
	{
		Base *obj = generate(); // random object
		std::cout << "Identifying with pointer: ";
		identify(obj);			// id type using pointer
		std::cout << "Identifying with reference: ";
		identify(*obj);			// id type using ref
		delete obj;				// clean up dynamically alloc memory
		std::cout << std::endl;
	}

	return 0;
}
