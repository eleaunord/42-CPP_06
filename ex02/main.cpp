#include "functions.hpp"

/*

Polymorphisme, cast dynamiques, utilisation références/pointeurs dans fonctions

Créer une instance aléatoire de A, B ou C et la retourner en tant que pointeur de type Base*
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.hpp"

int main()
{
    srand(time(0)); // Initialize PRNG with the current time

    // Generate and identify types multiple times
    for (int i = 0; i < 5; ++i)
    {
        Base *obj = generate(); // Generate a random object
        std::cout << "Identifying with pointer: ";
        identify(obj); // Identify type using pointer
        std::cout << "Identifying with reference: ";
        identify(*obj); // Identify type using reference
        delete obj; // Clean up dynamically allocated memory
        std::cout << std::endl;
    }


    // 1. null pointer
    Base *nullPointer = nullptr;
    std::cout << "Identifying with a null pointer: ";
    identify(nullPointer); // Should print "null pointer given"

    // 2. reference to NULL 
    try
    {
        Base *nullRef = nullptr;
        std::cout << "Identifying with a null reference: ";
        identify(*nullRef); // Undefined behavior: this would normally crash
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // 3. pointer to an invalid object (not derived from Base)
    try
    {
        class D {}; 
        D d;
        Base *invalidBase = reinterpret_cast<Base *>(&d); 
        std::cout << "Identifying with a pointer to an unrelated object: ";
        identify(invalidBase); 
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught during invalid pointer handling: " << e.what() << std::endl;
    }

    // 4. stack-allocated Base object
    try
    {
        Base baseObject; 
        std::cout << "Identifying a Base object directly: ";
        identify(&baseObject);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught during Base object identification: " << e.what() << std::endl;
    }

    return 0;
}
