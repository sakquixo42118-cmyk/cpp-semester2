#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;



class Circle
{
  public:
  double r;
  double square;

  Circle (double in);
   
};

Circle ::Circle(double in)
{
    r=in;
    square=3.14*r*r;
}

class Table
{
 public:
 double height;

 Table (double in):height(in){};
};

class RoundTable:public Circle,public Table{
   public:
    string color;
    
    RoundTable (double a,double b,string c):Circle(a),Table (b),color(c){};
    double fun()
    {
        return square;
    }
    void print()
    {
        cout<<"height:"<<height<<endl;
        cout<<"area:"<<square<<endl;
        cout<<"color:"<<color<<endl;
    }
};

int main() {
	cout << "please input the data of round table:" << endl;
	int r, h;
	char c[100];
	cout << "radius:" << endl;
	cin >> r;
	cout << "height:" << endl;
	cin >> h;
	cout << "color:" << endl;
	cin.get();
	cin.getline(c, 100);
	RoundTable rt = RoundTable(r, h, c);
	rt.print();
	return 0;
}