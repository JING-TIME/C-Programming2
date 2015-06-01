#include <iostream>
using namespace std;

class Shape {
public:
    virtual double getArea() {}
    virtual double getPerim() {}
};

class Rectangle: public Shape {
protected:
    double width;
    double height;

public:
    Rectangle(double width, double height) {
        this->width = width;
        this->height = height;
    }
    double getArea() {
        return width*height;
    }
    double getPerim() {
        return 2*(width+height);
    }
};

class Square: public  Rectangle {
public:
    Square(double side): Rectangle(side, side) {}
};
    
int main()
{
    Rectangle r1(3, 4);
    cout << r1.getArea() << endl;
    cout << r1.getPerim() << endl;
    Square s(5);
    cout << s.getArea() << endl;
    cout << s.getPerim() << endl;
    return 0;
}
