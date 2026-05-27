#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>  
using namespace std;

class Battery
{
  public:
    int charge;
  int capacity;
  int efficiency;

  Battery (int a,int b,int c):charge(a),capacity(b),efficiency(c){};

  Battery operator+ (Battery b)
  {
    int neweff;
    if (efficiency>=b.efficiency)
    {
        neweff=b.efficiency;

    }
    else 
    {
        neweff=efficiency;
    }
    return Battery(charge*efficiency/100+b.charge*b.efficiency/100,capacity+b.capacity,neweff);
  }

  friend Battery& operator++ (Battery& self)//复习自增的几种类型,友元自增的参数要加上引用
  {
    if(self.charge+self.efficiency<=self.capacity)
    {
        self.charge+=self.efficiency;
    }
    else
    {
        self.charge=self.capacity;
    }
    return self;
  }

  bool operator== (Battery other)
  {
    if (charge==other.charge)
    return 1;
    else
    return 0;
  }

  friend ostream& operator<< (ostream& outt,Battery in)//忘记了！！！这里的参数必须把ostream和istream放在前面！！！
  {
    outt<<"Battery(charge="<<in.charge<<", capacity="<<in.capacity<<", efficiency="<<in.efficiency<<"%)"<<endl; 
    return outt;
  }
};

int main()
{
    int a,b,c,d,e,f;
    while (cin>>a>>b>>c>>d>>e>>f)
    {
     Battery fir(a,b,c);
     Battery sec(d,e,f);
     cout<<"b1 = ";
     cout << fir;
     cout<< "b2 = "<<sec;
     Battery thi=fir+sec;
     cout<<"b3 = b1 + b2 = "<<thi;
     ++thi;
     cout<<"++b3 = "<<thi;
     if (fir==sec)
     cout<<"b1 和 b2 电量相等"<<endl;
     else
     cout<<"b1 和 b2 电量不相等"<<endl;
    }
    return 0;
}