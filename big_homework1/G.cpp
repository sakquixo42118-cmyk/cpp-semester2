using namespace std;
#include <vector>
#include <iostream>
#include <string>

int scan (string in)
{
    int count=0;
    int length=in.size();
    for (int i=0;i<length-2;i++)
    {
        if (in[i]=='C')
        {
            for (int j=i+1;j<length-1;j++)
            {
                if (in[j]=='H')
                {
                    for (int k=j+1;k<length;k++)
                    {
                        if (in[k]=='N')
                        {
                             count++;
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main (){
    string in;
    while (cin>>in)
    {
    int count= scan(in);
    cout<<count<<endl;
    }
}