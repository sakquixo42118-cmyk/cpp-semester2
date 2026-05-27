#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>  
#include <vector>
using namespace std;

class Clock
{
   public:
    int hour;
   int minute;
   int second;

   Clock (int a,int b,int c)
   {
     if (c>=60)
        {
           
           b+=c/60;
           c%=60;
            
        }
        if (b>=60)
        {
           
            a+=b/60;
             b%=60;
        }
        if (a>=24)
        {
            a%=0;///这个地方要用取余！！！
        }
       hour=a;minute=b;second=c;
   };

   friend ostream& operator<< (ostream& out,Clock a)
   {
     if (a.hour<10)
     out<<"0"<<a.hour<<":";//全部用out！
     else
     out<<a.hour<<":";
     if (a.minute<10)
     out<<"0"<<a.minute<<":";
     else
     out<<a.minute<<":";
     if (a.second<10)
     out<<"0"<<a.second;
     else
     out<<a.second;
     return out;
   }

   friend Clock& operator++ (Clock& a)
   {
    if (a.second==59)
    {
        a.second=0;
        a.minute++;
        if (a.minute==60)
        {
            a.minute=0;
            a.hour++;
            if (a.hour==24)
             a.hour=0;
        }
    }
    else
    a.second++;
    return a;
   }

   friend Clock operator++ (Clock a,int)
   {
    if (a.second==59)
    {
        a.second=0;
        a.minute++;
        if (a.minute==60)
        {
            a.minute=0;
            a.hour++;
            if (a.hour==24)
             a.hour=0;
        }
    }
    else
    a.second++;
    return a;
    }

    Clock operator+ (Clock b)
    {
        int nsec=second+b.second;
        int nmin=minute+b.minute;
        int nhou=hour+b.hour;
        if (nsec>=60)
        {
            nmin+=nsec/60;
            nsec%=60;
            
            
        }
        if (nmin>=60)
        {
           nhou+=nmin/60;
           nmin%=60;
        }
        if (nhou>=24)
        {
            nhou%=24;
        }
        return Clock (nhou,nmin,nsec);
    }

    bool operator== (Clock b)
    {
        if (hour==b.hour&&minute==b.minute&&second==b.second)
        return 1;
        else
        return 0;
    }


  

};

int main() {

    int h1, m1, s1, h2, m2, s2;

    while (cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2) {

        Clock c1(h1, m1, s1);

        Clock c2(h2, m2, s2);

        Clock c3 = c1 + c2;

        cout << "c1 = " << c1 << endl;

        cout << "c2 = " << c2 << endl;

        cout << "c1 + c2 = " << c3 << endl;

 

        ++c1;

        cout << "++c1 = " << c1 << endl;

 

        if (c1 == c2) {

            cout << "c1 和 c2 时间相等" << endl;

        }

        else {

            cout << "c1 和 c2 时间不相等" << endl;

        }

    }

    return 0;

}