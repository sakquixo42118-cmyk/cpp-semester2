using namespace std;
#include <vector>
#include <iostream>
#include <cmath>

int weishu (int in)
{
    int weishu=0;
    while (in>0)
    {
     in/=10;
     weishu++;
    }
    return weishu;
}

vector <int> convert (int in)
{
   int wei =weishu(in);
    vector <int> store;
   
    for (int i=0;i<wei;i++)
   {
     int temp= in/(int(pow(10,wei-1-i)));
     if (temp%2==1)
     {
      store.push_back(1);
     }
     else {
        store.push_back(0);
     }
     in=in%(int(pow(10,wei-1-i)));
    }
    return store;
}

int main (){
    int input;
    while (cin>>input)
    {
        vector <int> store=convert(input) ;
        int weishu = store.size();
        int i=0;
        while ((store[i]==0)&&(i<weishu-1))
            {
                i++;
            }
        for (;i<weishu;i++)
        {
            
            cout<<store[i];
        }
        cout<<endl;
    }
}