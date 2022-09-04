#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ComputerPartVisitor;
class ComputerPart {
public:
    virtual void accept(ComputerPartVisitor* visitor) = 0;
    virtual ~ComputerPart() {};
};

class Keyboard: public ComputerPart {
public:
    void accept(ComputerPartVisitor* visitor);
};

class Mouse: public ComputerPart {
public:
    void accept(ComputerPartVisitor* visitor);
};

class Monitor: public ComputerPart {
public:
    void accept(ComputerPartVisitor* visitor);
};

class Computer: public ComputerPart {
public:
    Computer() {
        _parts.emplace_back(new Mouse);
        _parts.emplace_back(new Keyboard);
        _parts.emplace_back(new Monitor);
    }

    void accept(ComputerPartVisitor* visitor);
    
    ~Computer() {
        for(int i = 0; i < _parts.size(); ++i) {
            delete _parts[i];
            _parts[i] = nullptr;
        }
        _parts.clear();
    }
    
private:
    vector<ComputerPart*> _parts;
};

class ComputerPartVisitor {
public:
    virtual void visit(Computer* computer) = 0;

    virtual void visit(Mouse* mouse) = 0;

    virtual void visit(Keyboard* keyboard) = 0;

    virtual void visit(Monitor* monitor) = 0;
};

void Keyboard::accept(ComputerPartVisitor* visitor) {
    visitor->visit(this);
}

void Mouse::accept(ComputerPartVisitor* visitor) {
    visitor->visit(this);
}
void Monitor::accept(ComputerPartVisitor* visitor) {
    visitor->visit(this);
}
void Computer::accept(ComputerPartVisitor* visitor) {
    for (int i = 0; i < _parts.size(); ++i) {
        _parts[i]->accept(visitor);
    }
    visitor->visit(this);
}

class ComputerPartDisplayVisitor: public ComputerPartVisitor {
public:
    void visit(Computer* computer) {
        cout << "visit computer" << endl;
    }
    void visit(Mouse* mouse) {
        cout << "visit Mouse" << endl;
    }
    void visit(Keyboard* keyboard) {
        cout << "visit keyboard" << endl;
    }
    void visit(Monitor* monitor) {
        cout << "visit Monitor" << endl;
    }
};

int main() {
    ComputerPart* computer = new Computer;
    computer->accept(new ComputerPartDisplayVisitor());
    system("pause");
    return 0;
}