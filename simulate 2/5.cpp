#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>  
#include <vector>
#include <sstream>
using namespace std;

class Fraction
{
  public:
    int son;
   int mom;

   Fraction(int a,int b):son(a),mom(b){};
   
static  Fraction fromStr (string in)   ///用静态函数来进行无类对象访问
   {
      string sonn;
      string momm;
      int i;
      for ( i=0;in[i]!='/';i++)
      {
        sonn.push_back(in[i]);
      }
      for (i++;i<in.size();i++)
      {
        momm.push_back(in[i]);
      }
      int sonnn=stoi(sonn);
      int mommm=stoi(momm);

      if (mommm<0)     //保证分母是正数
      {
        mommm*=-1;
        sonnn*=-1;
      }
      return Fraction(sonnn,mommm);
      
   }

    string operator+ (Fraction b)
    {
        int nson;
        int nmom;

        nmom=mom*b.mom;
        nson=son*b.mom+b.son*mom;

        if (nson==0)
        return "0";

        if (nson%nmom==0)
        {  int temp=nson/nmom;
        return to_string(temp);
        } 
        
        int max=abs(nson);
        if (nmom>max)
        {
            max=nmom;
        }   
        
        for (int i=2;i<max;)
        {
            while (abs(nson)%i==0&&nmom%i==0)  //加上绝对值！
            {
                nson/=i;    
                nmom/=i;
            }
            i++;
        }
        return to_string(nson)+"/"+to_string(nmom);
        
    }
    
    string operator- (Fraction b)
    {
        int nson;
        int nmom;

        nmom=mom*b.mom;
        nson=son*b.mom-b.son*mom;

        if (nson==0)
        return "0";

        if (nson%nmom==0)
        {  int temp=nson/nmom;
        return to_string(temp);
        } 
        
        int max=abs(nson);
        if (nmom>max)
        {
            max=nmom;
        }   
        
        for (int i=2;i<max;)
        {
            while (abs(nson)%i==0&&nmom%i==0)  //加上绝对值！
            {
                nson/=i;    
                nmom/=i;
            }
            i++;
        }
        return to_string(nson)+"/"+to_string(nmom);
    }


    string operator* (Fraction b)
    {
       int nson;
       int nmom;

       nson=son*b.son;
       nmom=mom*b.mom;
    
       if (nson==0)
        return "0";

        if (nson%nmom==0)
        {  int temp=nson/nmom;
        return to_string(temp);
        } 
        
        int max=abs(nson);
        if (nmom>max)
        {
            max=nmom;
        }   
        
        for (int i=2;i<max;)
        {
            while (abs(nson)%i==0&&nmom%i==0)  //加上绝对值！
            {
                nson/=i;    
                nmom/=i;
            }
            i++;
        }
        return to_string(nson)+"/"+to_string(nmom);
    
    }
          

    friend ostream& operator<< (ostream& out, Fraction in)
    {
        out<<in.son<<"/"<<in.mom;
        return out;
    }


};


int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        Fraction f1 = Fraction::fromStr(s1), f2 = Fraction::fromStr(s2);
        cout << f1+f2 << " "<< f1-f2 << " " << f1*f2 << endl;
    }
    return 0;
}