#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>  
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Polynomial
{
  public:
    vector <int> xishu;
  int quant;

  Polynomial (int n,vector<int> in)
  {
    xishu=in;
    quant=n;
  }

  long long unsigned int value (int x)
  {
    long long unsigned int total=0 ;
    for (int i=0;i<xishu.size();i++)
    {
     total+= pow (x,i)*xishu[i];
    }
    return total;
  }

  void print ()
  {
    for (int i=0;i<xishu.size();i++)
    {cout<<xishu[i]<<" ";}
  cout<< endl;

}
  


};


int main() {
    int n, x;
    while (cin >> n) {
        vector<int> coef(n + 1);
        for (int i = 0; i <= n; i++) {
            cin >> coef[i];
        }
        cin >> x;
        Polynomial p(n, coef);
        p.print();
        cout << p.value(x) << endl;
    }
    return 0;
}