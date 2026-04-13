#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class Employee
{
  public:
  static int count;
  int id;
  int salary;
  int bonus;

  Employee (int a,int b):id(a),salary(b){};
  virtual void show()=0;
};

int Employee::count=0;//静态成员在类外进行初始化的时候要加上类型

class A :public Employee
{
   public:
   A (int a,int b):Employee(a,b){};
   void show () override{
    cout<<"Aid:"<<id<<" "<<"prize:"<<6000+5*salary-count*1000<<endl;
   }
};

class B :public Employee{
   public:
   B(int a,int b):Employee(a,b)
   {
    count++;
   }
   void show ()override{
    cout<<"Bid:"<<id<<" "<<"prize:"<<6000+3*salary<<endl;
   }
};

class C: public Employee
{
public:
   C(int a,int b):Employee(a,b){};
   void show ()override{
    cout<<"Cid:"<<id<<" "<<"prize:"<<6000+1*salary+count*1000<<endl;
   }
};

int main() {
	int id, sa;
	Employee* p;
	while (cin >> id >> sa) {
		if (id >= 1 && id <= 20) { // A 类员工
			A a(id, sa);
			p = &a;
			p->show();
		}
		else if (id >= 21 && id <= 100) { // B 类员工
			B b(id, sa);
			p = &b;
			p->show();
		}
		else if (id >= 101 && id <= 120) { // C 类员工
			C c(id, sa);
			p = &c;
			p->show();
		}
		else {
			return 0;
		}
	}
	return 0;
}
