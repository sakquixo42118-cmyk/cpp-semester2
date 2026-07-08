#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main()
{
    ifstream ifs("numbers.bin",ios_base::binary);
    vector <int> out;
    int temp;
    while (ifs.read((char *)&temp,sizeof(int)))
    {
        out.push_back(temp);
    }
    for (int i=1;i<=out.size();i++)
    {
        for (int j=0;j<out.size()-1-i;j++)
        {
            if (out[j]>out[j+1])
            {
                int tt=out[j];
                out[j]=out[j+1];
                out[j+1]=tt;
            }
        }
    }
    ofstream ofs ("numbers.bin",ios_base::binary|ios_base::app|ios_base::out);
    for (int i=0;i<out.size();i++)
    {
        ofs.write((char *)& out[i],sizeof(int));
    }
    ifs.close();
    ofs.close();

}
