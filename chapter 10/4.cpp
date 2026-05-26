#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;

class card 
{
 public:
 double price;
 double discount;
 double left;

 card (double a):price(a){};
 virtual void setDiscount (double)=0;//纯虚函数和后面的实函数的名字，return和参数必须全部相同，不然就没有办法成功创建实体对象
 virtual void setType ()=0;
 virtual void consume ()=0;
};

class olderCard:public card{
  public:
    olderCard (double a):card(a){left=100;};
    void setDiscount(double b)
    {
        discount=b;
    }
    void setType ()
    {
     cout<<"OLDER"<<" ";
    }
    void consume ()
    {
        if (left>=price*discount)
        {
            cout<<price*discount<<endl;
            left-=price*discount;
        }
        else 
        {
            cout<<"Please recharge!"<<endl;
        }
    }
};

class studentCard:public card{
  public:
    studentCard (double a):card(a){left=100;};
    void setDiscount(double b)
    {
        discount=b;
    }
     void setType ()
    {
     cout<<"STUDENT"<<" ";
    }
    void consume ()
    {
        if (left>=price*discount)
        {
            cout<<price*discount<<endl;
            left-=price*discount;
        }
        else 
        {
            cout<<"Please recharge!"<<endl;
        }
    }
};

class commonCard:public card{
  public:
    commonCard (double a):card(a){left=100;};
    void setDiscount(double b)
    {
        discount=b;
    }
     void setType ()
    {
     cout<<"COMMON"<<" ";
    }
    void consume ()
    {
        if (left>=price*discount)
        {
            cout<<price*discount<<endl;
            left-=price*discount;
        }
        else 
        {
            cout<<"Please recharge!"<<endl;
        }
    }
};

int main() {
	double o, s, c, p;
	int n;
	cin >> o >> s >> c >> p;
	olderCard O(p); O.setDiscount(o);
	studentCard S(p); S.setDiscount(s);
	commonCard C(p); C.setDiscount(c);
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			O.setType(); O.consume();
			S.setType(); S.consume();
			C.setType(); C.consume();
		}
	}
	return 0;
}