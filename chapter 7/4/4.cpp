#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
using namespace std;

class STR 
{
 private:
 char*p;
 public:
 STR(char *s):p(s){};
 void move(char &t1, char &t2);
 void fun( );
 void print( );

};


void STR::print()
{
    int len=strlen(p);
   
        for (int i=0;i<len;i++)
        {
            cout<<p[i];
        }
        cout<<endl;
    
}

void STR::fun(){
    int len=strlen(p);
    for (int i=0;i<len/2;i++)
    {
        if (p[i]-'0'>=0&&p[i]-'0'<=9)
        {
            for (int j=len-1;j>len/2-1;j--)
            {
                if(p[j]-'0'>9)
                {
                    move (p[i],p[j]);
                    break;
                }
            }
        }
    }
}

void STR::move (char &a,char&b)
{
    char temp=a;
    a=b;
    b=temp;
}

int main() {
	char input[100];
	while (cin.getline(input, 100)) {
		STR s = STR(input);
		s.fun();
		s.print();
	}
	return 0;
}