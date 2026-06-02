#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;

template <typename T>
basic_string <T> reverseString (basic_string <T> in)
{
    basic_string <T> out;

    for (int i=in.size()-1;i>=0;i--)
    {
        out.push_back(in[i]);
    }
    return out;
}


int main() {
	string line;
	while (getline(cin, line)) {
		// 函数模板basic_string<CharType> reverseString(const basic_string<CharType>& str)
		auto reversed = reverseString(line);
		cout << reversed << endl;
	}
	return 0;
}