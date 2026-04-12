#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class Point 
{
    public:
    int x;
    int y;
    
    Point (int a ,int b):x(a),y(b){};
};

class Circle:public Point
{
   public:
    int r;

   Circle (int a,int b,int c):Point (a,b),r(c){};
   double area()
   {
    return 3.14*r*r;
   }
   double perimeter()
   {
    return 3.14*2*r;
   }
};

class Cylinder:public Circle
{
  public:
  int h;

  Cylinder (int a,int b,int c,int d):Circle(a,b,c),h(d){};//如果这里是不是虚继承的话，那么不用写POint的构造函数
  double area ()
  {
    return Circle::perimeter()*(r+h);
  }
  double volume()
  {
    return Circle::area()*h;
  }
  void setHeight(int in)
  {
    h=in;
  }
  void setRadius(int in)
  {
    r=in;
  }
  void setPoint(int xx,int yy)
  {
    x=xx;
    y=yy;
  }
  friend ostream& operator<< (ostream& ,Cylinder);
};

ostream& operator<< (ostream& out,Cylinder i)
{
    out<<i.area()<<" "<<i.volume();
    return out;
}

int main()
{
	int x, y, r, h;
	cin >> x >> y >> r >> h;
	Cylinder cy1(x, y, r, h);
	cout << cy1.area() << " " << cy1.volume() << endl;
	cin >> x >> y >> r >> h;
	cy1.setHeight(h);
	cy1.setRadius(r);
	cy1.setPoint(x, y);
	cout << cy1;
	return 0;
}