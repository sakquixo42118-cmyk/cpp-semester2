#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

template <typename T>
class ccount
{
 public:
    T character;
 int count;
 ccount (T a):character(a){};
};

template <typename T>
vector<ccount<T>> countCharacters (basic_string<T> in)//用basic_string代表传进来的东西
{
 vector<ccount<T>> out;
 for (int i=0;i<in.size();i++)
 {
    if (out.empty())
    {
        out.push_back(ccount(in[i]));
        out[0].count=1;//out的下标和in是不一样的
        for (int j=i+1;j<in.size();j++)
        {
            if (in[j]==in[i])
            {
                out[0].count++;
            }
        }
        continue;
    }
    bool xiangtong = 0;
    for(int j=0;j<out.size();j++)
    {
        if (out[j].character==in[i])
        xiangtong =1;
    }
    if (!xiangtong)
    {
        out.push_back(ccount(in[i]));
        out.back().count=1;//用back访问最后一个元素
        for (int j=i+1;j<in.size();j++)
        {
            if (in[j]==in[i])
            {
                out.back().count++;
            }
        }
    }
 }
 return out;
}

int main() {
	string line;
	while (getline(cin, line)) {
// 函数模板vector<CharCount<CharType>> countCharacters(const basic_string<CharType>& str) ,CharType是自定义类型
		auto counts = countCharacters(line);// auto会根据返回值类型自动适配
		for (size_t i = 0; i < counts.size(); ++i) {
			if (i > 0) {
				cout << " ";
			}
			cout << counts[i].character << ":" << counts[i].count;
		}
		cout << endl;
	}
	return 0;
}