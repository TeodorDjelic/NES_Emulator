#ifndef PIC_h
#define PIC_h

#include "MemoryUnits.h"

class PIC{
public:
    PIC(word _startAddress, word _endAddress);
    virtual byte read(word address) const = 0;
    virtual void write(word address, byte data) = 0;
protected:
private:
    word startAddress;
    word endAddress;
};

#endif