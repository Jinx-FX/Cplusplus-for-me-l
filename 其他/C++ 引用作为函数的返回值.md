> 本文由 [简悦 SimpRead](http://ksria.com/simpread/) 转码， 原文地址 [blog.csdn.net](https://blog.csdn.net/weixin_40539125/article/details/81410008?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control)

```
//代码来源：RUNOOB
#include<iostream>
using namespace std;
float temp;
float fn1(float r){
    temp=r*r*3.14;
    return temp;
} 
float &fn2(float r){ //&说明返回的是temp的引用，换句话说就是返回temp本身
    temp=r*r*3.14;
    return temp;
}
int main(){
    float a=fn1(5.0); //case 1：返回值
    //float &b=fn1(5.0); //case 2:用函数的返回值作为引用的初始化值 [Error] invalid initialization of non-const reference of type 'float&' from an rvalue of type 'float'
                           //（有些编译器可以成功编译该语句，但会给出一个warning） 
    float c=fn2(5.0);//case 3：返回引用
    float &d=fn2(5.0);//case 4：用函数返回的引用作为新引用的初始化值
    cout<<a<<endl;//78.5
    //cout<<b<<endl;//78.5
    cout<<c<<endl;//78.5
    cout<<d<<endl;//78.5
    return 0;
}
```

**特别注意：**

1. 引用作为函数的返回值时，**必须在定义函数时在函数名前将 &**

2. 用引用作函数的返回值的**最大的好处是在内存中不产生返回值的副本**

```
int x=fn1(5.0);
  int &b=x;
```

**case 1：用返回值方式调用函数（如下图，图片来源：伯乐在线）：**

![](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pbWFnZXMyMDE3LmNuYmxvZ3MuY29tL2Jsb2cvOTAwNzE1LzIwMTcwOC85MDA3MTUtMjAxNzA4MjQyMTMzMzIyNzctMTQwMzgwNTQwNi5wbmc?x-oss-process=image/format,png)

**返回全局变量 temp 的值时，C++ 会在内存中创建临时变量并将 temp 的值拷贝给该临时变量。当返回到主函数 main 后，赋值语句 a=fn1(5.0) 会把临时变量的值再拷贝给变量 a**

**case 2：用函数的返回值初始化引用的方式调用函数（如下图，图片来源：伯乐在线）**

![](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pbWFnZXMyMDE3LmNuYmxvZ3MuY29tL2Jsb2cvOTAwNzE1LzIwMTcwOC85MDA3MTUtMjAxNzA4MjQyMTM5MDk3NjEtMTY5MzExMDQ3MC5wbmc?x-oss-process=image/format,png)

**这种情况下，函数 fn1() 是以值方式返回到，返回时，首先拷贝 temp 的值给临时变量。返回到主函数后，用临时变量来初始化引用变量 b，使得 b 成为该临时变量到的别名。由于临时变量的作用域短暂（在 C++ 标准中，临时变量或对象的生命周期在一个完整的语句表达式结束后便宣告结束，也就是在语句 float &b=fn1(5.0); 之后） ，所以 b 面临无效的危险，很有可能以后的值是个无法确定的值。**

 **如果真的希望用函数的返回值来初始化一个引用，应当先创建一个变量，将函数的返回值赋给这个变量，然后再用该变量来初始化引用：**

```
#include<iostream>
using namespace std;
int value[10];
int error=-1;
int &func(int n){
    if(n>=0&&n<=9)
        return value[n];//返回的引用所绑定的变量一定是全局变量，不能是函数中定义的局部变量 
    else
        return error;
}
 
int main(){
    func(0)=10;
    func(4)=12;
    cout<<value[0]<<endl;
    cout<<value[4]<<endl;
    return 0; 
}
```

 **case 3: 用返回引用的方式调用函数（如下图，图片来源：伯乐在线）**

![](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pbWFnZXMyMDE3LmNuYmxvZ3MuY29tL2Jsb2cvOTAwNzE1LzIwMTcwOC85MDA3MTUtMjAxNzA4MjQyMjU0MjQzMzktOTAxNTczNjQ3LnBuZw?x-oss-process=image/format,png)

**这种情况下，函数 fn2() 的返回值不产生副本，而是直接将变量 temp 返回给主函数，即主函数的赋值语句中的左值是直接从变量 temp 中拷贝而来（也就是说 c 只是变量 temp 的一个拷贝而非别名） ，这样就避免了临时变量的产生。尤其当变量 temp 是一个用户自定义的类的对象时，这样还避免了调用类中的拷贝构造函数在内存中创建临时对象的过程，提高了程序的时间和空间的使用效率。**

**case 4: 用函数返回的引用作为新引用的初始化值的方式来调用函数（如下图，图片来源：伯乐在线）**

![](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pbWFnZXMyMDE3LmNuYmxvZ3MuY29tL2Jsb2cvOTAwNzE1LzIwMTcwOC85MDA3MTUtMjAxNzA4MjQyMzEwNDc3MTQtNTUyODE2MTUucG5n?x-oss-process=image/format,png)

**这种情况下，函数 fn2() 的返回值不产生副本，而是直接将变量 temp 返回给主函数。在主函数中，一个引用声明 d 用该返回值初始化，也就是说此时 d 成为变量 temp 的别名。由于 temp 是全局变量，所以在 d 的有效期内 temp 始终保持有效，故这种做法是安全的。**

3. **不能返回局部变量的引用。**如上面的例子，如果 temp 是局部变量，那么它会在函数返回后被销毁，此时对 temp 的引用就会成为 “无所指” 的引用，程序会进入未知状态。

4. **不能返回函数内部通过 new 分配的内存的引用**。虽然不存在局部变量的被动销毁问题，但如果被返回的函数的引用只是作为一个临时变量出现，而没有将其赋值给一个实际的变量，那么就可能造成这个引用所指向的空间（有 new 分配）无法释放的情况（由于没有具体的变量名，故无法用 delete 手动释放该内存），从而造成内存泄漏。因此应当避免这种情况的发生

5 **当返回类成员的引用时，最好是 const 引用**。这样可以避免在无意的情况下破坏该类的成员。

6. 可以用函数返回的引用作为赋值表达式中的左值

```
class Father;//基类（父类）
class Son：public Father{.....}//Son是Father的派生类
Son son;//son是类Son的一个实例
Father &ptr=son;//用派生类的对象初始化基类对象的使用
```

![](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pbWFnZXMyMDE3LmNuYmxvZ3MuY29tL2Jsb2cvOTAwNzE1LzIwMTcwOC85MDA3MTUtMjAxNzA4MjQyMzM4NDM1NTgtMTczMTMzOTU3NC5wbmc?x-oss-process=image/format,png)

### D. 用引用实现多态

在 C++ 中，**引用是除了指针外另一个可以产生多态效果的手段**。也就是说一个基类的引用可以用来绑定其派生类的实例

```
class Father;//基类（父类）
class Son：public Father{.....}//Son是Father的派生类
Son son;//son是类Son的一个实例
Father &ptr=son;//用派生类的对象初始化基类对象的使用
```

**特别注意：**

**ptr 只能用来访问派生类对象中从基类继承下来的成员**。**如果基类（类 Father）中定义的有虚函数，那么就可以通过在派生类（类 Son）中重写这个虚函数来实现类的多态。**