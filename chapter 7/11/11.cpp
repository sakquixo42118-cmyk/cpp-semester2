#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class SStack
{
   public:
   vector<int> stack;

   void push(int n)
   {
    stack.push_back(n);
   }
   bool isEmpty()
   {
    return stack.empty();
   }
   void pop()
   {
    stack.pop_back();
   }
   int top()
   {
    int quant =stack.size();
    for (int i=0;i<quant-1;i++)
    {
        for (int j=0;j<quant-1;j++)
        {
            if (stack[j]>stack[j+1])
            {
                int temp=stack[j];
                stack[j]=stack[j+1];
                stack[j+1]=temp;
            }
        }
    }
    return stack[quant-1];
   }
};

int main() {
	SStack stack = SStack();
	int n;
	int num;
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			cin >> num;
			stack.push(num);
		}
		while (!stack.isEmpty()) {
			cout << stack.top() << " ";
			stack.pop();
		}
		cout << endl;
	}
	return 0;
}
