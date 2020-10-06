#ifndef STATE_H
#define STATE_H

class Context;

class State {
protected:
    Context* context;

public:
    virtual ~State() {}

    void setContext(Context* context) {
        this->context = context;
    }

    virtual void handle1() = 0;
    virtual void handle2() = 0;
    virtual void handle3() = 0;
};

#endif // STATE_H

