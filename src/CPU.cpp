#include "CPU.hpp"

CPU::CPU(std::shared_ptr<MemoryInterface> _memory)
    : memory(_memory){}

void CPU::powerUp(){
    PSW.byte = 0x34;
    A = X = Y = 0;
    SP = 0xFD;

    PC = loadResetVector();

    /*memory->write(0x4017, 0x0);
    memory->write(0x4015, 0x0);
    for(int i = 0; i <= 0xF; i++)
        memory->write(0x4000 + i, 0x0);
    for(int i = 0; i <= 0x3; i++)
        memory->write(0x4010 + i, 0x0);*/

    /**
     * TODO: APU stuff
    */
}

word CPU::loadWord(word address){
    return ((word) memory->load(address + 1) << 8)
            + (word)memory->load(address);
}

void CPU::storeWord(word address, word data){
    memory->store(address, (byte)(data & 0x00FF));
    memory->store(address + 1, (byte)(data >> 8));
}

word CPU::loadNMIVector(){
    return loadWord(0xFFFA);
}

word CPU::loadResetVector(){
    return loadWord(0xFFFC);
}

word CPU::loadIRQBRKVector(){
    return loadWord(0xFFFE);
}

void CPU::setNMIVector(word address){
    storeWord(0xFFFA, address);
}

void CPU::setResetVector(word address){
    storeWord(0xFFFC, address);
}

void CPU::setIRQBRKVector(word address){
    storeWord(0xFFFE, address);
}