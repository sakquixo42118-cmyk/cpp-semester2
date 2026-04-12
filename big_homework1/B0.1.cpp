using namespace std;
#include <vector>
#include <iostream>
#include <iomanip>


float sum (vector<int> in)
{
    vector<int> chongfushu (in.size());
    vector <int> index (in.size());
    int j,k;
    int length=in.size();
    for (int i=0;i<length;i++)
    {
       index[i]=i;
    }
    for (int i=0;i<length;i++)
    {
        chongfushu[i]=0;
    }
    for (j=0;j<length-1;j++)
    {
        for (k=j+1;k<length;k++)
        {
            if (in[j]==in[k])
            {
                chongfushu[j]+=1;
            }
        }
    }
        for (int n=0;n<length-1;n++)
        {
        if (chongfushu[n]>chongfushu[n+1])//用选择排序（直接找最大的那个会更好）
                                          //int max_index =0
                                          //for (int i=0;i<length;i++)
                                          //{if (chongfushu[i]>chongfushu[max_index])
                                          //    {max_index=i}}
        {
            int temp1=chongfushu [n];
            chongfushu [n]=chongfushu [n+1];
            chongfushu [n+1]=temp1;
            int temp2 = index [n];
            index [n]=index [n+1];
            index [n+1]=temp2;
                }
        }

    vector<int> out ;
    out.push_back(in[index[length-1]]);
    for (int i=0;i<length;i++)
    {
        if (in[i]!=in[index[length-1]])
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
        if ((in.size())==1)
        {
            cout<<fixed<<setprecision(2)<<in[0]<<endl;
            continue;
        }
          
        cout<<fixed<<setprecision(2)<< sum (in)<<endl;

   
    }
}