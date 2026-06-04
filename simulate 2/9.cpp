#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>  
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;


class Product
{
    public:
    string name;
    double price;
    int count;

    Product (string a="",double b=0.00,int c=0):name(a),price(b),count(c){};

    friend ostream& operator<< (ostream& out,Product a)
    {
        out<<"("<<a.name<<","<<fixed<<setprecision(2)<<a.price<<","<<a.count<<")";//不要有方框
        return out;
    }

    bool operator== (Product& o)  //要给product也加上==重载
    {
        if(name==o.name&&price==o.price&&count==o.count)
        return 1;
        else
        return 0;
    }

    bool operator!= (Product& o)
    {
        return !(*this==o);  //善于运用*this
    }

};




template <typename T>
class Storebase
{
    public:
    vector <T> items;

    virtual void add (const T& x)=0;

    int size()
    {
        return items.size();
    };

    bool operator== (const Storebase<T>& b)   //抽象类不能直接传参，要使用引用，别忘了加上<T>!!!
    {
        bool equal =1;
        if (items.size()!=b.items.size())
        return 0;

        else
        {
            for (int i=0;i<items.size();i++)
            {
                if (items[i]!=b.items[i])
                equal=0;
            }
        }
        return equal;
    }
};


template <typename T>
class Inventory:public Storebase<T>{
     public:
    using Storebase<T>::items;

     void add (const T& x)
     {
        bool eq=0;
        int index;
        
        if (items.empty())
        {
            items.push_back(x);
            return;
        }
        
        for (int i=0;i<items.size();i++)
        {
            
            if (items[i].name==x.name)
            {
                eq=1;
                index=i;
            
            }
        }
        if (eq)
        {
         items[index].count+=x.count;    //这个地方不能直接++
         items[index].price=x.price;
        }
        else{
            items.push_back(x);
            for (int i=0;i<items.size()-1;i++)
            {
                for (int j=0;j<items.size()-1-i;j++)
                {
                    if (items[j].name>items[j+1].name)
                    {
                        T temp=items[j];
                        items[j]=items[j+1];
                        items[j+1]=temp;

                    }
                }
            }
        }
     }
     
     bool remove (const string& n, int k)
     {
        bool ex=0;
        int index;
        for (int i=0;i<items.size();i++)
        {
            if (items[i].name==n)
            {ex=1;
            index=i;
            }
        }
        if (!ex||items[index].count<k)
        return false;
        else{
          items[index].count-=k;
          if(items[index].count<=0)
          {
            items.erase(items.begin()+index);   //不能加1，+号后面的就是index
          }
          return 1;                   //如果商品不足也会返回1！这是有问题的
        }
      }

     bool contains (const string& n) const{
        bool is=0;
        for (int i=0;i<items.size();i++)
        {
            if (items[i].name==n)
            is=1;
        }
        return is;
     }


     double totalValue ()
     {
        double out=0;
        for (int i=0;i<items.size();i++)
        {
           out+=items[i].price*items[i].count;
        }
        return out;
     }

     T maxStockItem()
     {
        T max;
        if (items.empty())
        {
            return max ;
        }
        max=items[0];
        for (int i=1;i<items.size();i++)
        {
            if (max.count<items[i].count)
            {
                max=items[i];
            }
            if (max.count==items[i].count)
            {
                if (max.name>items[i].name)
                {
                    max=items[i];
                }
            }
        }
        return max;
     }

     friend ostream& operator<< (ostream& out,Inventory a)
     {
        if (a.items.empty())
        {
            out<<"[]";
        }
        else{
            out<<"[";
            for (int i=0;i<a.items.size();i++)
            {
             if (i>0)    //格式中间有逗号！！！！
             cout<<", "; 
                out<<"("<<a.items[i].name<<","<<fixed<<setprecision(2)<<a.items[i].price<<","<<a.items[i].count<<")";//不能每一个都输出括号
               
            }
            out<<"]";//别忘了补上]
        }
        return out;
     }






};


int main() {

    

ios::sync_with_stdio(false);

    cin.tie(nullptr);

 

    int n;

    while (cin >> n) {

        Inventory<Product> inv;

        string op;

        for (int i = 0; i < n; ++i) {

            cin >> op;

            if (op == "IN") {

                string name; double p; int c;

                cin >> name >> p >> c;

                inv.add(Product(name, p, c));

            } else if (op == "OUT") {

                string name; int c;

                cin >> name >> c;

                cout << "Out " << name << " " << c << ": " << boolalpha << inv.remove(name, c) << "\n";

            } else if (op == "HAS") {

                string name; cin >> name;

                cout << "Has " << name << ": " << boolalpha << inv.contains(name) << "\n";

            } else if (op == "SIZE") {

                cout << "Size: " << inv.size() << "\n";

            } else if (op == "VALUE") {

                cout << "TotalValue: " << fixed << setprecision(2) << inv.totalValue() << "\n";

            } else if (op == "MAX") {

                cout << "MaxStock: " << inv.maxStockItem() << "\n";

            } else if (op == "PRINT") {

                cout << "Inventory: " << inv << "\n";

            }

        }

    }

    return 0;

}