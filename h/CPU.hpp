#ifndef CPU_hpp
#define CPU_hpp

#include <memory>
#include "MemoryUnits.h"
#include "MemoryInterface.hpp"

class CPU{
public:
    CPU(std::shared_ptr<MemoryInterface>);
    void powerUp();
protected:
private:
    byte A;
    byte X, Y;
    union{
        struct{
            byte C:1;
            byte Z:1;
            byte I:1;
            byte D:1;
            byte B:1;
            byte R:1;
            byte V:1;
            byte N:1;
        } bits;
        byte byte;
    } PSW;
    byte SP;
    word PC;

    std::shared_ptr<MemoryInterface> memory;
};

#endif