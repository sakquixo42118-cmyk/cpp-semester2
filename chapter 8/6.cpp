#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class RMB
{
    public:
    int yuan;
    int jiao;
    int fen;
    double d;
    bool mark;

    RMB (double in):d(in){
        yuan=int(in);
        jiao=int(int (in*10)%10);
        fen=int(int (in*100)%10);
    };
    
    RMB (int a,int b,int c):yuan(a),jiao(b),fen(c){
        d=a+0.1*b+0.01*c;
    };

    RMB (){yuan=0,jiao=0,fen=0,d=0; };

    friend RMB operator+ (RMB,RMB );
    RMB operator- (RMB);
    friend ostream& operator<< (ostream&,RMB);
    friend istream& operator>> (istream&,RMB&);
   
};

RMB operator+ (RMB r1,RMB r2 )
{
 r1.d=r1.yuan+0.1*r1.jiao+0.01*r1.fen;
 if (r2.d==0)
 {
    r2.d=r2.yuan+0.1*r2.jiao+0.01*r2.fen;
 }
 RMB out(r1.d+r2.d);
 return out;

 
}

RMB RMB::operator- (RMB r2 )
{
 d=yuan+0.1*jiao+0.01*fen;
 if (r2.d==0)
 {
    r2.d=r2.yuan+0.1*r2.jiao+0.01*r2.fen;
 }
 RMB out(d-r2.d);
 return out;

 
}

ostream& operator<< (ostream& out,RMB in)
{
    if (in.d==0)
    {
        in.d=in.yuan+0.1*in.jiao+0.01*in.fen;
    }
    out<< in.d;
    return out;
}

istream& operator>> (istream& out,RMB& in)//要加上引用！！！！！！！！
{
  
    int temp;
    out>>temp;
    in.yuan=temp;
    out>>temp;
    in.jiao=temp;
    out>>temp;
    in.fen=temp;
    return out;
}

int main()
{
	RMB a, b;
	double c;
	cout.setf(cout.showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	cin >> a;
	cin >> b;
	cin >> c;
	cout << RMB(a + c) << endl;
	cout << RMB(b - a) << endl;
	cout << RMB(2.18 + a) << endl;
	return 0;
}