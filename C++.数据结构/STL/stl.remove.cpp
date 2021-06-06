#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
#include <functional>
 
template<typename Container>
void PrintElement(const Container& c)
{
     std::cout << "Size: " << c.size() << std::endl;
     std::copy(c.begin(), c.end(),
                     std::ostream_iterator<typename Container::value_type>(std::cout, " "));
     std::cout << std::endl;
}
template<typename Container>
void PrintElementOnly(const Container& c)
{
     std::copy(c.begin(), c.end(),
                    std::ostream_iterator<typename Container::value_type>(std::cout, " "));
     std::cout << std::endl;
}
 
//移除元素
int main()
{
     /************************************************************************/
     //remove
     /************************************************************************/
     //remove：将value从range[first,last)中移除
     // 此处的移除并非真正抹除掉，所以range的范围未发生
     // 操作只是返回一个新的iterator（new_last）,使得range[first,new_last)内的元素值不等于value
     //如果需要真正清除元素，可以使用Container/Sequence的成员函数erase
     //Sequence s;s.erase(remove(s.begin(),s.end(),x),s.end());
     /*
     template<class ForwardIterator, class Type>
     ForwardIterator remove(
          ForwardIterator _First,
          ForwardIterator _Last,
          const Type& _Val
          );
     */
     int a[] = { 2, 3, 1, 9, 0, 1, 5, 4, 8, 7, 1 };
     std::vector<int> iv(std::begin(a), std::end(a));
     PrintElement(iv);
     //Size: 11
     //2 3 1 9 0 1 5 4 8 7 1
 
     std::vector<int>::iterator newLast = std::remove(iv.begin(), iv.end(), 1);
     PrintElement(iv);
     //Size: 11     ------->Size：保持不变
     //2 3 9 0 5 4 8 7 8 7 1  ------->其中最后几位保留原来的值
 
     iv.erase(newLast, iv.end());
     PrintElement(iv);
     //Size: 8    --------->Size：发生变化
     //2 3 9 0 5 4 8 7  --------->将最后几位清除抹掉
 
     /************************************************************************/
     //remove_if
     /************************************************************************/
     //remove_if：将range[first,last)内满足条件的元素remove掉，原理跟remove相同
     /*
     template<class ForwardIterator, class Predicate>
     ForwardIterator remove_if(
          ForwardIterator _First,
          ForwardIterator _Last,
          Predicate _Pred
          );
     */
     iv.clear();
     iv = { 1, 4, 6, 5, 3, 9 };
     newLast = std::remove_if(iv.begin(), iv.end(),  [](const int i){return i % 2 == 0; });
     iv.erase(newLast, iv.end());
     //1 5 3 9
     //std::copy(iv.begin(), iv.end(), std::ostream_iterator<int>(std::cout, " "));
     PrintElementOnly(iv);
 
     /************************************************************************/
     //remove_copy
     /************************************************************************/
     //remove_copy：将range[first,last)内的不等于value的元素复制到result所指定的range内
     //  原range[first,last)保持不变
     /*
     template<class ForwardIterator, class OutputIterator, class Type> inline
      OutputIterator remove_copy(
      ForwardIterator First,
          ForwardIterator Last,
          OutputIterator Result,
          const T& Value
          );
     */
     std::vector<std::string> sv;
     sv.push_back("");
     sv.push_back("one");
     sv.push_back("ten");
     sv.push_back("");
     sv.push_back("four");
     std::remove_copy(sv.begin(), sv.end(),
     std::ostream_iterator<std::string>(std::cout, "\n"), "");
     //one
     //ten
     //four
 
 
     /************************************************************************/
     //remove_copy_if
     /************************************************************************/
     //remove_copy_if：将满足条件的条件的元素移除
     /*
     template<class InputIterator, class OutputIterator, class Predicate>
     OutputIterator remove_copy_if(
          InputIterator _First,
          InputIterator _Last,
          OutputIterator _Result,
          Predicate _Pred
          );
     */
     iv.clear();
     iv = { 1, 4, 6, 5, 3, 9 };
     std::vector<int> iv2;
     std::remove_copy_if(iv.begin(), iv.end(), back_inserter(iv2),
      std::bind1st(std::less_equal<int>(), 5));
     PrintElementOnly(iv2);     //1 4 3
 
     /************************************************************************/
     //unique
     /************************************************************************/
     //unique：移除相邻的重复的元素，如果想要移除所有重复的元素，必须确保所有重复的元素都相邻，所以需要unique和sort搭配使用
     //unique跟remove一样，都不会改变[first,last)间的元素个数，只会返回一个iterator（new_last），使得范围[first,new_last)相邻之间没有重复的元素
     //版本1：以默认的operator==进行比较
     //版本2：自定义函数对象，来进行比较
     /*
     template<class ForwardIterator>
     ForwardIterator unique(
          ForwardIterator _First,
          ForwardIterator _Last
          );
     */
     /*
     template<class ForwardIterator, class Predicate>
     ForwardIterator unique(
          ForwardIterator _First,
          ForwardIterator _Last,
          Predicate _Comp
          );
     */
     //测试版本1：
     iv.clear();
     iv = { 1, 2, 2, 3, 4, 4, 1, 3 };
     //只unique
     iv.erase(std::unique(iv.begin(), iv.end()),iv.end());
     PrintElementOnly(iv);    //1 2 3 4 1 3
 
     iv.clear();
     iv = { 1, 2, 2, 3, 4, 4, 1, 3 };
     //先sort，然后unique
     std::sort(iv.begin(), iv.end());
     iv.erase(std::unique(iv.begin(), iv.end()), iv.end());
     PrintElementOnly(iv);    //1 2 3 4
 
     //测试版本2：
     char s[] = "The Standard Template Library";
     std::vector<char> cv(s,s + sizeof(s));
     //不分字母大小写
     std::sort(std::begin(cv), std::end(cv), 
                  [](const char c1, const char c2){return toupper(c1) < toupper(c2); });
     std::copy(cv.begin(), cv.end(), std::ostream_iterator<char>(std::cout));
     std::cout << std::endl;
 
     //不分大小写，只要是同一字母，都抹掉
     cv.erase(std::unique(cv.begin(), cv.end(), 
                  [](const char c1, const char c2){return toupper(c1) == toupper(c2); }), cv.end());
     std::copy(cv.begin(), cv.end(), std::ostream_iterator<char>(std::cout));
     std::cout << std::endl;
 
     /************************************************************************/
     //unique_copy
     /************************************************************************/
     //unique_copy：copy和unique的结合
     /*
     template<class InputIterator, class OutputIterator>
     OutputIterator unique_copy(
          InputIterator _First,
          InputIterator _Last,
          OutputIterator _Result
          );
     */
     /*
     template<class InputIterator, class OutputIterator, class BinaryPredicate>
     OutputIterator unique_copy(
          InputIterator _First,
          InputIterator _Last,
          OutputIterator _Result,
          BinaryPredicate _Comp,
          );
     */
     //测试版本1：
     int b[] = { 2, 8, 8, 8, 1, 1, 8, 7, 7, 2, 1, 1 };
     std::unique_copy(std::begin(b), std::end(b),
                  std::ostream_iterator<int>(std::cout, " "));     //2 8 1 8 7 2 1
 
    //测试版本2：
     struct eq_div
     {
          eq_div(int n) :div(n){}
          bool operator()( int x,  int y)const { return x / div == y / div; }
          int div;
     };
     iv.clear();
     int c[] = { 1, 5, 8, 15, 24, 27, 41, 47, 55, 62, 69, 74, 82, 93, 98 };
     std::unique_copy(std::begin(c), std::end(c), std::back_inserter(iv), eq_div(10));
     PrintElementOnly(iv);    //1 15 24 41 55 62 74 82 93 
     return 0;
}
