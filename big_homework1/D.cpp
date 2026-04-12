using namespace std;
#include <cmath>
#include <iostream>
int main ()
{
    int x;
    int n;
    while (cin>>x>>n)
    {
         int sum=0;
         int currnt=0;
         bool ovfl=0;
         for (int i=n;i>=0;i--)
         {
            
            if (sum>2147483647-currnt)
            {
               
                ovfl=1;
                break;
            }
            if (int (pow(x,n))>2147483647)
            {
                ovfl=1;
                break;
            }
            currnt = int(pow(x,i));
            sum+=currnt;
            
         }
        if (ovfl)
        {
             cout<<"Overflow"<<endl;
             continue;
        }
        else 
        {
            
            cout<<sum<<endl;

        }    
    }
}