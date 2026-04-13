#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class Cart {
public:
	// 存储商品单价和数量的数组
	double price[3];
	int num[3];
	// 存储总价
	double sumPrice = 0;
	// 重载输入
	friend istream& operator>>(istream& input, Cart& c)
    {
        for(int i=0;i<3;i++)
        {
            input>>c.price[i];
        }
        for (int j=0;j<3;j++)
        {
            input>>c.num[j];
        }
        return input;
    };
	// 计算总价
	double caculate()
    {
         double total=0;
        for (int i=0;i<3;i++)
        {
            total+=price[i]*num[i];
        }
        return total;
    };
};
class DisCount : public Cart {
public:
	//重写总价计算方法
	double caculate()
    {
        double total=0;
        for (int i=0;i<3;i++)
        {
            total+=price[i]*num[i];
        }
        return total*0.9;
    };
};
class Minus : public Cart {
public:
	//重写总价计算方法
	double caculate()
    {
        double total=0;
        for (int i=0;i<3;i++)
        {
            total+=price[i]*num[i];
        }
        int ceil=total/200;
        return total-ceil*30;
    };
};
int main()
{
	int n;
	cin >> n;
	while (n > 0) {
		DisCount d;
		Cart* cart = &d;
		cin >> *cart;
		// 计算原价
		double originPrice = cart->caculate();
		DisCount* discount = (DisCount*)cart;
		double res1 = discount->caculate();
		Minus* minus = (Minus*)cart;
		double res2 = minus->caculate();
		cout << originPrice << " ";
		// 输出优惠力度最大的付款价格
		if (res1 < res2) {
			cout << res1 << endl;
		}
		else {
			cout << res2 << endl;
		}
		n--;
	}
	return 0;
}