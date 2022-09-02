#include <iostream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;

class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() {};
};

class Subject {
public:
    int getState() {
        return _state;
    }

    void setState(int state) {
        _state = state;
        notifyAllObservers();
    }

    void attach(Observer* observer) {
        _observers.emplace_back(observer);
    }

    void notifyAllObservers() {
        for (auto& observer: _observers) {
            observer->update();
        }
    }

    ~Subject() {
        for (int i = 0; i < _observers.size(); ++i) {
            delete _observers[i];
            _observers[i] = nullptr;
        }
        _observers.clear();
    }

private:
    vector<Observer*> _observers;
    int _state;
};



class BinaryObserver: public Observer {
public:
    BinaryObserver(Subject& subject) {
        _subject = &subject;
        subject.attach(this);
    }

    void update() {
        cout << "Binary string: " << bitset<8>(_subject->getState()) << endl;
    }

private:
    Subject* _subject;
};

class OctalObserver: public Observer {
public:

    OctalObserver(Subject& subject) {
        _subject = &subject;
        subject.attach(this);
    }

    void update() {
        cout << "Octal string: " << oct << _subject->getState() << endl;
    }

private:
    Subject* _subject;
};

class HexaObserver: public Observer {
public:
    HexaObserver(Subject& subject) {
        _subject = &subject;
        subject.attach(this);
    }
    
    void update() {
        cout << "Hex string: " << hex << _subject->getState() << endl;
    }

private:
    Subject* _subject;
};

int main() {
    Subject subject;

    HexaObserver hexaObserver(subject);
    OctalObserver octalObserver(subject);
    BinaryObserver binaryObserver(subject);

    cout << "First state change: 15" << endl;
    subject.setState(15);

    cout << "Second state change: 10" << endl;
    subject.setState(10);

    system("pause");
    return 0;
}