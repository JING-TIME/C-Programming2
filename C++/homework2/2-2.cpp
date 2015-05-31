using namespace std;
#include <iostream>
#include <cmath>
 
class Complex {
    private:
        double real;
        double im;
 
    public:
        Complex(void) {
            real = im = 0;
        }

        Complex(double real, double im) {
            this->real = real;
            this->im = im;
        }
 
        Complex(double real) {
            this->real = real;
            this->im = 0;
        }

        Complex& operator=(const Complex &b) {
            real = b.real;
            im = b.im;
        }

        Complex operator+(const Complex &b) {
            return Complex(real + b.real, im + b.im);
        }

        Complex operator-(const Complex &b) {
            return Complex(real - b.real, im - b.im);
        }

        Complex operator*(const Complex &b) {
            return Complex(real * b.real, im * b.im);
        }

        Complex operator/(const Complex &b) {
            return Complex(real / b.real, im / b.im);
        }

        bool operator==(const Complex &b) {
            return (real == b.real && im == b.im);
        }

        bool operator!=(const Complex &b) {
            return (real != b.real || im != b.im);
        }

        // ++this
        Complex operator++(void) {
            real++;
            return Complex(real, im);
        }
        
        // --this
        Complex operator--(void) {
            real--;
            return Complex(real, im);
        }

        // this++
        Complex operator++(int) {
            im++;
            return Complex(real, im);
        }

        // this--
        Complex operator--(int) {
            im--;
            return Complex(real, im);
        }

        Complex& operator+=(const Complex &b) {
            real += b.real;
            im += b.im;
        }

        Complex operator~(void) {
            return Complex(im, real);
        }

        Complex operator-(void) {
            return Complex(-real, -im);
        }

        Complex operator+(void) {
            return Complex(real, im);
        }

        // return the length of Complex as a vector
        operator double() const {
            return sqrt(real * real + im * im);
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

        friend istream& operator>>(istream& in, Complex &c) {
            in >> c.real >> c.im;
            return in;
        }
 
        void add(Complex c) {
            this->real += c.real;
            this->im += c.im;
        }
 
        void show(void) {
            cout << this->real << "+" << this->im << "i" << endl;
        }

        double getReal(void) {
            return real;
        }

        double getIm(void) {
            return im;
        }
};

int main() {
    Complex c1, c2;

    cout << "Input two doubles as real and im of c1: " << endl;
    cin >> c1;
    cout << "Input two doubles as real and im of c2: " << endl;
    cin >> c2;

    cout << "c1 = " << c1 << " (length=" << (double)c1 << ")" << endl;
    cout << "c2 = " << c2 << " (length=" << (double)c2 << ")" << endl;

    cout << "c1 + c2 = " << c1 + c2 << endl;
    cout << "c1 - c2 = " << c1 - c2 << endl;
    cout << "c1 * c2 = " << c1 * c2 << endl;
    cout << "c1 / c2 = " << c1 / c2 << endl;

    cout << "c1++ = " << c1++ << endl;
    cout << "c1-- = " << c1-- << endl;
    cout << "++c1 = " << ++c1 << endl;
    cout << "--c1 = " << --c1 << endl;

    cout << "~c1 = " << ~c1 << endl;
    cout << "-c1 = " << -c1 << endl;
    cout << "+c1 = " << +c1 << endl;

    cout << "(c1+c2)*(c1-c2) = " << (c1+c2)*(c1-c2) << endl;
    cout << "c1*c1  - c2*c2  = " << c1*c1 - c2*c2 << endl;

    if (c1 == c2)
        cout << "c1 == c2" << endl;
    if (c1 != c2)
        cout << "c1 != c2" << endl;
    if (c1 == c1)
        cout << "c1 == c1" << endl;
    if (c1 != c1)
        cout << "c1 != c1" << endl;

    c2 += c1;
    cout << "Assign c2 += c1;" << endl << "c2 = " << c2 << endl;

    c2 = c1;
    cout << "Assign c2 = c1;" << endl << "c2 = " << c2 << endl;
    if (c2 == c1)
        cout << "c1 == c2" << endl;

    return 0;
}