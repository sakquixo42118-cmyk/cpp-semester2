#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>  
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Item
{
    public:
    string name;
    double weight;
    int value;
    
    Item (string a="",double b=0,int c=0):name(a),weight(b),value(c){};
    
    string getName ()
    {
        return name;
    }

    Item operator+ (Item b)
    {
        return Item ("Total",weight+b.weight,value+b.value);
    }

    bool operator< (Item b)
    {
        return value<b.value;
    }

    friend ostream& operator<< (ostream& out,Item in)
    {
        out<<in.name<<" "<<in.weight<< " "<<in.value;
        return out;
    }

          
   
    
};

int main() {

    int T;

    cin >> T;

    while (T--) {

        int n;

        cin >> n;

        Item total("Total", 0, 0);

        Item best;

        for (int i = 0; i < n; i++) {

            string name;

            double weight;

            int value;

            cin >> name >> weight >> value;

            Item item(name, weight, value);

            cout << "Item: " << item << endl;

            total = total + item;

            if (i == 0 || best < item) {

                best = item;

            }

        }

        cout << "Total: " << total << endl;

        cout << "Best: " << best.getName() << endl;

    }

    return 0;

}