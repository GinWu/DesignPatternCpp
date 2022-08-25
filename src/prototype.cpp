#include <iostream>
#include <string>
#include <map>

using namespace std;

class Shape {
public:
    virtual string getType() = 0;
    virtual string getId() = 0;
    void setId(string id) {
        _id = id;
    }
    virtual Shape* clone() = 0;
    virtual void draw() = 0;
    virtual ~Shape(){};

protected:
    string _id;
    string _type;
};


class Circle: public Shape {
public:
    Circle() {
        _type = "Circle";
    }

    string getType() override {
        return _type;
    }

    string getId() override {
        return _id;
    }

    Circle(const Circle& c) {
        cout << "Circle copy construct!" << endl;
        this->_type = c._type;
        this->_id = c._id;
    }

    void draw() override {
        cout << "this is id" << _id << " draw a " << _type << endl;
    }

    Shape* clone() override {
        return new Circle(*this);
    }

};

class Square: public Shape {
public:
    Square() {
        _type = "Square";
    }

    Square(const Square& s) {
        cout << "Square copy construct!" << endl;
        this->_type = s._type;
        this->_id = s._id;
    }

    string getType() override {
        return _type;
    }

    string getId() override {
        return _id;
    }

    void draw() override {
        cout << "this is id" << _id << " draw a " << _type << endl;
    }

    Shape* clone() override {
        return new Square(*this);
    }

};

class Rectangle: public Shape {
public:
    Rectangle() {
        _type = "Rectangle";
    }

    Rectangle(const Rectangle& r) {
        cout << "Rectangle copy construct!" << endl;
        this->_type = r._type;
        this->_id = r._id;
    }

    string getType() override {
        return _type;
    }

    string getId() override {
        return _id;
    }

    void draw() override {
        cout << "this is id" << _id << " draw a " << _type << endl;
    }

    Shape* clone() override {
        return new Rectangle(*this);
    }
};

class ShapeCache {
public:
    Shape* getShape(string shapeId) {
        auto iter = _shapeMap.find(shapeId);
        if (iter == _shapeMap.end()) {
            cout << "shapeId is not exists." << endl;
            return nullptr;
        }
        return iter->second->clone();
    }

    void loadCache() {
        Shape* circle = new Circle;
        circle->setId("1");
        _shapeMap.emplace(make_pair(circle->getId(), circle));

        Shape* rectangle = new Rectangle;
        rectangle->setId("2");
        _shapeMap.emplace(make_pair(rectangle->getId(), rectangle));

        Shape* square = new Square;
        square->setId("3");
        _shapeMap.emplace(make_pair(square->getId(), square));
    }

    ~ShapeCache() {
        for (auto iter = _shapeMap.begin(); iter != _shapeMap.end(); ++iter) {
            delete iter->second;
            iter->second = nullptr;
        }
        _shapeMap.clear();
    }

private:
    map<string, Shape*> _shapeMap;
};


int main() {
    ShapeCache shapeCache;
    shapeCache.loadCache();
    Shape* circle = shapeCache.getShape("1");
    circle->draw();

    Shape* rectangle = shapeCache.getShape("2");
    rectangle->draw();

    Shape* square = shapeCache.getShape("3");
    square->draw();

    delete circle;
    delete rectangle;
    delete square;
    circle = nullptr;
    rectangle = nullptr;
    square = nullptr;

    system("pause");
    return 0;
}
