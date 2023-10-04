#include <iostream>
#include "Serializer.hpp"

int main() {
    Data* data = new Data();
    std::cout << "data address: " << data << std::endl;
    std::cout << "data: " << data->getData() << std::endl;
    
    uintptr_t raw = Serializer::serialize(data);
    std::cout << "raw: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "deserializedData address: " << deserializedData << std::endl;
    std::cout << "deserializedData: " << deserializedData->getData() << std::endl;

    delete data;
    return (0);
}