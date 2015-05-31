using namespace std;
#include <iostream>
 
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
 
        void show(void) {
            cout << this->real << "+" << this->im << "i" << endl;
        }
};
 
int main() {
    Complex c1(3,5);
    Complex c2 = 4.5;
    c1.add(c2);
    c1.show();
    return 0;
}