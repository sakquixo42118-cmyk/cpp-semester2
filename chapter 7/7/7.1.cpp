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
    string addd(string ,string);
    BigNumber (string a,string b):num1(a),num2(b){};
};

string BigNumber::add ()
{
int lnger;
int smler;
string lng;
string sht;

if (num1.size()>num2.size())
{
    lnger=num1.size();
    smler=num2.size();
    lng= num1;
    sht=num2;
}
else{
    lnger=num2.size();
    smler=num1.size();
    lng= num2;
    sht=num1;
}
string out(lnger+1,'0');
int i;
int j;
for ( i=smler-1;i>-1;i--)
{
  int a= sht[i]-'0' +lng [lnger-1-(smler-1-i)]-'0';
  if (a + (out[lnger-(smler-1-i)]-'0') >=10)
  {
    out[lnger-1-(smler-1-i)]=char((out[lnger-1-(smler-1-i)]-'0'+1)+'0');
    out[lnger-(smler-1-i)] = char((a + (out[lnger-(smler-1-i)]-'0')-10)+'0' );
  }
  else{
    out[lnger-(smler-1-i)] = char((a + (out[lnger-(smler-1-i)]-'0'))+'0' );
  }


}

for ( j =lnger-1-(smler-1-i);j>-1;j--)//实际上i的值已经减去过一次了，不能是lnger-2-(smler-1-i)，会多减去1
{
   int b= lng[j]-'0';
   if (b + (out[j+1]-'0') >=10)
  {
    out[j]=char((out[j]-'0'+1)+'0');
    out[j+1] = char((b + (out[j+1]-'0')-10)+'0' );
  }
  else{
    out[j+1] = char((b + (out[j+1]-'0'))+'0' );
  }
}

int quant;
int h;
if (out[0]=='0')
{
  quant= out.size()-1;
  h=1;
}
else{
    quant=out.size();
    h=0;
}

string oout(quant,'0');
for (int b=0;b<quant;h++,b++)//这里的条件不要搞混淆了
{
    oout[b]=out[h];
}

return oout;
}

string BigNumber::addd (string numm1,string numm2)
{
int lnger;
int smler;
string lng;
string sht;

if (numm1.size()>numm2.size())
{
    lnger=numm1.size();
    smler=numm2.size();
    lng= numm1;
    sht=numm2;
}
else{
    lnger=numm2.size();
    smler=numm1.size();
    lng= numm2;
    sht=numm1;
}
string out(lnger+1,'0');
int i;
int j;
for ( i=smler-1;i>-1;i--)
{
  int a= sht[i]-'0' +lng [lnger-1-(smler-1-i)]-'0';
  if (a + (out[lnger-(smler-1-i)]-'0') >=10)
  {
    out[lnger-1-(smler-1-i)]=char((out[lnger-1-(smler-1-i)]-'0'+1)+'0');
    out[lnger-(smler-1-i)] = char((a + (out[lnger-(smler-1-i)]-'0')-10)+'0' );
  }
  else{
    out[lnger-(smler-1-i)] = char((a + (out[lnger-(smler-1-i)]-'0'))+'0' );
  }


}

for ( j =lnger-1-(smler-1-i);j>-1;j--)//实际上i的值已经减去过一次了，不能是lnger-2-(smler-1-i)，会多减去1
{
   int b= lng[j]-'0';
   if (b + (out[j+1]-'0') >=10)
  {
    out[j]=char((out[j]-'0'+1)+'0');
    out[j+1] = char((b + (out[j+1]-'0')-10)+'0' );
  }
  else{
    out[j+1] = char((b + (out[j+1]-'0'))+'0' );
  }
}

int quant;
int h;
if (out[0]=='0')
{
  quant= out.size()-1;
  h=1;
}
else{
    quant=out.size();
    h=0;
}

string oout(quant,'0');
for (int b=0;b<quant;h++,b++)//这里的条件不要搞混淆了
{
    oout[b]=out[h];
}

return oout;
}

string BigNumber::multiply()
{
int i,j,k;
int lnger;
int smler;
string lng;
string sht;

if (num1.size()>num2.size())
{
    lnger=num1.size();
    smler=num2.size();
    lng= num1;
    sht=num2;
}
else{
    lnger=num2.size();
    smler=num1.size();
    lng= num2;
    sht=num1;
}
string stemp;
vector <string> sum;
for (i=0;i<smler;i++)
{
    for (j=0;j<lnger;j++)
    {
      int temp= (lng[j]-'0')*(sht[i]-'0');
      stemp=to_string(temp);
      for (k=1;k<=lnger-1-j+(smler-1-i);k++)
      {
        stemp.push_back('0');
      }
      sum.push_back(stemp);
    }
}
string fina;
if (sum.size()==1)
{
    return sum[0];
}
fina=addd(sum[0],sum[1]);
for (int h=2;h<sum.size();h++)
{
    fina= addd(fina,sum[h]);
}
return fina;
}

int main() {
	string num1, num2;
	while (cin >> num1 >> num2) {
		BigNumber bn(num1, num2);
		cout << bn.add() << " ";
		cout << bn.multiply() << endl;
	}
	return 0;
}