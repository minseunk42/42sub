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
    private:
        Serializer();
        Serializer(Serializer const &ref);
        Serializer&  operator=(Serializer const &ref);
    public:
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};


#endif