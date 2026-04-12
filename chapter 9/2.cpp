#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class z
{
    public:
    int data;
    
    z(){data=0;};
    z (int a):data(a){};
    
};

class MyPoint 
{
    public:
    int x;
    int y;

    MyPoint (){x=0;y=0;};
    MyPoint (int a,int b):x(a),y(b){};
    virtual double distance()//用虚继承的方式确保覆盖
    {
        return sqrt(x*x+y*y);
    }
};

class Point3D:public z,public MyPoint
{
  public:

  Point3D ();
  Point3D(int a,int b,int c):z(c),MyPoint (a,b){};
  int getZ(){return data;};
  double distance ()
  {
    return sqrt(x*x+y*y+data*data);
  }
};

int main() {
	int flag, x, y, z;
	MyPoint* point = nullptr;
	while (cin >> flag) {
		if (1 == flag) {
			cin >> x >> y;
			point = new MyPoint(x, y);
		}
		else if (2 == flag) {
			cin >> x >> y >> z;
			point = new Point3D(x, y, z);
		}
		cout << fixed << setprecision(2);
		if (point != nullptr) {
			cout << point->distance() << endl;
		}
		delete point;
		point = nullptr;
	}
	return 0;
}