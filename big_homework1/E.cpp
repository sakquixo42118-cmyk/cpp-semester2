using namespace std;
#include <iostream>
#include <vector>

int curve (vector<vector<int>> input,int row,int coll)
{
    vector<vector<int>> core(3,vector<int>(3));
    vector <int> core1(9);
    int index=0;
    for (int j=-1;j<=1;j++)
    {
        for(int k=-1;k<=1;k++)
        {
            core1[index]=input[row+j][coll+k];
            index++;
        }
    }
    return (core1[0]*1+core1[1]*-1+core1[2]*1+core1[3]*1+core1[4]*-1+core1[5]*-1+core1[6]*1+core1[7]*-1+core1[8]*-1);
}
int main(){
    int m,n;
    while(cin>>m>>n)
    {vector<vector<int>> input(m+2,vector<int>(n+2));
    for(int j=1;j<m+1;j++)
    {
        for(int k=1;k<n+1;k++)
        {
            cin>> input[j][k];
        }
    }
    vector<vector<int>> output(m,vector<int>(n));
    for(int j=1;j<m+1;j++)
    {
        for(int k=1;k<n+1;k++)
        {
            output[j-1][k-1]=curve(input,j,k);
        }
    }
    for(int j=0;j<m;j++)
    {
        for(int k=0;k<n;k++)
        {
            cout<<output[j][k]<<" ";
        }
        cout<<endl;
    }
}
}