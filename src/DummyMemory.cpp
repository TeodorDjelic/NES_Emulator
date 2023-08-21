#include "DummyMemory.hpp"

byte DummyMemory::read(word address) {
    return memory[address];
}
void DummyMemory::write(word address, byte data){
    memory[address] = data;
}