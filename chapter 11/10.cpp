#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;

template <typename T>
class FilteredVector
{
    public:
    vector <T> con;
    int fil;

    FilteredVector (vector <T> in)
    {
        con=in;
    }

    vector <T> filterGreaterEqual (int n)
    {
        vector <T> out;
        for (int i=0;i<con.size();i++)
        {
            if (con[i]>=n)
            out.push_back(con[i]);
        }
        return out;
    }
};

int main() {
	int n;
	while (cin >> n) {
		vector<int> vec(n); 
		for (int i = 0; i < n; ++i) {
			cin >> vec[i];
		}
		int k;
		cin >> k; 
		FilteredVector<int> fv(vec);
		auto filtered = fv.filterGreaterEqual(k);
		for (size_t i = 0; i < filtered.size(); ++i) {
			if (i > 0) {
				cout << " "; 
			}
			cout << filtered[i];
		}
		cout << endl;
	}
	return 0;
}