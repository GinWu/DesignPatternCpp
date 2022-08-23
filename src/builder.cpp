#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Packing {
public:
    Packing() {}
    virtual string packingName() = 0;
    virtual ~Packing() {};
};

class Wrapper: public Packing {
    string packingName() {
        return "Wrapper";
    }
};

class Bottle: public Packing {
public:
    string packingName() {
        return "Bottle";
    }   
};

class Item {
public:
    virtual string name() = 0;

    virtual Packing* packing() = 0;

    virtual float price() = 0;

    virtual ~Item() {};
};

class Burger: public Item {
public:
    Packing* packing() {
        Packing* pack = new Wrapper;
        return pack;
    }
    virtual ~Burger() {};
};

class VegBurger: public Burger {
public:
    string name() {
        return "VegBurger";
    }
    float price() {
        return 9.99;
    }
};

class ChickenBurger: public Burger {
public:
    string name() {
        return "ChickenBurger";
    }
    float price() {
        return 15.99;
    }
};


class ColdDrink: public Item {
public:
    Packing* packing() {
        Packing* pack = new Bottle;
        return pack;
    }
    virtual ~ColdDrink() {};
};

class Pepsi: public ColdDrink {
public:
    string name() {
        return "Pepsi";
    } 
    float price() {
        return 2.89;
    }
};

class Coke: public ColdDrink {
public:
    string name() {
        return "Coke";
    }
    float price() {
        return 2.99;
    }
};


class Meal {
public:
    void addItem(Item* item) {
        _items.emplace_back(item);
    }

    float getCost() {
        float cost = 0.0;
        for(auto& item: _items) {
            cost += item->price();
        }
        return cost;
    }

    void showItems() {
        for(auto& item: _items) {
            cout << item->name() << "\t" << item->packing()->packingName() << "\t" << item->price() << endl;
        }
    }

    ~Meal() {
        for (int i = 0; i < _items.size(); ++i) {
            delete _items[i];
            _items[i] = nullptr;
        }
        _items.clear();
    }

private:
    vector<Item*> _items;
};


class MealBuilder {
public:
    Meal prepareVegMeal() {
        Meal meal;
        Item* coke = new Coke;
        Item* vegBurger = new VegBurger;
        meal.addItem(coke);
        meal.addItem(vegBurger);

        return meal;
    }

    Meal prepareNonVegMeal() {
        Meal meal;
        Item* pepsi = new Pepsi;
        Item* chickenBurger = new ChickenBurger;
        meal.addItem(pepsi);
        meal.addItem(chickenBurger);

        return meal;
    }
};


int main() {
    MealBuilder mealBuilder;
    Meal vegMeal = mealBuilder.prepareVegMeal();
    Meal nonVegMeal = mealBuilder.prepareNonVegMeal();

    vegMeal.showItems();
    cout << "total cost for veg meal: " << vegMeal.getCost() << endl;

    nonVegMeal.showItems();
    cout << "total cost for none-veg meal: " << nonVegMeal.getCost() << endl;

    system("pause");
    return 0;
}