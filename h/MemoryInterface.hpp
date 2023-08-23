#ifndef MemoryInterface_hpp
#define MemoryInterface_hpp

#include "MemoryUnits.h"

class MemoryInterface{
public:
    virtual byte load(word address) = 0;
    virtual void store(word address, byte data) = 0;
protected:
private:
};

#endif