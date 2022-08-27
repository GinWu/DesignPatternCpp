#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <vector>

using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual void setX(int x) = 0;
    virtual void setY(int y) = 0;
    virtual void setRadius(int radius) = 0;
    virtual ~Shape() {}
};

class Circle: public Shape {
public:
    Circle(string color): _color(color) {}

    void setX(int x) {
        _x = x;
    }

    void setY(int y) {
        _y = y;
    }

    void setRadius(int radius) {
        _radius = radius;
    }

    void draw() {
        cout << "draw a circle [ color: " << _color << ", x: " << _x \
             << ", y: " << _y << ", radius: " << _radius << endl;
    }
private:
    int _x;
    int _y;
    int _radius;
    string _color;
};

vector<string> COLORVEC = {"blue", "green", "red", "yellow", "purple", "black", "white"};

static string getRandomColor() {
    int idx = rand() % 7;
    return COLORVEC[idx];
}

static int getRandom() {
    return rand() % 100 + 1;
}

class ShapeFactory {
public:
    Shape* getCircle(string color) {
        Shape* circle;
        auto iter = _circleMap.find(color);
        if (iter == _circleMap.end()) {
            circle = new Circle(color);
            _circleMap.emplace(make_pair(color, circle));
        } else {
            circle = iter->second;
        }
        
        return circle;
    }
    ~ShapeFactory() {
        for(auto iter = _circleMap.begin(); iter != _circleMap.end(); ++iter) {
            delete iter->second;
            iter->second = nullptr;
        }
        _circleMap.clear();
    }
private:
    map<string, Shape*> _circleMap;
};


int main() {
    ShapeFactory shapeFactory;
    for (int i = 0; i < 10; ++i) {
        Shape* circle = shapeFactory.getCircle(getRandomColor());
        circle->setX(getRandom());
        circle->setY(getRandom());
        circle->setRadius(getRandom());
        circle->draw();
    }
    system("pause");
    return 0;
}