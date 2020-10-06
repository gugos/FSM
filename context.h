#ifndef CONTEXT_H
#define CONTEXT_H

class State;
class Machine;

class Context {
private:
    Machine& owner;
    State* state;

public:
    Context(Machine& owner) : owner(owner), state(nullptr) {}

    void transitionTo(State* state) {
        this->state = state;
        this->state->setContext(this);
    }

    State* getState() {
        return state;
    }

    Machine& getOwner() {
        return owner;
    }

    void handleState1() {
        state->handle1();
    }

    void handleState2() {
        state->handle2();
    }

    void handleState3() {
        state->handle3();
    }
};

#endif // CONTEXT_H

