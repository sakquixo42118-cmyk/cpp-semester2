#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class Fraction
{
    public:
    int num;
    int deno;

    Fraction(int ,int);
    void print();
};


Fraction::Fraction(int numm,int deno0)
{
    num=numm;
    deno=deno0;
}

void Fraction::print()
{
  int a; int b;
    if (num<0&&deno<0)
  {
    a=-num; b=-deno;
  }
    else{
     a=num; b=deno;
  }
    int min;
  if (fabs(num)>fabs(deno))
  {
    min=fabs(deno);
  }
  else{
     min=fabs(num);
  }
  for (int i=2;i<=fabs(min);i++)
  {
     if (a%i==0&&b%i==0)
     {
        a/=i;
        b/=i;
     }
    
    }
  cout<< a<<"/"<<b<<endl;

}

int main() {
    int numerator, denominator;
    while (cin >> numerator >> denominator)
    {
	Fraction myFraction(numerator, denominator);
	myFraction.print();
    }
    return 0;
}