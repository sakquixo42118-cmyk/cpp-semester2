using namespace std;
#include <iostream>
#include <string>
#include <vector>

bool find (string in,char target)
{
  if (in.find(target)==string::npos)
  {
    return 0;
  }
  else return 1;
}

string convert (string in,char target)
{
  
    int position=0;
  while (in[position]!=target)
  {
    position++;
  }
  string out=in;
  char temp;
  if ((position%2)==0)
  {
    for (int i=0;i<position/2;i++)
    {
        
        temp=out[i];
        out[i]=out[position-i];
        out[position-i]=temp; 
    }
  }
  else{
    for (int i=0;i<(position+1)/2;i++)
    {
         temp=out[i];
        out[i]=out[position-i];
        out[position-i]=temp; 
    }
  }
  return out;
}

int main ()
{
    string in;
    char target;
    while(cin>>in>>target)
    {
      if (!find(in,target))
      {cout<<"none"<<endl;
      continue;
      }
      else {
        cout<<convert(in,target)<<endl;
      }
    }
}