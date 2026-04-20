#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class Circle 
{
 public:
 double radius;

 virtual double area()=0;
 virtual double volume()=0;

 Circle (double in):radius(in){};

};

class Sphere :public Circle{
 public:

 double area ()
 {
    return radius*radius*3.14*4;
 }
 double volume()
 {
    return radius*radius*radius*3.14*4/3;
 }
 Sphere(double in):Circle(in){};
};

class Column:public Circle{
 public:
 double height;

 double volume()
 {
    return 3.14*radius*radius*height;
 }
 double area()
 {
    return 3.14*radius*radius*2+2*3.14*radius*height;
 }
 Column (double a,double b):Circle(a),height(b){};
};

int main() {
	double radius, height;
	cout << "Enter the radius of the sphere: ";
	cin >> radius;
	Sphere sphere(radius);
	cout << "Enter the radius and height of the column: ";
	cin >> radius >> height;
	Column column(radius, height);
	cout << fixed << setprecision(2);
	cout << "Sphere area: " << sphere.area() << endl;
	cout << "Sphere volume: " << sphere.volume() << endl;
	cout << "Column area: " << column.area() << endl;
	cout << "Column volume: " << column.volume() << endl;
	return 0;
}