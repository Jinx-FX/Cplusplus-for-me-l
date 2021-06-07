//设计一个通用数组类模板
/*
int main()
{
int n;
cin >> n;
Array a(n);
for (int i = 0; i < n; i++)
{
cin >> a[i];
}
mysort(a, n); // 排序
for (int i = 0; i < n; i++)
{
cout << a[i] << " ";
}
cout << endl;
return 0;
}

输入
输入分两行，第一行输入数组个数n，第二行输入n个整数
输出
输出分三行
第一行输出"分配n个数组元素"
第二行输出从小到大排序后的整数，每个整数中间用一个空格隔开
第三行输出"释放数组"

样例输入 Copy
5
4 3 5 1 2
样例输出 Copy
分配5个数组元素
1 2 3 4 5
释放数组
*/

//答案如下：
#include <iostream>
using namespace std;
template<class T>
class Array
{
    int SIZE;
    T* arr;
public:
    Array(int n)
    {
        SIZE = n;
        arr = new T[SIZE];
    }
    T& operator[](int n){return arr[n];}
    template<class U>
    friend void mysort(Array<U>&,int);
    ~Array()
    {
        delete [] arr;
        cout<<"释放数组";
    }
};

template<class U>
void mysort(Array<U> &a,int n)
{
    int k;
    U t;
    for(int i=0;i<n-1;i++)
    {
        k=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[k]>a[j])
                k=j;
        }
        if(k!=i)
        {
            t=a[i];
            a[i]=a[k];
            a[k]=t;
        }
    }
    cout<<"分配"<<n<<"个数组元素"<<endl;
}
int main()
{
    int n;
    cin >> n;
    Array<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mysort(a, n); // 排序
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
