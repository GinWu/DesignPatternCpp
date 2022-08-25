#include <iostream>
#include <string>

using namespace std;


class DrawAPI {
public:
    virtual void drawCircle(int radius, int x, int y) = 0;
    virtual ~DrawAPI() {}
};

class RedCircle: public DrawAPI {
public:
    void drawCircle(int radius, int x, int y) override {
        cout << "Drawing circle[ color: red, radius: " << radius << ", x: " << x << ", y: " << y << " ]"<< endl;
    }

};

class GreenCircle: public DrawAPI {
public:
    void drawCircle(int radius, int x, int y) override {
        cout << "Drawing circle[ color: green, radius: " << radius \
             << ", x: " << x << ", y: " << y << " ]"<< endl;
    }

};

class Shape {
public:
    Shape(DrawAPI* drawAPI) {
        _drawAPI = drawAPI; 
    }

    virtual void draw() = 0;

    virtual ~Shape() {
        delete _drawAPI;
        _drawAPI = nullptr;
    }

protected:
    DrawAPI* _drawAPI;
};

class Circle: public Shape {
public:
    Circle(int x, int y, int radius, DrawAPI* drawAPI): Shape(drawAPI) {
        _x = x;
        _y = y;
        _radius = radius;
    }

    void draw() {
        _drawAPI->drawCircle(_radius, _x, _y);
    }
private:
    int _x;
    int _y;
    int _radius;
};


int main() {
    DrawAPI* redDrawAPI = new RedCircle;
    Shape* redCircle = new Circle(5, 8, 6, redDrawAPI);
    redCircle->draw();

    DrawAPI* greenDrawAPI = new GreenCircle;
    Shape* greenCircle = new Circle(6, 8, 10, greenDrawAPI);
    greenCircle->draw();


    delete redCircle;
    delete greenCircle;

    redCircle = nullptr;
    greenCircle = nullptr;

    system("pause");
    return 0;
}