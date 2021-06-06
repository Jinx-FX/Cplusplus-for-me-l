// 有趣的排序

// 编程：设计学生类-排名
// 请设计一个学生类，私有数据成员包括姓名、成绩、排名，类的友元 func 函数计算成绩排名并填入
// 排名， main 函数如下：

// 样例输入：
//     5
//     zhao 80.5
//     qian 90
//     sun 70
//     li 80
//     zhou 60
// 样例输出：
//     2 zhao 80.5
//     1 qian 90
//     4 sun 70
//     3 li 80
//     5 zhou 60

#include<iostream>
#include<string>
using namespace std;
class Student{
    string name;
    float grade;
    int rank;
public:
    void set(const char *n,float s){name = n;grade = s;}
    friend void func(Student *,int);
    void show()
    {
        cout<<rank<<" "<<name<<" "<<grade<<endl;
    }
};
void func(Student *p,int n)
{
    int num[n];
    int k,temp;
    for(int i=0;i<n;i++)
        num[i] = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(p[i].grade<p[j].grade)
                num[i] += 1;
        }
    }
    for(int i=0;i<n;i++)
    {
        p[i].rank = num[i];
    }
}
int main() {
    int n;
    cin >> n;
    Student *pStu = new Student[n];
    for (int i = 0; i < n; i++)
    {
        char name[80];
        float score;
        cin >> name >> score;
        pStu[i].set(name, score);
    }
    func(pStu, n);
    for (int i = 0; i < n; i++)
    {
        pStu[i].show();
    }
    return 0;
}
