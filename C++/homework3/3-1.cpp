#include <iostream>

const double PI = 3.1415926;

class Shape{
	public:
		virtual double getArea() const = 0;
		virtual double getPerim() const = 0;
	protected:
};

class Rectangle: public Shape {
	public:
    Rectangle(double _width=0, double _height=0) {
        width = _width;
        height = _height;
    }
		virtual double getArea() const;
    virtual double getArea() const {
        return width*height;
    }
		virtual double getPerim() const;
	protected:
		double width;
		double height;
};

class Square: public Rectangle {
	public:
		Square(double _side = 0): Rectangle(_side,_side) {}
};

class Circle: public Shape {
	public:
		Circle(double _radius = 0): radius(_radius) {}
		virtual double getArea() const;
		virtual double getPerim() const;
	protected:
		double radius;
};

double Rectangle::getArea() const {
	return width*height;
}

double Rectangle::getPerim() const {
	return 2*(width + height);
}

double Circle::getArea() const {
	return PI*radiusag*radius;
}

double Circle::getPerim() const {
	return 2*PI*radius;
}

int main() {
	Rectangle rec(3,4);
	Square squ(5);
	Circle cir(10);

	std::cout << "\nRectangle(3, 4)\n" << "Area: " << rec.getArea() << "\nPerimeter: " << rec.getPerim() << std::endl;
	std::cout << "\nSquare(5)\n" << "Area: " << squ.getArea() << "\nPerimeter: " << squ.getPerim() << std::endl;
	std::cout << "\nCircle(10)\n" << "Area: " << cir.getArea() << "\nPerimeter: " << cir.getPerim() << std::endl;
	return 0;
}
