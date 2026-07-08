#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main ()
{
    string out;
    ifstream ifs ("normal.txt",ios_base::in);
    ofstream ofs ("reverse.txt",ios_base::out);
    char temp;
    while (ifs.get(temp))
    {
        out.push_back(temp);
    }
    for (int i=out.size()-1;i>-1;i--)
    {
        ofs<<out[i];
    }
    ifs.close();
    ofs.close();
}