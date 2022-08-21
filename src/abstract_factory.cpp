#include <iostream>
#include <string>

// class Reflector {
// public:
//     static void regist(std::string& fac, void& facObject) {
//         facMap[fac] = facObject;
//     }
//     void getFactory(std::string& fac) {
//         auto facIter = facMap.find(fac);
//         if (facIter == facMap.end()) {
//             return NULL;
//         }
//         facObject facObject = facIter->second;
//         if (!facObject) {
//             return NULL;
//         }
//         return facObject;
//     }
//     static Reflector& getInstance() {
//         static Reflector fac;
//         return fac;
//     }

// private:
//     Reflector() {};
//     std::map<std::string, IFactory> facMap;

// };

class IProduct{
public:
    virtual void display() {
        std::cout << "this is IProduct" << std::endl;
    }
    virtual void cal(int& a, int& b) {
        std::cout << "IProduct cal" << std::endl;
    }
    virtual ~IProduct(){};
};

class ProductA: public IProduct {
public:
    void display() {
        std::cout << "this is ProductA" << std::endl;
    }
    void cal(int& a, int& b) {
        std::cout << "ProductA cal result: " << a + b << std::endl;
    }
};
class ProductB: public IProduct {
public:
    void display() {
        std::cout << "this is ProductB" << std::endl;
    }
    void cal(int& a, int& b) {
        std::cout << "ProductB cal result: " << a * b << std::endl;
    }
};


class IFactory {
public:
    virtual IProduct* getProduct() {};

    virtual ~IFactory() {};
};

class FactoryA: public IFactory {
public:
    IProduct* getProduct() {
        IProduct* prodA = new ProductA;
        return prodA;
    }
};

class FactoryB: public IFactory {
public:
    IProduct* getProduct() {
        IProduct* prodB = new ProductB;
        return prodB;
    }

};





int main() {
    FactoryB facA;
    IProduct* prodA = facA.getProduct();
    prodA->display();
    int a = 1;
    int b = 2;
    prodA->cal(a, b);
    system("pause");
    return 0;
    
}