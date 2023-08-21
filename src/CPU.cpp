#include "CPU.hpp"

CPU::CPU(std::shared_ptr<MemoryInterface> _memory)
    : memory(_memory){}

void CPU::powerUp(){
    PSW.byte = 0x34;
    A = X = Y = 0;
    SP = 0xFD;
    memory->write(0x4017, 0x0);
    memory->write(0x4015, 0x0);
    for(int i = 0; i <= 0xF; i++)
        memory->write(0x4000 + i, 0x0);
    for(int i = 0; i <= 0x3; i++)
        memory->write(0x4010 + i, 0x0);

    /**
     * TODO: APU stuff
    */
}