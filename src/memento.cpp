#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Memento {
public:
    Memento(string state) {
        _state = state;
    }
    string getState() {
        return _state;
    }
private:
    string _state;
};

class Originator {
public:
    void setState(string state) {
        _state = state;
    }

    string getState() {
        return _state;
    }

    Memento saveStateToMemento() {
        Memento mem(_state);
        return mem;
    }

    void getStateFromMemento(Memento mem) {
        _state = mem.getState();
    }

private:
    string _state;
};

class CareTaker {
public:
    void add(const Memento& memento) {
        _mementoVec.emplace_back(memento);
    }

    Memento get(int idx) {
        return _mementoVec[idx];
    }

    ~CareTaker() {
        _mementoVec.clear();
    }
private:
    vector<Memento> _mementoVec;
};


int main() {
    Originator originator;
    CareTaker careTaker;
    originator.setState("State #1");
    originator.setState("State #2");
    careTaker.add(originator.saveStateToMemento());

    originator.setState("State #3");
    careTaker.add(originator.saveStateToMemento());
    originator.setState("State #4");

    cout << "Current state: " << originator.getState() << endl;
    originator.getStateFromMemento(careTaker.get(0));
    cout <<"First saved state: " << originator.getState() << endl;
    originator.getStateFromMemento(careTaker.get(1));
    cout <<"Second saved state: " << originator.getState() << endl;


    system("pause");
    return 0;
}