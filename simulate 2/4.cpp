#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>  
#include <vector>
#include <sstream>
using namespace std;

class Time 
{
    public:
    int H;
    int M;
    int S;

    Time (int a,int b,int c):H(a),M(b),S(c){


    };

    Time operator+ (const Time& b)
    {
        int ss=S+b.S;
        int mm=M+b.M;
        int hh=H+b.H;

        if (ss>=60)
        {
            mm+=ss/60;
            ss%=60;
        }
        if (mm>=60)
        {
            hh+=mm/60;
            mm%=60;
        }
        if (hh>=24)
        {
            hh%=24;
        }
        return Time (hh,mm,ss);
    }


    Time& operator++ ()
    {
       S++;
       if (S>=60)
        {
            M+=S/60;
            S%=60;
        }
        if (M>=60)
        {
           H+=M/60;
           M%=60;
        }
        if (H>=24)
        {
            H%=24;
        }
        return *this;
    }

    friend ostream& operator<< (ostream& out,Time in)
    {
        out<<setw(2)<<setfill('0')<<in.H<<":"<<setw(2)<<setfill('0')<<in.M<<":"<<setw(2)<<setfill('0')<<in.S;// 要记住这些关键的表达！
        return out;
    }

    
};

int main() {
    int h1, m1, s1, h2, m2, s2, n;
    while(cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2) {
        Time t1(h1, m1, s1), t2(h2, m2, s2);
        cout << (t1 + t2) << endl;
        cin >> n;
        while(n--) ++t1;
        cout << t1 << endl;
    }
    return 0;
}