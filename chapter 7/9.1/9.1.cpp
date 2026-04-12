#include <iostream>
#include <vector>
#include <string>
using namespace std;

class FilePath
{
public:
    string path;

    FilePath(string in) : path(in) {}
    
    string simplifyPath()
    {
    vector<string> fina;
        string cur;
        string out;
    int quant =path.size();
    for (int i=0;i<quant;)
    {
        cur.clear();
        if (path[i]=='/'&&i<quant)
        {
        i++;
        }
        while(path[i]!='/'&&i<quant)
        {
         cur.push_back(path[i]);
         i++;
        }
        if (cur==".."&&(!fina.empty()))//fina不能是空的，因为可能会报错
        {
            fina.pop_back();
        }
        if (cur!="."&&cur!=".."&&!cur.empty())//记得考虑cur不能是空的，因为第一遍如果是///的话，那么就会往fina填充一个空的cur
        {
        fina.push_back(cur);
        }
    }

    out.push_back('/');
    for(int i=0;i<fina.size();i++)
    {
        out+=fina[i];
        out.push_back('/');
    }
    if (out.size()>=2)//记得检查是不是只有一个斜杠
    {
        out.pop_back();
    }
    return out;
    }
};

int main()
{
    string path;
    while (cin >> path)
    {
        FilePath fp(path);
        cout << fp.simplifyPath() << endl;
    }
    return 0;
}