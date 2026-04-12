#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class Matrix
{
    public:
    int a;
    int b;
    vector<vector<int>> ma ;//直接写vector<vector<int>> ma (int a,vector<int>(b))会被当成函数

    Matrix (int aa,int bb):a(aa),b(bb),ma(aa,vector<int>(bb)){};//ma直接卸载初始化列表会更好，若想要在构造函数内部进行初始化的话就需要再次创造一个二维向量并对ma进行赋值，不够自然
    
    
    vector<int>& operator[] (int);//不需要int& operator[] (vector<int>&); 首先这么写就补兑，因为下标的参数应该是int，其次只需要上面一个就可以解决问题了
                                  //因为返回了vector《int》之后就可以正常使用下标访问而不使用重载了
    
    friend Matrix operator+ (Matrix,Matrix);
    friend Matrix operator* (Matrix,Matrix);
    friend ostream& operator<< (ostream&,Matrix);
    int getRows(){ return a;};
    int getColumns() {return b;};
};

vector<int>& Matrix::operator[] (int i)
{
    return ma[i];
}

Matrix operator+ (Matrix m1,Matrix m2)
{
  Matrix out(m1.a,m2.b);
    for (int i=0;i<m1.a;i++)
  {
    for (int j=0;j<m1.b;j++)
    {
     out.ma[i][j]=m1.ma[i][j]+m2.ma[i][j];
    }
  }
  return out;
}

Matrix operator* (Matrix m1,Matrix m2)
{
    Matrix out (m1.a,m2.b);
    int temp;
    for (int i=0;i<m1.a;i++)
    {
     for (int j=0;j<m2.b;j++)
     {
         temp=0;
        for (int k=0;k<m1.b;k++)
        {
                temp+=m1.ma[i][k]*m2.ma[k][j];
           
        }
        
        out.ma[i][j]=temp;
     }
    }
    return out;
}

ostream& operator<< (ostream& out,Matrix m)
{
 for (int i=0;i<m.a;i++)
 {
    for (int j=0;j<m.b;j++)
    {
        out<<m.ma[i][j];
        out<<" ";
    }
    out<<endl;
 }
return out;
}

int main() {
	int a, b;
	cin >> a >> b;
	Matrix m1(a, b), m2(a, b), m3(b, a);
	int i, j;
	for (i = 0; i < m1.getRows(); i++)
		for (j = 0; j < m1.getColumns(); j++)
			cin >> m1[i][j];
	for (i = 0; i < m2.getRows(); i++)
		for (j = 0; j < m2.getColumns(); j++)
			cin >> m2[i][j];
	for (i = 0; i < m3.getRows(); i++)
		for (j = 0; j < m3.getColumns(); j++)
			cin >> m3[i][j];
	cout << "Matrix M1:" << endl;
	cout << m1;
	cout << "Matrix M2:" << endl;
	cout << m2;
	cout << "Matrix M3:" << endl;
	cout << m3;
	cout << "Result of Matrix Addition:" << endl;
	cout << m1 + m2;
	cout << "Result of Matrix Multiplication:" << endl;
	cout << m1 * m3;
	return 0;
}