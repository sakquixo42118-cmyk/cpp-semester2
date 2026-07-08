#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>  
#include <vector>
#include <sstream>
using namespace std;

int calPoints (vector<string> in)
{
  vector <int> zhan;
    for (int i=0;i<in.size();i++)
  {
     if (in[i][0]>='0'&&in[i][0]<='9'&&in[i].size()==1)//不能直接用isdigit 会忽略负数,要考虑多位数的情况
     zhan.push_back(in[i][0]-'0');
     if (in[i].size()>=2)       
     {

        zhan.push_back (stoi(in[i]));           //这个很好用，要记住！！
     }
     if (in[i]=="+")
     zhan.push_back(zhan[zhan.size()-1]+zhan[zhan.size()-2]);
     if (in[i]=="D")
     zhan.push_back((zhan.back())*2);
     if (in[i][0]=='C')
     {
        zhan.pop_back();
     }

  }
   
   int res=0;
   for (int temp:zhan)
   {

    res+=temp;
   }

   return res;

}


int main() {
    string line;
    // 逐行读取
    while (getline(cin, line)) {
        vector<string> ops; // 存储所有操作
	stringstream ss(line); // 把这一行变成流，需要#include <sstream>
        string s;
        // 按空格分割，存入当前行的数组
        while (ss >> s) {
            ops.push_back(s);
        }
	cout << calPoints(ops) << endl;
    }
}