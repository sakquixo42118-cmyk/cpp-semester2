#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Student 
{
    private:
    double score;
    
    public:
    Student (){};
    void scoreTotalCount (double);
    static double sum ();
    static double average();
    static double total;
    static int count;
    
};
 
double Student::total =0;
int  Student::count =0;
void Student::scoreTotalCount(double s)
{
    score=s;
    count++;
    total+=s;
}
double Student::sum()
{
 return total;
}

double Student::average()
{
 return (total/count);
}

int main() {
	vector<Student> students; // 存储学生对象的向量
	double score;
	int numStudents;
	// 输入学生人数
	cout << "请输入学生人数：";
	cin >> numStudents;
	// 输入每个学生的成绩
	for (int i = 0; i < numStudents; ++i) {
		cout << "请输入第 " << (i + 1) << " 个学生的成绩：";
		cin >> score;
		students.push_back(Student());
		students[i].scoreTotalCount(score);
	}
	// 输出总分和平均分
	cout << "全班学生的总分是：" << Student::sum() << endl; cout << "全班学生的平均分是：" << fixed << setprecision(2) << Student::average() << endl;
	return 0;
}