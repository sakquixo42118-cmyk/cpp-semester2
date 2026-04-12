using namespace std;
#include <vector>
#include <iostream>
#include <iomanip>
bool find (vector<int> in)
{

    int j,k;
    int length=in.size();
    for (j=0;j<length-1;j++)
    {
        for (k=j+1;k<length;k++)
        {
          if (in[j]==in[k])
           return 1;
        }
    }
    return 0;
}

float sum (vector<int> in)
{
    vector<vector<int>> chongfushu (in.size()+1,vector<int>(in.size()+1));
    int j,k;
    int length=in.size();
    for (int i=1;i<length+1;i++)
    {
        chongfushu[0][i]=i;
    }
    for (int i=1;i<length+1;i++)
    {
        chongfushu[i][0]=0;
    }
    for (j=0;j<length-1;j++)
    {
        for (k=j+1;k<length;k++)
        {
            if (in[j]==in[k])
            {
                chongfushu[j+1][0] +=1;
            }
        }
    }
        for (int n=1;n<length;n++)
        {
        if (chongfushu[n][0]>chongfushu[n+1][0])
        {
            int temp= chongfushu[0][n];
            chongfushu[0][n]=chongfushu[0][n+1];
            chongfushu[0][n+1]=temp;
        }
        }

    vector<int> out ;
    out.push_back(in[(chongfushu[0][length])-1]);
    for (int i=0;i<length;i++)
    {
        if (in[i]!=in[(chongfushu[0][length])-1])
        {
            out.push_back(in[i]);
        }
    }
    float sum=0;
        float aver=0;
        for (int h=0;h<out.size();h++)
        {
            sum+=out[h];
        }
        aver = sum/out.size();
        return aver;
}

int main ()
{
    int quant;
    while (cin>>quant)
    {
        vector <int> in (quant);
        for (int i=0;i<quant;i++)
        {
            cin>>in[i];
        }
        if (!find(in))
        {
        float sum=0;
         float aver=0;
            for(int i=0;i<quant;i++)
           {
            sum+=in[i];
           }
          aver=(sum/quant);
          cout<<fixed<<setprecision(2)<<aver<<endl;
          
        }
        else {             
        cout<<fixed<<setprecision(2)<< sum (in)<<endl;

        }
    }
}