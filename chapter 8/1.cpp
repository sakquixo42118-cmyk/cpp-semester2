#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Time
{
  public:
  int hour;
  int minute;
  int second;

  void display();
  Time operator- (Time);
  Time operator+ (Time);
  bool operator< (Time);
  bool operator> (Time);
  Time (int h,int m,int s);
};

Time::Time(int h,int m,int s)
{
second=0;
minute=0;
hour=0;
  if (s>=60)
{
  second=s-60;
  minute++;
}
else{
  second=s;
}
if (minute+m>=60)
{
  minute=minute+m-60;
  hour++;
}
else{
  minute=m;
}
hour=hour+h;
}

Time Time::operator+ (Time t2)
{
 int sefina =t2.second+second;
 int minfina =t2.minute+minute;
 int houfina =t2.hour+hour;
 if (sefina>=60)
 {
  sefina=sefina-60;
  minfina++;
 }
 if (minfina>=60)
 {
  minfina-=60;
  houfina++;
 }
 return Time(houfina,minfina,sefina);
}

bool Time::operator< (Time t2)
{
  if (hour<t2.hour)
  {
    return 1;
  }
  if (hour>t2.hour)
  return 0;
  if (hour==t2.hour)
  {
    if (minute<t2.minute)
  {
    return 1;
  }
  if (minute>t2.minute)
  return 0;
  if (minute==t2.minute)
  {
    if (second<t2.second)
  {
    return 1;
  }
  if (second>t2.second)
  return 0;
  if (second==t2.second)
  return 0;
  }
  }
}

bool Time::operator>(Time t2)
{
   if (hour>t2.hour)
  {
    return 1;
  }
  if (hour<t2.hour)
  return 0;
  if (hour==t2.hour)
  {
    if (minute>t2.minute)
  {
    return 1;
  }
  if (minute<t2.minute)
  return 0;
  if (minute==t2.minute)
  {
    if (second>t2.second)
  {
    return 1;
  }
  if (second<t2.second)
  return 0;
  if (second==t2.second)
  return 0;
  }
  }
}

Time Time::operator- (Time t2)
{
  int fise;
  int fimi;
  int fiho;
  if (second-t2.second<0)
  {
    fise=second+60-t2.second;
    minute--;
  }
  else {
    fise=second-t2.second;
  }
  if(minute-t2.minute<0)
  {
    fimi=minute+60-t2.minute;
    hour--;
  }
  else{
    fimi=minute-t2.minute;
  }
  fiho=hour-t2.hour;
  return Time(fiho,fimi,fise);
}

void Time::display()
{
  cout<<hour<<':'<<minute<<':'<<second;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int h, m, s;
		cin >> h >> m >> s;
		Time time1(h, m, s);
		cin >> h >> m >> s;
		Time time2(h, m, s);
		(time1 + time2).display();
		cout << " ";
		if (time1 > time2)
		{
			(time1 - time2).display();
		}
		else
		{
			(time2 - time1).display();
		}
		cout << endl;
	}
}