#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class ID
{
    public:
    string id;
    char newid[19];
    
    ID (string in):id(in){};
    void change();
    string getNewID ();
};

void ID::change()
{
    for (int i=0;i<6;i++)
    {
        newid[i]=id[i];
    }
    newid[6]='1';
    newid[7]='9';
    for (int i=8;i<17;i++)
    {
        newid[i]=id[i-2];
    }
    int total=0;
    vector <int>can ={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    for (int i=0;i<17;i++)
    {
    total+= ((newid[i]-'0')*can[i]);
    }
    int final=total%11;
    string aaa ="10X98765432";
    newid[17]=aaa[final];
    newid[18]='\0';
}

string ID::getNewID()
{
    return newid;
}

int main() {
	string str; while (cin >> str) {
		ID myID(str); myID.change();
		cout << myID.getNewID() << endl;
	}
	return 0;
}