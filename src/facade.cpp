#include <iostream>
#include <string>

using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle: public Shape {
public:
    void draw() {
        cout << "draw a circle." << endl;
    }

};

class Square: public Shape {
public:
    void draw() {
        cout << "draw a square." << endl;
    }

};

class Rectangle: public Shape {
public:
    void draw() {
        cout << "draw a rectangle." << endl;
    }

};

class ShapeMaker {
public:
    ShapeMaker() {
        _circle = new Circle;
        _rectangle = new Rectangle;
        _square = new Square;
    }

    void drawCircle() {
        _circle->draw();
    }

    void drawRectangle() {
        _rectangle->draw();

    }

    void drawSquare() {
        _square->draw();
    }

    ~ShapeMaker() {
        delete _circle;
        delete _rectangle;
        delete _square;

        _circle = nullptr;
        _rectangle = nullptr;
        _square = nullptr;
    }
private:
    Shape* _circle;
    Shape* _rectangle;
    Shape* _square;
};


int main() {
    ShapeMaker shapeMaker;
    shapeMaker.drawCircle();
    shapeMaker.drawRectangle();
    shapeMaker.drawSquare();

    system("pause");
    return 0;
}