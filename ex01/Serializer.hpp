#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>
#include "Data.hpp"

/*
	POUR STOCKER 
	unintptr_t : unsigned integer type defined in the <cstdint> librairy
	large enough to hold pointer value w/t data loss
	used when you need to safely store a pointer as an integer
	==> allows conversion back and forth btwn pointer types and int types w/t altering data
*/

class Serializer
{
private:
	// Prevent instantiation and copying
	Serializer();
	Serializer(const Serializer &);
	Serializer &operator=(const Serializer &);
	~Serializer();

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};


#endif
