using namespace std;
#include <iostream>
int getPower(int x, int n) {
    if (x == 0)
        return 0;
    if (n == 0)
        return 1;
    else if (n > 0)
        return getPower(x, n-1) * x;
    else // n < 0
        return getPower(x, n+1) / x;
}
double getPower(double x, int n) {
    if (n == 0)
        return 1;
    else if (n > 0)
        return getPower(x, n-1) * x;
    else // n < 0
        return getPower(x, n+1) / x;
}
int main() {
    int a;
    double b;
    int m;
    cin >> a >> b >> m;
    cout << getPower(a,m) << endl << getPower(b,m) << endl;
}