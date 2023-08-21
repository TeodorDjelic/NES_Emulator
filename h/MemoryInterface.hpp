#ifndef MemoryInterface_hpp
#define MemoryInterface_hpp

#include "MemoryUnits.h"

class MemoryInterface{
public:
    virtual byte read(word address) = 0;
    virtual void write(word address, byte data) = 0;
protected:
private:
};

#endif