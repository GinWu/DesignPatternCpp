#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class Item> class Iterator {
public:
    Iterator() {};
    virtual ~Iterator() {};

    virtual bool hasNext() = 0;
    virtual Item next() = 0;
};

class Container {
public:
    virtual Iterator<string>* getIterator() = 0;
    virtual ~Container() {};
};

class NameRepository: public Container {
public:
    NameRepository() {
    }
    template<class Item>
    class NameIterator: public Iterator<Item> {
    public:
        int _index = 0;
        bool hasNext() override {
            if (_index < _names.size()) {
                return true;
            }
            return false;
        }

        Item next() override {
            if (hasNext()) {
                return _names[_index++];
            }
            return NULL;
        }
        ~NameIterator() {
        _names.clear();
        }
    private:
        vector<string> _names = {"Tom", "Smith", "Trump", "Obama", "Biden"};
    };

    Iterator<string>* getIterator() {
        return new NameIterator<string>();
    }

};

int main() {
    NameRepository nameRepository;
    for(Iterator<string>* iter = nameRepository.getIterator(); iter->hasNext();) {
        string name = iter->next();
        cout << "Name: " << name << endl;
    }

    system("pause");
    return 0;
}