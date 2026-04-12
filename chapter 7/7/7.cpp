#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class BigNumber 
{
    public:
    string num1;
    string num2;

    string add();
    string multiply();
    string addm(string ,string);
    BigNumber (string a,string b):num1(a),num2(b){};
};

string BigNumber::add()
{
    return addm(num1, num2);
}

string BigNumber::multiply()
{
  string shorter,longer;
  string temp;
  string sum;
  if (num1.size()<num2.size())
  {
    shorter=num1;
    longer =num2;
  }
  else{
    shorter =num2;
    longer =num1;
  }
  for (int i=shorter.size()-1;i>-1;i--)
  {
    for (int j=longer.size()-1;j>-1;j--)
    {
     temp=to_string(((shorter[i]-'0')*(int(pow(10,shorter.size()-i-1))))*((longer[j]-'0')*(int(pow(10,longer.size()-j-1)))));
      sum= addm(sum,temp);
    }
  }
  return sum;
}

string BigNumber::addm(string num1,string num2)
{
    string numm1(num1.size(),'0'), numm2(num2.size(),'0');

    for (int i = num1.size()-1; i >= 0; i--)
    {
        numm1[num1.size()-i-1] = num1[i];
    }

    for (int i = num2.size()-1; i >= 0; i--)
    {
        numm2[num2.size()-i-1] = num2[i];
    }

    int quant;
    int longg;
    string longer;

    if (num1.size() < num2.size())
    {
        quant = num1.size();
        longg = num2.size();
        longer = numm2;
    }
    else
    {
        quant = num2.size();
        longg = num1.size();
        longer = numm1;
    }

    string after(longg+1, '0');

    for (int i = 0; i < quant; i++)
    {
        int a = (numm1[i]-'0') + (numm2[i]-'0') + (after[i]-'0');
        if (a >= 10)
        {
            after[i+1] = char((after[i+1]-'0' + 1) + '0');
            after[i] = char((a - 10) + '0');
        }
        else
        {
            after[i] = char(a + '0');
        }
    }

    for (int i = quant; i < longg; i++)
    {
        int a = (longer[i]-'0') + (after[i]-'0');
        if (a >= 10)
        {
            after[i+1] = char((after[i+1]-'0' + 1) + '0');
            after[i] = char((a - 10) + '0');
        }
        else
        {
            after[i] = char(a + '0');
        }
    }

    int qquant;
    if (after[longg] == '0')
    {
        qquant = longg;
    }
    else
    {
        qquant = longg + 1;
    }

    string aafter;
    for (int i = qquant - 1; i >= 0; i--)
    {
        aafter.push_back(after[i]);
    }

    return aafter;
}

int main() {
	string num1, num2;
	while (cin >> num1 >> num2) {
		BigNumber bn(num1, num2);
		
        cout << bn.add() <<" ";
        cout << bn.multiply() << endl;
		
	}
	return 0;
}
