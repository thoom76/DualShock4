#ifndef MAIN_CPP_ZEROTYPE_H
#define MAIN_CPP_ZEROTYPE_H

#include <bitset>

template<unsigned int BitSize>
struct ZERO_BYTES{
    char __zero__[BitSize];
} __attribute__((packed));

#endif //MAIN_CPP_ZEROTYPE_H
