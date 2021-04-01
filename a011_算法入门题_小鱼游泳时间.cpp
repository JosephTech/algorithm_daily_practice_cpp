/*
从a时b分 到 c时d分，一共是多长时间。 （当天，24小时制）

输入： a, b, c, d四个整数

输出： e，f，表示几小时几分
*/
/*
思路：
	统一成分钟，
	减
	/60得到小时
	%60得到分钟
*/

#include <iostream>

int main() {
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	int total_m = (60 * c + d) - (60 * a + b);
	int e = total_m / 60;
	int f = total_m % 60;
	std::cout << e << " "<< f;

	system("pause");
	return 0;
}


