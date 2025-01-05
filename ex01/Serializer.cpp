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

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}