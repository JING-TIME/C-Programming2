#include <iostream>
using namespace std;


int getPower(int x, int n) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (n == 0) return 1;
    if (n > 0) {
        return x * getPower(x, n-1);
    }
    if (n < 0) {
        return getPower(x, n+1) / x;
    }
    return 0;
}

double getPower(double x, int n) {
    if (n == 0) return 1;
    if (n > 0) {
        return x * getPower(x, n-1);
    }
    if (n < 0) {
        return getPower(x, n+1) / x;
    }
    return 0.0;
}

int main()
{
    int a;
    double b;
    int m;
    cin >> a >> b >> m;
    cout << getPower(a, m) << endl;
    cout << getPower(b, m) << endl;
    return 0;
}
