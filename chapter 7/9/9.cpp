#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class FilePath
{
   public:
   string path;

   FilePath(string in):path(in){};
   string simplifypath ();
};

string FilePath::simplifypath(){
   string newp;
   newp.push_back('/');
   int quant =path.size();
   for (int i=1;i<quant;)
   {
    if (path[i]=='.')
    {
       if(path[i+1]!=NULL&&path[i+1]=='/')
       {
        newp.push_back('^');
        i++;
        continue;
       }
        if(path[i+1]!=NULL&&path[i+1]=='.')
       {
        if (path[i+2]!=NULL&&path[i+2]=='/')
        {
            newp.push_back('<');
            i+=2;
            continue;
        }
       }
    }
    if (path[i]!='/')
    {
        newp.push_back(path[i]);
        i++;
        continue;
    }   
    i++;
}

vector<string> fina;
quant=newp.size();
 string temp;

for (int i=1;i<quant;)
{
   temp.clear();
   while(newp[i]!='.'&&(newp[i]!='^')&&newp[i]!='<'&&newp[i]!=NULL)
   {
     
      temp.push_back(newp[i]);
      i++;
   }
   if (!temp.empty())
   {fina.push_back(temp);}//temp需要非空
   if (newp[i]=='.')
   {
      fina.push_back("...");
      i++;
      continue;
   }
   if (newp[i]=='<'&&(!fina.empty()))
   {
      fina.pop_back();
      i++;
      continue;
   }
   if(newp[i]=='^')
   {
    i++;
    continue;
   }
  i++;
}

string finale;
quant=fina.size();
finale.push_back('/');
for (int i=0;i<quant;i++)
{
finale+=(fina[i]);
finale.push_back('/');
}
quant=finale.size();
if (finale[quant-1]=='/'&&finale.size()>=2)
{
   finale.pop_back();
}
return finale;
}

int main()
{
 string path;
 while (cin>>path)
 {
    FilePath fp(path);
    cout<<fp.simplifypath()<<endl;
 }
    }
