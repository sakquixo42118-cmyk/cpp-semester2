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

    bool operator== (const Setbase& b)
    {
        if (elements.size()!=b.elements.size())
        return 0;
        for (int i=0;i<elements.size();i++)
        {
            if (elements[i]!=b.elements[i])
            return false;
        }
        return true;
    }
};

template <typename T>
class GenericSet:public Setbase<T>     //要加上《T》！！！！
{
   public:
   using Setbase<T>::elements;        //如果要用elements，要加上using，或者所有的都用this-》elements
    void add (T val)
   {
    if (elements.empty())
    {
        elements.push_back(val);
        return;                         //因为只有一个值，所以push完成之后直接return；
    }
    bool equal = 0;
    for (int i=0;i<elements.size();i++)
    {
        if (elements[i]==val)
        equal =1;
    }
    if (!equal)
    elements.push_back(val);
    bubble() ;                        //调用函数带括号！
   }
   
   void bubble ()
  {
    for (int i=0;i<elements.size();i++)
    {
        for (int j=0;j<elements.size()-i-1;j++)
        {
            if (elements[j]>elements[j+1])
            {
                T temp =elements [j];
                elements[j]=elements[j+1];
                elements[j+1]=temp;
            }
        }
    }
  }
   
   bool contains (T val)
   {
    for (T temp:elements)
    {
        if (val==temp)
        {
            return 1;
        }
    }
    return 0;
   }

    GenericSet<T> operator+ (GenericSet <T> b)
    {
        GenericSet <T> out;
        for (int i=0;i<elements.size();i++)
        {
            out.add(elements[i]);
        }
        for (int i=0;i<b.elements.size();i++)
        {
            out.add(b.elements[i]);
        }
        return out;
    }

    GenericSet<T> operator* (GenericSet <T> b)
    {
        GenericSet <T> out;
        for (int i=0;i<elements.size();i++)
        {
            for (int j=0;j<b.elements.size();j++)
            {
                if (elements[i]==b.elements[j])
                {
                    out.add(elements[i]);
                }
            }
        }
        return out;
    }

    GenericSet<T> operator- (GenericSet <T> b)
    {
        GenericSet<T> out;
        for (int i=0;i<elements.size();i++)
        {
            bool equal=0;
            for (int j=0;j<b.elements.size();j++)
            {
                if (elements[i]==b.elements[j])
                equal=1;
            }
            if (!equal)
            {
                out.add(elements[i]);
            }
        }
        return out;
    }

    friend ostream& operator<< (ostream& out ,GenericSet<T> in)
    {
        if (in.elements.empty())
        {
            out<<"{}";
            return out;
        }
        out<<"{"<<in.elements[0];
        for (int i=1;i<in.elements.size();i++)
        {
            out<<", "<<in.elements[i];
        }
        out<<"}";
        return out;
    }

    int sum ()
    {
        int tot=0;
        for (int i=0;i<elements.size();i++)
        {
        tot+=elements[i];
        }
        return tot;
    }

    int maxVal()
    {
        int max=elements[0];
        for (int i=0;i<elements.size();i++)
        {  
          if (elements[i]>max)
          {
            max=elements[i];
          }
        }
        return max;
    }

    int minVal()
    {
        int min=elements[0];
        for (int i=0;i<elements.size();i++)
        {  
          if (elements[i]<min)
          {
            min=elements[i];
          }
        }
        return min;
    }




};







int main() {
    vector<double> nums1;
    vector<double> nums2;
    string line1, line2;
    // 循环读取多组测试数据，每组两行，需要#include <sstream>
    while (getline(cin, line1) && getline(cin, line2)) {
        nums1.clear();
        nums2.clear();
        // 读取第一行集合
        stringstream ss1(line1);
        double num1;
        while (ss1 >> num1) {
            nums1.push_back(num1);
        }
        // 读取第二行集合
        stringstream ss2(line2);
        double num2;
        while (ss2 >> num2) {
            nums2.push_back(num2);
        }
        GenericSet<double> set1;
        GenericSet<double> set2;
        for (int i = 0; i < nums1.size(); i++) {
            set1.add(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++) {
            set2.add(nums2[i]);
        }

        // 输出测试结果
        cout << "Set1: " << set1 << endl;
        cout << "Set2: " << set2 << endl;
	cout << "Union: " << (set1 + set2) << endl;//并集
	cout << "Intersection: " << (set1 * set2) << endl;//交集
	cout << "Difference: " << (set1 - set2) << endl;//差集
        cout << "Set1 == Set2: " << boolalpha << (set1 == set2) << endl;
        cout << "Sum of A: " << set1.sum() << endl;
        cout << "Max of A: " << set1.maxVal() << endl;
        cout << "Min of A: " << set1.minVal() << endl;
    }
    return 0;
}