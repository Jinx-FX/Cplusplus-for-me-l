// 编程：设计 mystring 类-删除一个字符
// 编写一个 mystring 类，使以下的 main 函数能编译运行。
// 其中 s1-=c 是删除 s1 中所有 c 存储的字符。

// 样例输入：
// hello world
// o
// 样例输出：
// hell wrld

#include <iostream> 
#include <algorithm>
#include <string> 
using namespace std;

class mystring 
{ 
    string val; 
public:
    mystring(string &s) { val = s; } 
    mystring operator-=(char c) 
    { 
        val.erase(remove(val.begin(), val.end(), c), val.end());   //删除val中的相应元素，remove仅返回 删除元素的一个'迭代位' 更详细的解释见下一个 stl .remove.cpp
        /* int n = val.length(); 
        for (int i = n - 1; i >= 0; i--) 
        { if (val[i] == c) 
        val.erase(i, 1); } 
        */ 
        return *this;
    }
    friend ostream& operator<<(ostream &o, const mystring& s) 
    { 
        o << s.val << endl; 
        return o; 
    } 
};

int main() { 
    string s; 
    char c;
    getline(cin, s);
    cin >> c; 
    mystring s1 = s; 
    s1 -= c; 
    cout << s1; 
    return 0;
}
