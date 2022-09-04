#include <iostream>
#include <string>

using namespace std;


class Strategy {
public:
    virtual float getResult(float price) {}
    virtual ~Strategy() {}
};


class ConcreteStrategy1: public Strategy {
public:
    float getResult(float price) {
        if (price > 100) {
            return price - 10;
        }
    }
};

class ConcreteStrategy2: public Strategy {
public:
    float getResult(float price) {
        if (price > 299) {
            return price * 0.8;
        }
    }
};
class ConcreteStrategy3: public Strategy {
public:
    float getResult(float price) {
        if (price >= 500) {
            return price - 60;
        }
    }
};

class NullStrategy: public Strategy {
public:
    
    float getResult(float price) {
        cout << "Not Available Strategy." << endl;
        return price;
    }
};

class Context {
public:
    Strategy* getStrategy(string strategyName) {
        Strategy* st;
        if (strategyName == "strategy1") {
            st = new ConcreteStrategy1;
        } else if (strategyName == "strategy2") {
            st = new ConcreteStrategy2;
        } else if (strategyName == "strategy3") {
            st = new ConcreteStrategy3;
        } else {
            st = new NullStrategy;
        }
    
        _strategy = st;
        return _strategy;
    }

    ~Context() {
        delete _strategy;
        _strategy = nullptr;
    }
private:
    Strategy* _strategy;
};


int main() {

    Context c;
    string stName = "strategy1";
    Strategy* st1 = c.getStrategy("strategy1");
    Strategy* st2 = c.getStrategy("strategy2");
    Strategy* st3 = c.getStrategy("strategy3");
    Strategy* st4 = c.getStrategy("strategy4");
    float price = 500;
    
    cout << st1->getResult(price) << endl;
    cout << st2->getResult(price) << endl;
    cout << st3->getResult(price) << endl;
    cout << st4->getResult(price) << endl;

    system("pause");
    return 0;
}