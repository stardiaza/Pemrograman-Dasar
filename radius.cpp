//distance formula Programming Exercise 8
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double PI = 3.1416;

double calculateRadius(double a, double b, double c, double d){
    return sqrt(pow(c - a, 2) + pow(d - b, 2));
}

double calculateDiameter(double radius) {
    return radius*2;
}

double calculateCircumference(double radius) {
    return radius*PI*2;
}

double calculateArea(double radius) {
    return PI*radius*radius;
}

int main() {
    double x1, y1, x2, y2;
    cout << "Masukkan titik pusat (x1) : ";
    cin >> x1;
    cout << "Masukkan titik pusat (y1) : ";
    cin >> y1;
    cout << "Masukkan titik diketahui (x2) : ";
    cin >> x2;
    cout << "Masukkan titik diketahui (y2) : ";
    cin >> y2;
    
    double radius = calculateRadius(x1, y1, x2, y2);
    double diameter = calculateDiameter(radius);
    double circumference = calculateCircumference(radius);
    double area = calculateArea(radius);

    cout << fixed << setprecision(4);
    cout << "Radius : " << radius << '\n';
    cout << "Diameter: " << diameter << '\n';
    cout << "Circumference : " << circumference << '\n';
    cout << "Area : " << area << '\n';
              
    return 0;
}

