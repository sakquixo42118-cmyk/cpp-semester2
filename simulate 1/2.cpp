#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>  
using namespace std;

class MyDate 
{ 
    public:
    int year;
    int month;
    int day;
   MyDate(int a,int b,int c):year(a),month(b),day(c){};
};


class Person
{
   public:
    string name;
   string address;
   string phone ;
   string email;
   
   Person (string a,string b,string c,string d):name(a),address(b),phone(c),email(d){};

   string toString ()
   {
    cout<<"Person: "; 
    return name; 
   }

};

class Student:public Person{
   public:
    string status;
   Student (string a,string b,string c,string d,string e):Person(a,b,c,d),status(e){};

   string toString ()
   {
    cout<<"Student: ";
    return name; 
   }
};

class Employee:public Person{
     public:
     string office;
     double salary;
     MyDate hireDate;

     Employee(string a,string b,string c,string d,string e,double f,MyDate g)
     :Person(a,b,c,d),office(e),salary(f),hireDate(g){};

    string toString ()
   {
    cout<<"Employee: ";
    return name; 
   }
};

class Faculty:public Employee
{
    public:
    string officeHour;
    string rank;

    Faculty (string a,string b,string c,string d,string e,double f,MyDate g,string h,string i)
    :Employee(a,b,c,d,e,f,g),officeHour(h),rank(i){};

    string toString ()
   {
    cout<<"Faculty: ";
    return name; 
   }
};

class Staff :public Employee
{
    public:
    string title;

    Staff (string a,string b,string c,string d,string e,double f,MyDate g,string h)
    :Employee(a,b,c,d,e,f,g),title (h){};

    string  toString ()
   {
    cout<<"Staff: ";
    return name; 
   }
};

int main() {

    string p_name, p_address, p_phone, p_email;

    getline(cin, p_name);

    getline(cin, p_address);

    getline(cin, p_phone);

    getline(cin, p_email);

    Person person(p_name, p_address, p_phone, p_email);




    string s_name, s_address, s_phone, s_email, s_status;

    getline(cin, s_name);

    getline(cin, s_address);

    getline(cin, s_phone);

    getline(cin, s_email);

    getline(cin, s_status);

    Student student(s_name, s_address, s_phone, s_email, s_status);




    string e_name, e_address, e_phone, e_email;

    string e_office;

    double e_salary;

    int e_year, e_month, e_day;

    getline(cin, e_name);

    getline(cin, e_address);

    getline(cin, e_phone);

    getline(cin, e_email);

    getline(cin, e_office);

    cin >> e_salary >> e_year >> e_month >> e_day;

    cin.ignore();

    MyDate e_date(e_year, e_month, e_day);

    Employee employee(e_name, e_address, e_phone, e_email, e_office, e_salary, e_date);

 

    string f_name, f_address, f_phone, f_email;

    string f_office, f_officeHour, f_rank;

    double f_salary;

    int f_year, f_month, f_day;

 

    getline(cin, f_name);

    getline(cin, f_address);

    getline(cin, f_phone);

    getline(cin, f_email);

    getline(cin, f_office);

    cin >> f_salary >> f_year >> f_month >> f_day;

    cin.ignore();

    getline(cin, f_officeHour);

    getline(cin, f_rank);

 

    MyDate f_date(f_year, f_month, f_day);

    Faculty faculty(f_name, f_address, f_phone, f_email, f_office, f_salary, f_date, f_officeHour, f_rank);

 

    string st_name, st_address, st_phone, st_email;

    string st_office, st_title;

    double st_salary;

    int st_year, st_month, st_day;

 

    getline(cin, st_name);

    getline(cin, st_address);

    getline(cin, st_phone);

    getline(cin, st_email);

    getline(cin, st_office);

    cin >> st_salary >> st_year >> st_month >> st_day;

    cin.ignore();

    getline(cin, st_title);

 

    MyDate st_date(st_year, st_month, st_day);

    Staff staff(st_name, st_address, st_phone, st_email, st_office, st_salary, st_date, st_title);

 

    cout << person.toString() << endl;

    cout << student.toString() << endl;

    cout << employee.toString() << endl;

    cout << faculty.toString() << endl;

    cout << staff.toString() << endl;

 

    return 0;

}