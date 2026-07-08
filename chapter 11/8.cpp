#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;

template <typename T, size_t Max_SIZE>
class ArrayMax
{
public:
 vector <T> con;

 void readInput(size_t quant)
 {
    for (size_t i=0;i<quant;i++)
    {
        T temp;
        cin>>temp;
        con.push_back(temp);
    }
 }

  T findMax ()
 {
    T max=con[0];
    for (size_t i=0;i<con.size();i++)
    {
        if (con[i]>max)
        {
            max=con[i];
        }
    }
    return max;
  }


};

int main() {
	const size_t MAX_SIZE = 1000;
	int n;
	while (cin >> n) {
		ArrayMax<int, MAX_SIZE> arr;
		arr.readInput(static_cast<size_t>(n));
		cout << arr.findMax() << endl;
	}
	return 0;
}

