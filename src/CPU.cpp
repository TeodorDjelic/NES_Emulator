#include <iostream>
#include "CPU.hpp"
#include "test.h"

void CPU::init(){
    std::cout << "Hey!\n";
}

int main(){

    CPU cpu;

    cpu.init();    

    f(10);

    return 0;
}