#include <iostream>
#include <string>

using namespace std;

class Image {
public:
    virtual void display() = 0;
    virtual void loadFromDisk(string fileName) = 0;

    virtual ~Image() {}
};

class RealImage: public Image {
public:
    RealImage(string fileName): _fileName(fileName) {
        loadFromDisk(fileName);
    }

    void display() override {
        cout << "display " << _fileName << endl;
    }

    void loadFromDisk(string fileName) override {
        cout << "load " << fileName << " from disk." << endl;
    }

    ~RealImage() {
        _fileName.clear();
    }
private:
    string _fileName;

};

class ProxyImage: public Image {
public:
    ProxyImage(string fileName): _fileName(fileName) {
        _realImage = new RealImage(_fileName);
    }

    void display() override {
        _realImage->display();
    }

    void loadFromDisk(string fileName) override {
    }

    ~ProxyImage() {
        delete _realImage;
        _realImage = nullptr;
        _fileName.clear();
    }

private:
    RealImage* _realImage;
    string _fileName;
};


int main() {
    ProxyImage proxyImage("test_image.jpg");
    proxyImage.display();

    system("pause");
    return 0;
}