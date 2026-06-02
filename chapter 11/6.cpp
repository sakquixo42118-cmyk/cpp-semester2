#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;



template <typename T>
class VectorSum
{
    public: 
  
    vector <T> con;

    VectorSum(vector<T> in)
    {
        con=in;
    }
  
  
    T computeSum ()
 {
    T out;
    int result=0;
    for (size_t i=0;i<con.size ();i++)
    {
     result +=con[i]; 
    }
    
    return result;
 }
};

int main() {
	int n;
	while (cin >> n) {
		vector<int> vec(n);
		for (int i = 0; i < n; ++i) {
			cin >> vec[i];
		}
		VectorSum<int> vs(vec);
		cout << vs.computeSum() << endl;
	}
	return 0;
}