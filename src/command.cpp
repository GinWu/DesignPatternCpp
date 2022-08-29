#include <iostream>
#include <string>

using namespace std;

class Stock {
public:
    Stock(string name) {
        _name = name;
    }
    void buy(int qty) {
        cout << "Buy Stock [ stock: " << _name << " quantity: " << qty << " ]" << endl;
    }

    void sell(int qty) {
        cout << "Sell Stock [ stock: " << _name << " quantity: " << qty << " ]" << endl;
    }
private:
    string _name;
};

class Order {
public:
    virtual void execute() = 0;
    virtual ~Order() {}
};

class BuyStock: public Order {
public:
    BuyStock(Stock* stock, int qty) {
        _stock = stock;
        _qty = qty;
    }

    void execute() {
        _stock->buy(_qty);
    }

private:
    Stock* _stock;
    int _qty;
};

class SellStock: public Order {
public:
    SellStock(Stock* stock, int qty) {
        _stock = stock;
        _qty = qty;
    }

    void execute() {
        _stock->sell(_qty);
    }

private:
    Stock* _stock;
    int _qty;
};

int main() {
    Stock* appleStock = new Stock("apple");
    Stock* amazonStock = new Stock("amazon");
    Stock* alibabaStock = new Stock("alibaba");
    Stock* teslaStock = new Stock("tesla");

    BuyStock buyStockOrder1(appleStock, 1000);
    BuyStock buyStockOrder2(amazonStock, 500);
    BuyStock buyStockOrder3(alibabaStock, 1200);
    SellStock sellStockOrder1(teslaStock, 800);

    buyStockOrder1.execute();
    buyStockOrder2.execute();
    buyStockOrder3.execute();
    sellStockOrder1.execute();

    delete appleStock;
    delete amazonStock;
    delete alibabaStock;
    delete teslaStock;

    appleStock = nullptr;
    amazonStock = nullptr;
    alibabaStock = nullptr;
    teslaStock = nullptr;

    system("pause");
    return 0;
}