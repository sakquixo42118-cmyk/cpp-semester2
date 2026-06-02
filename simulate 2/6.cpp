#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>  
#include <vector>
#include <sstream>
using namespace std;

template<typename T>
class Matrix
{
   public:
    vector <vector<T>>  ma ;  //二维矩阵的格式错误！！！！
    int row;
    int col;
   
   Matrix (int a,int b):ma(a,vector<T>(b)){row=a;col=b;};//不要忘记加括号,位置也不要搞错！！
   Matrix (vector<vector<T>> in){ ma=in;
        row=in.size();
        col=in[0].size();
       };                         //这里也要加上row和col的赋值

   void fill ()
   {
    
   
    for (int i=0;i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
            cin>>ma[i][j];
        }
    }
   }
   
   Matrix operator+ (Matrix b)
    {
        vector<vector<T>> out  (row,vector<T> (col));
        for (int i=0;i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
           out[i][j]=ma[i][j]+b.ma[i][j];
        }
    }
    return Matrix(out);
    }
   

   friend ostream& operator<< (ostream& out ,Matrix in)
   {
    for (int i=0;i<in.row;i++)
    {
        for (int j=0;j<in.col;j++)
        {
            out<<in.ma[i][j]<<" ";
        }
        if (i!=in.row-1)
        {
            cout<<endl;
        }
    }
   return out;
 }

   Matrix operator* (Matrix b)
    {
        vector<vector<T>> out (row,vector<T> (b.col));
        for (int i=0;i<row;i++)
    {
        for (int j=0;j<b.col;j++)
        {
           int temp=0;
           for (int p=0;p<col;p++)
           {
            temp+=ma[i][p]*b.ma[p][j];
           }
           out[i][j]=temp;

        }
    }
return Matrix(out);   
}
   

};

int main() {
    int r1, c1, r2, c2;
    while(cin >> r1 >> c1) {
        Matrix<long long> a(r1, c1); a.fill();
        cin >> r2 >> c2;
        Matrix<long long> b(r2, c2); b.fill();
        if(r1 == r2 && c1 == c2) cout << a + b << endl;
        cout << a * b << endl;
    }
    return 0;
}