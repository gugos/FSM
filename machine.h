#ifndef MACHINE_H
#define MACHINE_H

#include "state.h"
#include "context.h"

#include <iostream>

class State1 : public State {
    void handle1() override;
    void handle2() override;
    void handle3() override;
};

class State2 : public State {
    void handle1() override;
    void handle2() override;
    void handle3() override;
};

class State3 : public State {
    void handle1() override;
    void handle2() override;
    void handle3() override;
};

class Machine {
private:
    Context fsm;
    State1* state1;
    State2* state2;
    State3* state3;

public:
    Machine() : fsm(*this) {
        state1 = new State1;
        state2 = new State2;
        state3 = new State3;
        fsm.transitionTo(state1);
    }

    ~Machine() {
        delete state1;
        delete state2;
        delete state3;
    }

    State* getState1() { return state1; }
    State* getState2() { return state2; }
    State* getState3() { return state3; }

    void handleState1() {
        fsm.handleState1();
    }

    void handleState2() {
        fsm.handleState2();
    }

    void handleState3() {
        fsm.handleState3();
    }
};

void State1::handle1() { std::cout << "Handled State1. Switching to State2.\n"; this->context->transitionTo(this->context->getOwner().getState2()); }
void State1::handle2() { std::cout << "Can't handle2, at State1.\n"; }
void State1::handle3() { std::cout << "Can't handle3, at State1.\n"; }

void State2::handle1() { std::cout << "Can't handle1, at State2.\n"; }
void State2::handle2() { std::cout << "Handled State2. Switching to State3.\n"; this->context->transitionTo(this->context->getOwner().getState3()); }
void State2::handle3() { std::cout << "Can't handle3, at State2.\n"; }

void State3::handle1() { std::cout << "Can't handle1, at State3.\n"; }
void State3::handle2() { std::cout << "Can't handle2, at State3.\n"; }
void State3::handle3() { std::cout << "Handled State3. Switching to State1.\n"; this->context->transitionTo(this->context->getOwner().getState1()); }

#endif // MACHINE_H

