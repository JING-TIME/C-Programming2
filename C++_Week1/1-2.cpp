#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double im;

public:
    Complex(double real, double im) {
        this->real = real;
        this->im = im;
    }
    Complex(double real) {
        this->real = real;
        this->im = 0;
    }
    void add(Complex c) {
        this->real += c.real;
        this->im += c.im;
    }
    void show() {
        if (this->im >= 0) {
            cout << this->real << "+" << this->im << "i" << endl;
        }
        else {
            cout << this->real << "-" << -this->im << "i" << endl;
        }
    }
};

int main()
{
    Complex c1(3, 5);
    Complex c2 = 4.5;
    c1.show();
    c2.show();
    c1.add(c2);
    c1.show();
    return 0;
}
