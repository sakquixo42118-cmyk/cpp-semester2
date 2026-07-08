#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main ()
{
  ifstream ifs ("source.txt",ios_base::in);
  ofstream ofs ("dest.txt",ios_base::out);
  string line;
  while (getline(ifs,line))
  {
     ofs<<line<<endl;
  }
  ifs.close();
  ofs.close();
}