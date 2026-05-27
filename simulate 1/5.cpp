#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>  
#include <vector>
using namespace std;

class Product
{
  public:
  virtual double getPrice()=0;
  virtual string getName()=0;
string name;
double  price;

 
Product (string a,double b):name(a),price (b){};

};

class RegularProduct:public Product
{
  public:
    
  RegularProduct (string a,double b):Product(a,b){};
  
  double getPrice()
  {
   return price;
  }
  string getName ()
  {
    return name;
  }

};

class DiscountedProduct:public Product
{
  public:
  double discount;

  DiscountedProduct(string a,double b,double c):Product(a,b),discount(c){};

  double getPrice()
  {
   return price*discount;
  }
  string getName ()
  {
    return name+"（特价）";
  }

};

template <typename T>
class ShoppingCart
{
  public:
  int quaant;
  vector <T> carrt;
  vector <int > quant;
  
  ShoppingCart (int n)
  {
    quaant =n;
  }

  void addProduct (T pro,int inquant)
  {
   carrt.push_back(pro);
   quant.push_back(inquant);
  }

  double calculateTotalPrice()
  {
    double total=0;
    for (int i=0;i<carrt.size();i++)
    {
        total+=(carrt[i]->getPrice())*quant[i];//调用的时候加括号哦！！！！！
       
    }
    return total;
  }

  void productList()
  {
    cout<<"购物车商品列表："<<endl;
    for (int i=1;i<=carrt.size();i++)
    {
        cout<<i<<"."<<carrt[i-1]->getName()<<"，单价: "<<carrt[i-1]->getPrice()
        <<"元，数量: "<<quant[i-1]<<", 小计: "<< carrt[i-1]->getPrice()*quant[i-1]<<"元"<<endl;
    }
  }
};


int main() {

    int n = 0;

    while (cin >> n) {

        bool own = n > 0 ? true : false;//购物车中是否有商品

        // 基类指针类型保存子类指针，实现多态，ShoppingCart<T>, T = Product*

        ShoppingCart<Product*> *cart = new ShoppingCart<Product*>(own);

        for (int i = 0; i < n; i++) {

            string name;

            double price, discount;

            int quantity;

            cin >> name >> price >> quantity;

            if (cin.peek() != '\n') {

                cin >> discount;

                //void addProduct(T product, int quantity)

                cart->addProduct(new DiscountedProduct(name, price, discount), quantity);

            }

            else {

                cart->addProduct(new RegularProduct(name, price), quantity);

            }

        }

        cout << "购物车总价: " << cart->calculateTotalPrice() << " 元" << endl;

        cart->productList();

        delete cart;

    }

    return 0;

}