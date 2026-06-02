#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;


template <typename T> 
vector<T> squareVector(const vector<T>& in)
{
   vector <T> out;
   for (int i=0;i<in.size();i++)
   {
    out.push_back (in[i]*in[i]);
   }
   return out;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> vec(n);
		for (int i = 0; i < n; ++i) {
			cin >> vec[i];
		}
// 函数模板vector<T> squareVector(const vector<T>& input)
		auto squared = squareVector(vec);
		for (size_t i = 0; i < squared.size(); ++i) {
			if (i > 0) cout << " ";
			cout << squared[i];
		}
		cout << endl;
	}
	return 0;
}