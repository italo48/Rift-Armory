#ifndef SUBJECT_H
#define SUBJECT_H
#include "observer.h"
#include <vector>
class Subject{
public:
    Subject();
    virtual void attach(Observer *o){
        observers.push_back(o);
    }
    virtual void detach(Observer *o){
        for(int i = 0; i < (int)observers.size(); i++){
            if(observers[i] == o)
                observers.erase(observers.begin() + i);
        }
    }
    virtual void notify(int caso, ItemFinal* itf, float pIB, float pIE){
        for(Observer* o : observers)
            o->updade(caso, itf, pIB, pIE);
    }

private:
    std::vector<Observer*> observers;
};

#endif // SUBJECT_H
