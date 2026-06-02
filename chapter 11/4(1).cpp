#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;



template <typename T>
vector <T> computeProductVector (vector <T> in)
{
    vector <T> out;
    int result=1;
    for (size_t i=0;i<in.size ();i++)
    {
     result *=in[i]; 
    }
    out.push_back(result);
    return out;
}


int main() {
	int n;
	while (cin >> n) {
		vector<int> vec(n);
		for (int i = 0; i < n; ++i) {
			cin >> vec[i];
		}
// 函数模板vector<T> computeProductVector(const vector<T>& input)
		auto result = computeProductVector(vec);
		for (size_t i = 0; i < result.size(); ++i) {
			if (i > 0) cout << " ";
			cout << result[i];
		}
		cout << endl;
	}
	return 0;
}