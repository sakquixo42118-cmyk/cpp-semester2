#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;

class Shape
{
   public:

   
   string name;
   double area;

   virtual string getName ()=0;
   virtual double getArea ()=0;
};

class Circle:public Shape{
  public:
    double r;

  Circle (double a):r(a){};

  string getName ()
  {
    return "Circle";
  }
  double getArea ()
  {
    return 3.14*r*r;
  }
};

class Rectangle:public Shape{
    public:
    double l;
    double w;

    Rectangle(double a,double b):l(a),w(b){};

    string getName ()
  {
    return "Rectangle";
  }
  double getArea ()
  {
    return l*w;
  }

};

int main() {
	double r, l, w;
	while (cin >> r >> l >> w) {
		Shape* s1 = new Circle(r);
		Shape* s2 = new Rectangle(l, w);
		cout << fixed << setprecision(2);
		cout << s1->getName() << " area = " << s1->getArea() << endl;
		cout << s2->getName() << " area = " << s2->getArea() << endl;
	}
	return 0;
}