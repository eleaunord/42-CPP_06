#include "functions.hpp"


// rand() for a random number generator
Base* generate()
{
	int random;

	random = std::rand() % 3; // random number btwn 0 and 2 (A, B, C)
	// std::rand() generates a random number: Using the seed set by srand, it produces the next number in the sequence, combined with % 3, you get a random number in the range [0, 2].
	if (random == 0)
	{
		std::cout << "generating A" << std::endl;
		return new A();
	}
	else if (random == 1)
	{
		std::cout << "generating B" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "generating C" << std::endl;
		return new C();
	}
}
/*

dynamic_cast => allows us to convert a pointer/ref of a base class to a derived class
if the cast is not possible :
	- for pointers : returns NULL
	- for references : throws a std::bad_cast exception
Base = polymorphic base class (+ we need a virtual function in the base class to use dynamic_cast)
A, B, C = derived classes

check au moment de l'exec si la conversion d'un objet d'un type de base à un type dérivé est valide
Runtime Type Identification (RTTI) = permet de connaitre le type réel d'un object au moment de l'exec = essentiel pr que le dynamic_cast fonctionne
*/

// a pointer to Base => use dynamic_cast to attempt downcasting to A*, B*, C*
// => for situations where the object can be NULL == don't know if the pointer is valid (dynamic alloc, external input)
void identify(Base* p)
{
	if (p == NULL)
	{
		std::cout << "null pointer given" << std::endl;
		return;
	}
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "type id by pointer : A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "type id by pointer : B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "type id by pointer : C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

// a reference to Base => use dynamic_cast to attempt downcasting to A&, B&, C&
// => when we are sure the object CANNOT be Null == enforces the caller to provide a valid object (safer but more strict)
// !! exceptions not allowed in this exo

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "type id by reference : A" << std::endl;
		return;
	}
	catch (const std::exception &) {} // Catch all standard exceptions

	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "type id by reference : B" << std::endl;
		return;
	}
	catch (const std::exception &) {}

	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "type id by reference : C" << std::endl;
		return;
	}
	catch (const std::exception &) {}

	std::cout << "unknown type" << std::endl;
}

