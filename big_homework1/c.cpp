using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

int bintoten (string in)
{
    int length = in.size();
    int i;
    int sum=0;
    for (i=length-1;i>=0;i--)
    {
      sum+= (in[i]-'0')*(int (pow(2,length-i-1)));
    }
    return sum;
}

vector<int> tentobin (int in)
{
    vector <int> out;
    int present =in;
    while (present>0)
    {
    out.push_back(present%2);
    present= (present-(present%2))/2;
    }
    return out;
}



int main ()
{
string s1,s2;
while (cin>>s1>>s2)
{
  string s1bin,s2bin;
  int sum= bintoten(s1)+bintoten(s2);
  vector<int> bin=tentobin(sum);
  int len= bin.size();
  for (int i=len-1;i>=0;i--)
  {
    cout<<bin[i];
  }
  cout<<endl;
}
}