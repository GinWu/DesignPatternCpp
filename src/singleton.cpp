#include <iostream>
#include <string>
#include <mutex>

using namespace std;
/*
    impletement 5 kind of singleton:
        1. basic singleton
        2. common lazy loading singleton
        3. lazy and thread-safe singleton
        4. double-checked locking singleton
        5. hunger loading singleton
*/

// basic singleton
class SingleObject {
public:
    
    static SingleObject getInstance() {
        return _instance;
    }

    void showMessage() {
        cout << "hi I'm singleObject." << endl;
    }

private:
    SingleObject() {}
    static SingleObject _instance;
};

// common lazy loading singleton
class LazySingleton {
public:
    static LazySingleton* getInstance() {
        if (!_instance) {
            _instance = new LazySingleton;
        }
        return _instance;
    }
    void showMessage() {
        cout << "hi I'm LazySingleton." << endl;
    }
    ~LazySingleton() {
        delete _instance;
        _instance = nullptr;
    }
private:
    LazySingleton() {}
    static LazySingleton* _instance;
};

// lazy and thread-safe singleton
class LazySingleton_S {
public:
    static LazySingleton_S* getInstance() {
        if (_instance == nullptr) {
            std::lock_guard<std::mutex> lock(_lock);
            _instance = new LazySingleton_S;
        }
        return _instance;
    }

    void showMessage() {
        cout << "hi I'm LazySingleton_S." << endl;
    }

    ~LazySingleton_S() {
        delete _instance;
        _instance = nullptr;
    }
private:
    LazySingleton_S() {}
    static LazySingleton_S* _instance;
    static std::mutex _lock;

};

// double-checked locking singleton
class DoubleCheckedLazySingleton {
public:
    static DoubleCheckedLazySingleton* getInstance() {
        if (_instance == nullptr) {
            std::lock_guard<std::mutex> lock(_lock);
            if (_instance == nullptr) {
                _instance = new DoubleCheckedLazySingleton;
            }
        }
        return _instance;
    }

    void showMessage() {
        cout << "hi I'm DoubleCheckedLazySingleton." << endl;
    }

    ~DoubleCheckedLazySingleton() {
        delete _instance;
        _instance = nullptr;
    }
private:
    static DoubleCheckedLazySingleton* _instance;
    static std::mutex _lock;
    DoubleCheckedLazySingleton() {}
};

// hunger load singleton
class HungerSingleton {
public:
    static HungerSingleton* getInstance() {
        return _instance;
    }
    void showMessage() {
        cout << "hi I'm HungerSingleton." << endl;
    }
    ~HungerSingleton() {
        delete _instance;
        _instance = nullptr;
    }
private:
    static HungerSingleton* _instance;
    HungerSingleton() {}
};

// init static variant
LazySingleton* LazySingleton::_instance = nullptr;

LazySingleton_S* LazySingleton_S::_instance = nullptr;
std::mutex LazySingleton_S::_lock;

DoubleCheckedLazySingleton* DoubleCheckedLazySingleton::_instance = nullptr;
std::mutex DoubleCheckedLazySingleton::_lock;

HungerSingleton* HungerSingleton::_instance = new HungerSingleton;

int main() {
    SingleObject obj = SingleObject::getInstance();
    obj.showMessage();
    
    LazySingleton* ls = LazySingleton::getInstance();
    ls->showMessage();

    LazySingleton_S* lss = LazySingleton_S::getInstance();
    lss->showMessage();

    DoubleCheckedLazySingleton* dcls = DoubleCheckedLazySingleton::getInstance();
    dcls->showMessage();

    HungerSingleton* hs = HungerSingleton::getInstance();
    hs->showMessage();

    system("pause");
    return 0;
}