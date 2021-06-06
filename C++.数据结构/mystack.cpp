/*
堆栈是一种数据结构。堆栈都是一种数据项按序排列的数据结构，只能在一端(称为栈顶(top))对数据项进行插入和删除。
样例输入
1 2 3 4 5 6 7 8 9 10
样例输出
10 9 8 7 6 5 4 3 2 1
*/
#include <iostream>
using namespace std;

class Array
{
protected:
    int *p;
    int size;
public:
    Array(int n)
    {
        size = n;
        p = new int[size];
    }
    ~Array()
    {
        if (NULL != p)
        {
            delete [] p;
        }
    }
    int& operator[](int i)
    {
        return p[i];
    }
};
class Stack:public Array
{
public:
    Stack(int size):Array(size){}
    void push(int v)//输入
    {
        *(p++)=v;
    }
    void pop(int &v)//输出
    {
        v=*(--p);
    }
    ~Stack()
    {
        if (NULL != p)
        {
            delete [] p;
        }
    }
};
int main()
{
    int v;
    Stack mystack(10);
    for (int i = 0; i < 10; i++)
    {
        cin >> v;
        mystack.push(v);
    }
    for (int i = 0; i < 10; i++)
    {
        mystack.pop(v);
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
