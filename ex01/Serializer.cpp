#include "Serializer.hpp"
#include "Data.hpp"

/*
	POUR CONVERTIR
	reinterpret_cast : cast operator used to convert one pointer type to another
*/

Serializer::Serializer()
{

}
Serializer::Serializer(const Serializer &)
{

}
Serializer &Serializer::operator=(const Serializer &)
{
	return *this;
}

Serializer::~Serializer()
{

}

// Serialization : on convertit un pointer en uintptr_t
uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

// Désérialization : convertit un uintptr_t en pointer
Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}