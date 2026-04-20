#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class Vehicle
{
 public:


 virtual void display()=0;
};

class Car:public Vehicle
{
 public:
 int per;
 int weight;

 Car(int a,int b):per(a),weight(b){};

void display()
 {
   cout<< per*8+weight*2<<endl;
 }
};

class Truck:public Vehicle
{
 public:
 
 int weight;

 Truck(int a):weight(a){};

void display()
 {
    cout<<weight*5<<endl;
 }
};

class Bus:public Vehicle
{
 public:
 int per;
 

 Bus(int a):per(a){};

 void display()
 {
    cout<< per*3<<endl;
 }
};

int main()
{
	Vehicle* pd[10];
	int t, num, i = 0;
	double kg;
	cin >> t;
	while (t) {
		if (t == 1) {
			cin >> num >> kg;
			pd[i] = new Car(num, kg);
		}
		else if (t == 2) {
			cin >> kg;
			pd[i] = new Truck(kg);
		}
		else if (t == 3) {
			cin >> num;
			pd[i] = new Bus(num);
		}
		pd[i]->display();
		i++;
		cin >> t;
	}
	return 0;
}