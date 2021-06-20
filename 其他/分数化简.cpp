/*分数化简，关键是求出分母和分子的最大公因数。
  这里采用“辗转相除法”求两个整数的最大公因数。
  辗转相除法， 又名欧几里德算法（Euclidean algorithm），是求最大公约数的一种方法。
  它的具体做法是：用较大数除以较小数，再用出现的余数（第一余数）去除除数，再用出现的余数（第二余数）去除第一余数，
  如此反复，直到最后余数是0为止。如果是求两个数的最大公约数，那么最后的除数就是这两个数的最大公约数。
*/
 
#include<iostream>
 
using namespace std;
 
int main() {
	int n, m;	
	cout << "请分别输入分母和分子：" << endl;
	cin >> m >> n;
	int m0 = m, n0 = n;    //m0和n0保存m和n的原始值
	while (m%n != 0) {
		int temp = m ;
		m = n;
		n = temp%n;
	}
  n0 = n0/n;
  m0 = m0/n;
	cout << "原分式的最简分式为： " << n0 << "/" << m0 << endl;		                                                   
}
