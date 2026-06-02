#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;


template <typename T>
class EncryptedString 
{
   public:
    string con;

   EncryptedString(string in)
   {
    con =in;
   }

   void encrypt ()
   {
    for (int i=0;i<con.size();i++)
    {
        con[i]+=3;
    }
   }

   string getString ()
   {
    return con;
   }
};

int main() {
	string line;
	while (getline(cin, line)) {
		EncryptedString<char> es(line);
		es.encrypt();
		cout << es.getString() << endl;
	}
	return 0;
}