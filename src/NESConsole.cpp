#include "NESConsole.hpp"
#include "DummyMemory.hpp"

NESConsole::NESConsole()
    : memory(std::make_shared<DummyMemory>()), cpu(memory){}

void NESConsole::powerUp(){
    cpu.powerUp();
}