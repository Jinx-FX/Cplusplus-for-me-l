//引用-小技巧
//在重载运算符中用法

// 输出：
// 4,1

#include <iostream>
using namespace std;
class MyInt {
    int nVal;
public:
    MyInt(int n) : nVal(n) { }
    int ReturnVal() { return nVal; }
    MyInt& operator-(int i)       //这里返回引用，记录了每次变化的值，以确定在每次运算能够顺利进行
    {
        nVal = nVal -i;
        return *this;
    }
};
int main() {
    MyInt objInt(10);
    objInt - 2 - 1 - 3;
    cout << objInt.ReturnVal();
    cout << ","; 
    objInt - 2 - 1;
    cout << objInt.ReturnVal();
    return 0;
}
