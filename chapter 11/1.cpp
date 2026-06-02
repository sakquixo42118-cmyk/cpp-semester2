#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

template <typename T>
class SortedVector
{  
    public:
    vector <T> sv;

    SortedVector (vector<T> in):sv(in){};

    int binarySearch (T tar)
    {
     for (int i=0;i<sv.size();i++)
     {
        if (sv[i]==tar)
        return i;
     }
     return -1;
    }
    
};


int main() {
	int n;
	while (cin >> n) {
		vector<int> vec(n);
		for (int i = 0; i < n; ++i) {
			cin >> vec[i];
		}
		int target;
		cin >> target;
		SortedVector<int> sv(vec);
		int result = sv.binarySearch(target);
		cout << result << endl;
	}
	return 0;
}