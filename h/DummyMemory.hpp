#ifndef DummyMemory_hpp
#define DummyMemory_hpp

#include "MemoryInterface.hpp"

class DummyMemory : public MemoryInterface{
public:
    virtual byte read(word address) override;
    virtual void write(word address, byte data) override;
protected:
private:
    byte memory[MEM_SIZE];
};

#endif