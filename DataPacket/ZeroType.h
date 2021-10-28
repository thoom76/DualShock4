#ifndef MAIN_CPP_ZEROTYPE_H
#define MAIN_CPP_ZEROTYPE_H

template<unsigned int BitSize>
struct ZERO{
    unsigned long long __zero__ : BitSize;

    operator std::string() const{
        return std::bitset<BitSize>(__zero__).to_string();
    }
} __attribute__((packed));

#endif //MAIN_CPP_ZEROTYPE_H
