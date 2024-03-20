#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

#include <stdint.h>

typedef struct s_Data
{
    int i;
    float f;
} Data;

class Serializer
{
    public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};


#endif