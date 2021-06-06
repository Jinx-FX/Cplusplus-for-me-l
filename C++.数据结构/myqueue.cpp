//队列是一种特殊的线性表，特殊之处在于它只允许在表的前端（front）进行删除操作，
//而在表的后端（rear）进行插入操作，和栈一样，队列是一种操作受限制的线性表。
//进行插入操作的端称为队尾，进行删除操作的端称为队头。
//如果队列满了将不能插入数据。
/*
输入
一行输入两个整数，中间用空格分开
输出
在一系列的操作后输出队列里所有的数
样例输入 Copy
5 4
样例输出 Copy
6 7 8 10 11
*/

#include<iostream>
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
class Queue:public Array
{
public:
    int pos;
    Queue(int size):Array(size){pos=0;}
    ~Queue()
    {
        if (NULL != p)
        {
            delete [] p;
        }
    }
    void in(int v)
    {
        if(pos<size)
        {
            p[pos]=v;
            pos++;
        }
    }
    void out(int &o)
    {
        o=p[0];
        for(int i=0;i<size;i++)
        {
            p[i]=p[i+1];
        }
        pos--;
    }
};
int main()
{
    int v;
    int n;
    int o;
    cin >> n >> v;
    Queue myqueue(n);
    for (int i = 0; i < n + 1; i++)    // 插入数据比队列多，最后一个数据不能入队
    {
        myqueue.in(v++); // 数据入队
    }
    myqueue.out(o); // 数据出队
    myqueue.out(o); // 数据出队
    for (int i = 0; i < n; i++)
    {
        myqueue.in(v++); // 数据入队
    }
    for (int i = 0; i < n; i++)
    {
        myqueue.out(o); // 数据出队
        cout << o << " ";
    }
    cout << endl;
    return 0;
}
