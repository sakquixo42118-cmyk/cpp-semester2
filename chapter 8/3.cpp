#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Date
{
  public:
  int year;
  int month;
  int day;

  Date (int y,int m,int d):year(y),month(m),day(d){};
  int NthDay();
  Date operator+ (int);
  friend ostream& operator<< (ostream&,Date);
  bool isrun();
};

bool Date::isrun()
{
    if (year%4==0&&year%100!=0)
    return 1;
    if (year%400==0)
    return 1;
    else
    {
        return 0;
    }
}

int Date::NthDay()
{
    int sum=0;
    for (int i=1;i<=month;i++)
    {
        if(i!=month)
        {switch (i)//记得用swith
        {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            sum+=31;
            break;
            case 4:case 6:case 9:case 11:
            sum+=30;
            break;
            case 2:
            break;
        }
        }
        if (i==2&&isrun()&&i!=month)
        {
            sum+=29;
        }
        if(i==2&&!isrun()&&i!=month)
        {
            sum+=28;
        }
        if (i==month)
        {
            sum+=day;
        }
    }
    return sum;
}

Date Date::operator+ (int in)
{
    int left=in;
    while (left>0)
    {
       day++;left--;
       if ((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day==32)//不能用if i=1，2这样子的表述，只能用或
       {
        month++;
        day=1;
       }
       if ((month==4||month==6||month==9||month==11)&&day==31)
       {
        month++;
        day=1;
       }
       if(month==2&&isrun()&&day==30)
       {
        month++;
        day=1;
       }
       if(month==2&&!isrun()&&day==29)
       {
        month++;
        day=1;
       }
       if (month==13)
       {
        year++;
        month=1;
       }
    }
    return Date(year,month,day);
}

ostream& operator<< (ostream& out,Date in)
{
 out<<in.year;
 out<<" ";
 out<<in.month;
 out<<" ";
 out<<in.day;
 return out;
}


int main() {
	int year, month, day;
	while (cin >> year >> month >> day) {
		Date d(year, month, day);
		cout << d.NthDay() << endl;
		d = d + 1039;
		cout << d << endl;
	}
	return 0;
}