#ifndef OBSERVER_H
#define OBSERVER_H
#include "Item/itemfinal.h"
class Observer{
public:
    Observer();
    virtual void updade(int caso, ItemFinal* itf, float pIB, float pIE) = 0;
};

#endif // OBSERVER_H
