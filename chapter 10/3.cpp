#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
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

};