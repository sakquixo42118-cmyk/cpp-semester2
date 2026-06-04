#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>  
#include <vector>
#include <sstream>
using namespace std;


class StringCounter 
{
    public:
    string con;
    string a;
    vector <int> b;
    
    StringCounter(string in):con(in){};

    void compress ()  ///看清楚题目的要求，不要拿来就做
    {
        for (int i=0;i<con.size();)
        {
         if (!a.empty()&&a.back()!=con[i])
        {
            a.push_back(con[i]);
        }
         
            if (a.empty())
         {
            a.push_back(con[0]);
         }
         
        
        
         int quant=0;
         while (con[i]==a.back())
        {
           quant++;
           i++;
        }
        b.push_back(quant);
        
        
        }
    }

    void print ()
    {
        for (int i=0;i<a.size();i++)
        {
            cout<<a[i]<<b[i];
        }
        cout<<endl;
    }

};


int main(){
    string s;
    while(cin >> s){
        StringCounter sc(s);
        sc.compress();
        sc.print();
    }
    return 0;
}