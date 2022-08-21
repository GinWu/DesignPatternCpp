#include <iostream>
#include <string>


class Shape {
public:
    virtual void draw(){};
    virtual ~Shape(){};
};


class Rectangle: public Shape {
public:
    void draw() {
        std::cout << "draw a rectangle \n";
    }
};

class Square: public Shape {
public:
    void draw() {
        std::cout << "draw a square \n";
    }
};

class Circle: public Shape {
public:
    void draw() {
        std::cout << "draw a circle \n";
    }
};

class ShapeFactory {
public:
    Shape* getShape(std::string& shapeType) {
        if(shapeType == "RECTANGLE") {
            return new Rectangle();
        } else if (shapeType == "CIRCLE") {
            return new Circle();
        } else if (shapeType == "SQUARE") {
            return new Square();
        }
        
        return NULL;
    }
};

int main() {
    ShapeFactory factory;
    std::string shape;
    shape = "RECTANGLE";
    Shape* rec = factory.getShape(shape);
    rec->draw();
    shape = "CIRCLE";
    Shape* circle = factory.getShape(shape);
    circle->draw();
    shape = "SQUARE";
    Shape* square = factory.getShape(shape);
    square->draw();
    // std::cout << "ok" << std::endl;
    system("pause");
    return 0;
}