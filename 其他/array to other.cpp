// c++，原生的字符数组赋值另一个，同时转化到字符串数组

// 已知 Person 类包含保护数据成员姓名和年龄，
// 只有唯一一个构造函数 Person(const char *, int);
// 在Peroson 的基础上派生 Student 类，增加属性分数，
// 在 Person 的基础上派生 Teacher 类，增加属性工资，
// 助教类 Assistant 从 Student 类和 Teacher 类派生，
// 请按要求设计上述类使以下的 main 函数得以编译运行。

// 样例输入： 无
// 样例输出：
// Person::Person
// Student::Student
// Teacher::Teacher
// Assistant::Assistant
// zhangsan
// 24
// 90
// 2000

#include<iostream>
#include<cstring>
using namespace std;
class Person
{
protected:
    int age;
    char name[20];
public:
    Person(const char *nam,int ages)
    {
        unsigned int i;
        for(i=0;i<strlen(nam);i++)
            name[i]=nam[i];
        name[i]='\0';
        age=ages;
        cout<<"Person::Person"<<endl;
    }
};
class Student:virtual public Person
{
protected:
    int grade;
public:
    Student(const char*name,int age,int grades):Person(name,age)
    {
        grade=grades;
        cout<<"Student::Student"<<endl;
    }
};
class Teacher:virtual public Person
{
protected:
    long salary;
public:
    Teacher(const char*name,int age,long salarys):Person(name,age)
    {
        salary=salarys;
        cout<<"Teacher::Teacher"<<endl;
    }
};
class Assistant:public Student,public Teacher
{
public:
    Assistant(const char*name,int age,int grade,long salary):Person(name,age),Student(name,age,grade),Teacher(name,age,salary)
    {
        cout<<"Assistant::Assistant"<<endl;
    }
    void show()
    {
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<grade<<endl;
        cout<<salary<<endl;
    }
};
int main() 
{
    Assistant ass("zhangsan", 24, 90, 2000);
    // 姓名、年龄、分数、工资
    ass.show();
    return 0;
}





