#include "NESConsole.hpp"
#include "DummyMemory.hpp"

NESConsole::NESConsole()
    : memory(std::make_shared<DummyMemory>()), cpu(memory){}

void NESConsole::powerUp(){

    memory->store(0xFFFD, 0x80);
    memory->store(0xFFFC, 0x00);

    cpu.powerUp();
}