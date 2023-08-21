#ifndef NESConsole_hpp
#define NESConsole_hpp

#include "CPU.hpp"

class NESConsole{
public:
    NESConsole();
    void powerUp();
protected:
private:
    std::shared_ptr<MemoryInterface> memory;
    CPU cpu;
};

#endif