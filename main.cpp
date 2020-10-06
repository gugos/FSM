#include "machine.h"

int main()
{
    Machine machine;
    machine.handleState1();
    machine.handleState1();
    machine.handleState3();
    machine.handleState2();
    machine.handleState1();
    machine.handleState2();
    machine.handleState3();
    machine.handleState2();
    machine.handleState1();

    return 0;
}

