#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>  
using namespace std;


class Stock
{
    public:
    string symbol;
    string name;
    double previousClosingPrice;
    double currentPrice;

    Stock (string a,string b):symbol(a),name(b){};

    void setPreviousClosingPrice (double in)
    {
        previousClosingPrice=in;

    }

    void setCurrentPrice(double in)
    {
        currentPrice=in;
    }

    double getChangePercent()
    {
        return (currentPrice-previousClosingPrice)/ previousClosingPrice*100;
    }
    
};

int main() {

    string symbol, name;

    double prev, curr;

    getline(cin, symbol);

    getline(cin, name);  

    cin >> prev;         

    cin >> curr;         

    Stock stock(symbol, name);

    stock.setPreviousClosingPrice(prev);

    stock.setCurrentPrice(curr);

    cout << fixed << setprecision(2) << stock.getChangePercent() << "%" << endl;

    return 0;

}