#include <iostream>
#include <string>

using namespace std;


class Strategy {
public:
    virtual float getResult(float& price) {}
    virtual ~Strategy() {}
};


class ConcreteStrategy1 {
public:
    float getResult(float& price) {
        if (price > 100) {
            return price - 10;
        }
    }
};

class ConcreteStrategy2 {
public:
    float getResult(float& price) {
        if (price > 299) {
            return price * 0.8;
        }
    }
};
class ConcreteStrategy3 {
public:
    float getResult(float& price) {
        if (price > 500) {
            return price - 60;
        }
    }
};

class Context {
public:
    Strategy getStrategy(string& strategyName) {
        switch (c_str(strategyName)) {
            case "strategy1":
                ConcreteStrategy1 st;
                break;
            case "strategy2":
                ConcreteStrategy2 st;
                break;
            case "strategy3":
                ConcreteStrategy3 st;
                break;
            default:
                break;
        }
        strategy = strategy;
        return strategy;
    }
private:
    Strategy strategy;
};


int main() {

    Context c;
    string stName = "strategy1";
    Strategy st = c.getStrategy(stName);
    float price = 500;
    
    cout << st.getResult(price) << endl;
    system("pause");
    return 0;
}