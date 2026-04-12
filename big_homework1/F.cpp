using namespace std;
#include <vector>
#include <iostream>

vector <vector<int>> swap (vector<vector<int>> in,int a,int b,char oper,int n,int m)
{
  if (oper=='r')
{
  vector <int>temp;
  temp = in[a-1];
  in [a-1]=in[b-1];
  in[b-1]=temp;
  return in;
}
if (oper=='c')
{
    for (int i=0;i<n;i++)
    {
        int temp= in [i][a-1];
        in [i][a-1]=in [i][b-1];
        in[i][b-1]=temp;
    }
    return in;
}


}
int main (){
   int n,m;
   while (cin>>n>>m)
   {
    vector <vector<int>> in (n,vector<int>(m));
    for (int j=0;j<n;j++)
    {
        for (int k=0;k<m;k++)
        {
            cin>>in[j][k];
        }
    }
   char oper;
   int round;
   int a,b;
   cin>>round;
   vector <vector<int>> cur=in;
   for (int i=1;i<=round;)
   {
    
    cin>>oper;
    cin>>a>>b;
    if ((oper!='c')&&(oper!='r'))
    {
        i++;
        continue;
    }
    else{
        cur= swap(cur,a,b,oper,n,m);
    }
    i++;   
}   
   for (int j=0;j<n;j++)
   {
    for (int k=0;k<m;k++)
    {
        cout<<cur[j][k];
    }
    cout<<endl;   
    
}
}

}