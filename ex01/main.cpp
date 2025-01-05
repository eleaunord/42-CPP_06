#include "Serializer.hpp"
#include "Data.hpp"
#include <cassert>

int main()
{
	// creating and initializing a Data instance (int, str, float)
	Data data = {42, "Example", 3.14f};

	// 1/ Serialize the Data pointer <=> converts the adress of the data object into a uintptr_t using reinterpret_cast
	uintptr_t serializedData = Serializer::serialize(&data);
	// serializedData <=> stores raw memory adress rpz data object

	// 2/ Deserialize back to a Data pointer <=> takes the serialized uintptr_t value and converts it back into a Data* pointer using reinterpret_cast
	Data *deserializedData = Serializer::deserialize(serializedData);

	// Step 3: Validate the deserialization result
	// if the comparaison fails asserts send an error
	assert(deserializedData == &data);
	assert(deserializedData->id == data.id);
	assert(deserializedData->name == data.name);
	assert(deserializedData->value == data.value);

	// Output results to verify correctness
	std::cout << "Serialization and Deserialization Test:\n";
	std::cout << "Original Data -> ID: " << data.id
			  << ", Name: " << data.name
			  << ", Value: " << data.value << '\n';
	std::cout << "Deserialized Data -> ID: " << deserializedData->id
			  << ", Name: " << deserializedData->name
			  << ", Value: " << deserializedData->value << '\n';
	return 0;
}

