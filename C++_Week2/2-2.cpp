#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double im;
public:
    Complex(double real=0, double im=0) {
        this->real = real;
        this->im = im;
    }
    Complex operator+(Complex c) {
        Complex sum;
        sum.real = this->real + c.real;
        sum.im = this->im + c.im;
        return sum;
    }
    Complex operator-(Complex c) {
        Complex result;
        result.real = this->real - c.real;
        result.im = this->im - c.im;
        return result;
    }
    bool operator==(Complex c) {
        if (this->real == c.real && this->im == c.im) {
            return true;
        }
        else return false;
    }
     bool operator!=(Complex c) {
        if (this->real == c.real && this->im == c.im) {
            return false;
        }
        else return true;
    }
    Complex operator++(void) {
        this->real++;
        return Complex(real, im);
    }
    Complex operator++(int) {
        im ++;
        return Complex(real,im);
    }
    friend ostream& operator<<(ostream& out, const Complex &c) {
        out << c.real;
        if (c.im < 0) {
            out << "-" << -c.im << "i";
        } else if (c.im > 0) {
            out << "+" << c.im << "i";
        }
        return out;
    }
    friend istream& operator>>(istream& iin, Complex &c) {
        iin >> c.real >> c.im;
        return iin;
    }
};

int main()
{
    Complex c1(1, 2), c2(2, 5), c3(1, 2);
    cout << c1 << endl;
    cout << (c2-c1) << endl;
    cout << (c1 == c2) << endl;
    cout << (c1 != c2) << endl;
    ++ c2;
    cout << c2 << endl;
    c2 ++;
    cout << c2 << endl;
    Complex c4;
    cin >> c4;
    cout << c4 << endl;
    return 0;
}
