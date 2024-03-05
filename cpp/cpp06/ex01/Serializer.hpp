#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif