#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>  
#include <vector>
#include <sstream>
using namespace std;

template <typename T>
class Setbase {
    public:
    vector <T> elements;

    virtual void add (T val)=0;
    int size ()
    {
        return elements.size();
    }

    bool
}