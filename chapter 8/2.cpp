#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Array
{
  public:
    int a;
  int b;
  vector<int> arr ;

  void input_array1(int,int);
  void input_array2(int,int);
  void show();
  Array operator+ (Array);
  Array operator- (Array);

};

void Array::input_array1(int row, int col)
{
    a=row;
    b=col;
    arr.clear();
    for (int i=0;i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
    }
}

void Array::input_array2(int row, int col)
{
     a=row;
    b=col;
    arr.clear();
    for (int i=0;i<a;i++)
    {
        for (int j=0;j<b;j++)
        {
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
    }
}

Array Array::operator+ (Array a2)
{
    Array out;
    out.a=a;
    out.b=b;
    for (int i=0;i<a;i++)
    {
        for (int j=0;j<b;j++)
        {
          out.arr.push_back(arr[b*(i)+j]+a2.arr[b*(i)+j]);
        }
    }
    return out;
}

Array Array::operator- (Array a2)
{
    Array out;
    out.a=a;
    out.b=b;
    for (int i=0;i<a;i++)
    {
        for (int j=0;j<b;j++)
        {
          out.arr.push_back(arr[b*(i)+j]-a2.arr[b*(i)+j]);
        }
    }
    return out;
}

void Array::show()
{
    for (int i=0;i<a;i++)
    {
        for (int j=0;j<b;j++)
        {
            cout<<arr[b*(i)+j]<<" ";
        }
    }
}

int main() {
	Array rr, aa, p3;
	int a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		rr.input_array1(a, b);
		aa.input_array2(c, d);
		p3 = rr + aa;
		cout << "Addition result:";
		p3.show();
		cout << " ";
		p3 = rr - aa;
		cout << "Subtraction result:";
		p3.show();
		cout << endl;
	}
	return 0;
}