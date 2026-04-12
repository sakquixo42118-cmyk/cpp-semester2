#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class Ternary
{
    public:
    vector<int> ter;

    Ternary(int);
    Ternary operator+ (Ternary);
    int operator[] (int);
    void display();
    int change ();
};

Ternary::Ternary (int in)
{
  int temp=in;
  vector <int> ttemp;
  while (temp>0)
  {
    ttemp.push_back(temp%3);
    temp=(temp-temp%3)/3;
  }
  int quant=ttemp.size();
  for(int i=quant-1;i>-1;i--)
  {
    ter.push_back(ttemp[i]);
  }
}

int Ternary::change ()
{
    int sum=0;
    for (int i=ter.size()-1;i>-1;i--)
    {
    sum+= ter[i]*int(pow(3,ter.size()-1-i));
    }
    return sum;
}

Ternary Ternary::operator+ (Ternary t2)
{
  return Ternary(change()+t2.change());
  
}

int Ternary::operator[] (int xxx)
{
    return ter[ter.size()-xxx-1];//看清楚题目
}

void Ternary::display()
{
    int quant=ter.size();
    for (int i=0;i<quant;i++)
    {
        cout<<ter[i];
    }
    cout<<endl;
}

int main() {
	int num1, num2;
	cin >> num1 >> num2;
	Ternary t1(num1), t2(num2);
	cout << t1[0] << ' ' << t2[0] << '\n';
	t1.display();
	t2.display();
	Ternary t3 = t1 + t2;
	t3.display();
	t1.display();
	return 0;
}