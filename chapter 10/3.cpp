#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;

class Person
{
  public:
  static int MaleCnt;
  static int FemaleCnt;

  virtual void info ()=0;
  

};

class Male:public Person
{
  public:
  string Mname;
  int Mage;

  Male (string a,int b):Mname(a),Mage(b){MaleCnt ++;};

  void info ()
  {
    string Oname=Mname; 
	for (char &ch : Oname) {
        ch = toupper(ch); //如果想用小写的，那么就要加上tolower
    }
    cout<<"Male "<<Oname<<" "<<Mage<<endl;
  }
  static void stat() //要加上静态？？？
  {
	cout<<MaleCnt<<" ";
  }
};

class Female:public Person
{
  public:
  string Fname;
  int Fage;

  Female (string a,int b):Fname(a),Fage(b){FemaleCnt ++;};

  void info ()
  {
    string Oname=Fname; 
	for (char &ch : Oname) {
        ch = toupper(ch);
    }
    cout<<"Female "<<Oname<<" "<<Fage<<endl;
  }
  static void stat()
  {
	cout<<FemaleCnt;
  }

};


string toUpperCase (string a)
{
  for (char &nnew :a)
  {
    nnew =toupper(nnew);//要加上cctype的头文件
  }
  return a;
}

int Person::MaleCnt = 0;
int Person::FemaleCnt = 0;//静态成员需要提前定义！！！！

int main() {
	string line;
	while (getline(cin, line)) {
		istringstream iss(line); //这是什么东西？？？？ /////要加上sstream的头文件
		string gender;
		string name;
		int age;
		Person* person = NULL;
		iss >> gender >> name >> age;
		if (gender == "M") {
			person = new Male(toUpperCase(name), age);
		}
		else if (gender == "F") {
			person = new Female(toUpperCase(name), age);
		}
		if (person) {
			person->info();
			delete person; // 释放动态分配的内存
		}
	}
	Male::stat();
	Female::stat();
	return 0;

	}