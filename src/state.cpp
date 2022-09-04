#include <iostream>
#include <string>

using namespace std;
class Context;

class State {
public:
    virtual void doAction(Context* context) = 0;
    virtual string toString() = 0;
    virtual ~State() {};
};

class Context {
public:
    Context() {
        _state = nullptr;
    }

    State* getState() {
        return _state;
        
    }

    void setState(State* state) {
        _state = state;
    }

    ~Context() {
        if (_state != nullptr) {
            delete _state;
            _state = nullptr;
        }  
    }
private:
    State* _state;
};

class StartState: public State {
public:
    void doAction(Context* context) override {
        cout << "This is StartState." << endl;
        context->setState(this);
    }

    string toString() {
        return "Start State.";
    }
};

class StopState: public State {
public:
    void doAction(Context* context) override {
        cout << "This is StopState." << endl;
        context->setState(this);
    }

    string toString() override {
        return "Stop State.";
    }
};

int main() {
    
    StartState* startState = new StartState;
    Context* context = new Context;
    startState->doAction(context);
    cout << context->getState()->toString() << endl;

    StopState stopState;
    stopState.doAction(context);
    cout << context->getState()->toString() << endl;

    delete context;
    context = nullptr;

    system("pause");
    return 0;
}