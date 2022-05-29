#ifndef MAIN_CPP_FINGERTYPE_H
#define MAIN_CPP_FINGERTYPE_H

struct Finger{
    unsigned int fingerId               : 7;
    bool         fingerActive           : 1;    // Active low
    unsigned int fingerCoordinates1     : 12,
                 fingerCoordinates2     : 12;
} __attribute__((packed));

#endif //MAIN_CPP_FINGERTYPE_H
