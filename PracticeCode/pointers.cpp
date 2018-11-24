#include <cmath>
#include <iostream>
using namespace std;

void polarToCartesian(double rho, double theta, double* xx, double* yy); //double* means pointer-to-double or the-address-of-some-double

int main() {
    double r = 5;
    double angle = 90;

    double x;
    double y;
    polarToCartesian(r, angle, &x, &y);

    cout << x << endl;
    cout << y << endl;
}

void polarToCartesian(double rho, double theta, double* xx, double* yy) {
    *xx = rho * cos(theta);
    *yy = rho * sin(theta);
}