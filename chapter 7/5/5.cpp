#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Product
{
    public:
    static float discount;
    static float sum;
    static int n;
    int quantity;
    float price;
    
    Product(int q,float pri)
    {
        quantity=q;
        price=pri;
         if (quantity>=10)
        {
            sum+=quantity*price*(1-discount)*0.98;
            n+=q;
        }
        else 
        {
            sum+=quantity*price*(1-discount);
            n+=q;
        }
    };
    static void display ();
};


void Product::display()
{
    cout<<sum<<" "<<sum/n<<endl;
}

float Product::discount = 0;
float Product::sum = 0;
int Product::n = 0;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		float discount;
		cin >> discount;
		Product::discount = discount;
		Product::sum = 0;
		Product::n = 0;
		int m;
		cin >> m;
		while (m--)
		{
			int quantity;
			cin >> quantity;
			float price;
			cin >> price;
			Product(quantity, price);
		}
		Product::display();
	}
}