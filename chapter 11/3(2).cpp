#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;


template <typename T,int SIZE>
class UniqueArray 
{
    public:

    vector <T> arr ;

    void readInput(size_t ss)
    {
        for (size_t i=0;i<ss;i++)
        {
            T temp;
            cin>>temp;
            arr.push_back(temp);
        }
    }

    void removeDuplicates()
    {
        vector <T> newarr;
        for (int i=0;i<arr.size();i++)
        {
            if (newarr.empty())
            {
                newarr.push_back(arr[i]);
            }
            bool in =0;
            for (int j=0;j<newarr.size();j++)
            {
               if (newarr[j]==arr[i])
               in=1;
            }
            if (!in)
            {
                newarr.push_back(arr[i]);
            }
        }
        arr=newarr;
    }

    void print ()
    {
        for (int i=0;i<arr.size();i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};



int main() {
	const size_t MAX_SIZE = 1000;
	int n;
	while (cin >> n) {
		UniqueArray<int, MAX_SIZE> arr;
		arr.readInput(static_cast<size_t>(n));
		arr.removeDuplicates();
		arr.print();
	}
	return 0;
}