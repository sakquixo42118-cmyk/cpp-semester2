#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;

class Number
{
   public:
    double value;

   Number (double in):value(in){};

   Number& operator =(double res)//重载=想要生效的话需要有一个已经存在的Number对象，重载=和复制构造函数是不一样的
   {
    value=res;
    return *this;
   }
   void print()
   {
    cout<<value<<endl;
   }
};

class Real:public Number{
    public:

    Real (double inn):Number(inn){};
    Real* add (Real* b)//注意看主函数的信息，传进来的是指针，所以这个地方的格式也应该作出对应的修改
    {
        return new Real(value+b->value);//为了和主函数中的赋值进行对齐，所以这个地方应该return一个指向Number或者Real的指针
    }
    Real* subtract (Real* b)
    {
        return new Real(value-b->value);
    }
    Real* multiply (Real* b)
    {
        return new Real(value*b->value);
    }
    Real* divide (Real* b)
    {
        return new Real(value/b->value);
    }
    Real* power (Real* b)
    {
        return new Real(pow(value,b->value));
    }
};

class Integer:public Number{
    public:

    Integer (int inn):Number(inn){};
    Integer* add (Integer* b)
    {
        return new Integer(value+b->value);
    }
    Integer* subtract (Integer* b)
    {
        return new Integer(value-b->value);
    }
    Integer* multiply (Integer* b)
    {
        return new Integer(value*b->value);
    }
    Integer* divide (Integer* b)
    {
        return new Integer(value/b->value);
    }
    Integer* power (Integer* b)
    {
        return new Integer(pow(value,b->value));
    }
};

int main() {
	int a, b;
	double c, d;
	while (cin >> a >> b >> c >> d) {
		Integer* i1 = new Integer(a);
		Integer* i2 = new Integer(b);
		Real* r1 = new Real(c);
		Real* r2 = new Real(d);
		// 测试整数的算术运算
		Number* result = i1->add(i2);
		result->print();
		result = i1->subtract(i2);
		result->print();
		result = i1->multiply(i2);
		result->print();
		result = i1->divide(i2);
		result->print();
		result = i1->power(i2);
		result->print();
		// 测试实数的算术运算
		result = r1->add(r2);
		result->print();
		result = r1->subtract(r2);
		result->print();
		result = r1->multiply(r2);
		result->print();
		result = r1->divide(r2);
		result->print();
		result = r1->power(r2);
		result->print();
	}
	return 0;
}