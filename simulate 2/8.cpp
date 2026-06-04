#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>  
#include <vector>
#include <sstream>
#include <algorithm>//sort函数需要这个头文件
using namespace std;

class Task
{
    public:
    string name;
    int priority;

    virtual int getTime ()=0;
    
    Task (string a,int b):name(a),priority(b){};


};

class CPUTask :public Task
{
    public:
    int cycles;
    double Time;

    CPUTask (string a,int b,int c):Task(a,b),cycles(c),Time(c/10){};
    int getTime(){
        return Time;
    }
    
};

class IOTask :public Task
{
   public:
   int size;
   double Time;

   IOTask (string a,int b,int c):Task(a,b),size(c),Time(c/5){};
    int getTime(){
        return Time;
    }

};

bool cmp (Task*a ,Task*b) //cmp函数返回的a是否应该排在b的前面的问题
{
    if (a->priority>b->priority)
    {
      return 1;
    }
    if (a->priority<b->priority)
    {
        return 0;
    }
    else{
        if (a->getTime()>b->getTime())
        {
            return 0;
        }
        if (a->getTime()<b->getTime())
        {
            return 1;
        }
        else{
            return 0;     //如果二者相同应该返回0！！！！！
        }
    }
}







int main() {

    int n;

    

 

    while (cin >> n) {

        vector<Task*> tasks;

        for (int i = 0; i < n; i++) {

            string type;

            string name;

            int p, val;

 

            cin >> type >> name >> p >> val;

 

            if (type == "CPU") {

                tasks.push_back(new CPUTask(name, p, val));

            } else if (type == "IO") {

                tasks.push_back(new IOTask(name, p, val));

            }

        }

        // 排序

        sort(tasks.begin(), tasks.end(), cmp);

        // 输出

        for (int i = 0; i < tasks.size(); i++) {

            cout << tasks[i]->name << " "

                 << tasks[i]->getTime() << endl;

        }

        tasks.clear();

    }

    return 0;

}
