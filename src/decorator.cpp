#include <iostream>
#include <string>

using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {};
};

class Circle: public Shape {
public:
    void draw() {
        cout << "draw a circle" << endl;
    }
};

class Rectangle: public Shape {
public:
    void draw() {
        cout << "draw a rectangle" << endl;
    }
};

class ShapeDecorator {
public:
    ShapeDecorator(Shape* shape) {
        _shape = shape;
    }
    virtual void draw() {
        _shape->draw();
    }
    virtual ~ShapeDecorator() {
        delete _shape;
        _shape = nullptr;
    }
protected:
    Shape* _shape;
};

class RedShapeDecorator: public ShapeDecorator {
public:
    RedShapeDecorator(Shape* shape) : ShapeDecorator(shape) {
    }
    void draw() override {
        _shape->draw();
        setRedBorder(_shape);
    }
private:
    void setRedBorder(Shape* shape) {
        cout << "border color: red" << endl;
    }
};

int main() {
    Shape* c = new Circle;
    ShapeDecorator* shape = new RedShapeDecorator(c);
    shape->draw();
    delete c;
    delete shape;
    c = nullptr;
    shape = nullptr;
    system("pause");
    return 0;
}
