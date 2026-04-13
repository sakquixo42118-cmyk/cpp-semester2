#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class Vehicle
{
    public:
    int weight;

    Vehicle(int a):weight(a){
        cout<<"载入 Vehicle 类构造函数"<<endl;
    };
    void setWeight(int a)
    {
      cout<<"重新设置重量"<<endl;
        weight =a;
    }
    virtual void display ()
    {
        cout<<weight;
    };
};

class Car:virtual public Vehicle
{
   public:
   int aird;
   Car(int a,int b):Vehicle(a),aird(b){
    cout<<"载入 Car 类构造函数"<<endl;
   };
   void setAird(int a)
    {
       cout<<"重新设置空气排量"<<endl;
        aird =a;
    }

};

class Boat:virtual public Vehicle
{
   public:
   float tonnage;
   Boat(int a,float b):Vehicle(a),tonnage(b){
    cout<<"载入 Boat 类构造函数"<<endl;
   };
   void setTonnage(float a)
    {
       cout<<"重新设置排水量"<<endl;
        tonnage =a;
    }
    
};

class AmphibianCar :public Car,public Boat
{
   public:
   AmphibianCar(int a,int b,float c):Vehicle(a),Car(a,b),Boat(a,c){
    cout<<"载入 AmphibianCar 类构造函数"<<endl;
   };
   void display()override{
    cout<<"重量："<<weight<<"吨，空气排量："<<aird<<"CC，排水量："<<tonnage<<"吨"<<endl;
   }
   void setAmphibianCar(int a,int b,float c)
   {
    setWeight(a);
    setAird(b);
    setTonnage(c);
    display();
   }
};

int main()
{
	int weight, aird;
	float tonnage;
	cin >> weight >> aird >> tonnage;
	AmphibianCar a(weight, aird, tonnage);
	a.display();
	cin >> weight >> aird >> tonnage;
	a.setAmphibianCar(weight, aird, tonnage);
}