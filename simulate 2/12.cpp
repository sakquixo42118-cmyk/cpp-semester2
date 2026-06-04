#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>  
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Car
{
    public:
    string name;
    double cost;
    double base;

    Car (string a,double b,double c):name(a),cost(b),base(c){};

    double getCost (double dis)
    {
     return dis*cost+base;
    }

    string getName()
    {
        return name;
    }

    bool isCheaperThan (Car o,double dis)
    {
      return getCost(dis)<o.getCost(dis);

    }
};

int main() {
    string name1, name2;
    double cost1, cost2;
    double base1, base2;
    double distance;
    while (cin >> name1 >> cost1 >> base1) {
        cin >> name2 >> cost2 >> base2;
        cin >> distance;
        Car car1(name1, cost1, base1);
        Car car2(name2, cost2, base2);
        cout << car1.getName() << ": " << car1.getCost(distance) << endl;
        cout << car2.getName() << ": " << car2.getCost(distance) << endl;
        if (car1.isCheaperThan(car2, distance)) {
            cout << "Cheaper: " << car1.getName() << endl;
        } else {
            cout << "Cheaper: " << car2.getName() << endl;
        }
    }
    return 0;
}