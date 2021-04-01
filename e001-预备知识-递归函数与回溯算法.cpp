/*
预备知识：
	递归函数基础
*/

//#include <stdio.h> // printf
#include <iostream>

void compute_sum3(int i, int &sum) { // i= 3， 将sum再加上3
	sum += i;
}

void compute_sum2(int i, int &sum) { // i = 2, 将sum再加上2
	sum += i;
	compute_sum3(i + 1, sum);
}

void compute_sum1(int i, int &sum) { // i = 1, 将sum再加上1 
	//引用的方式传入，可以修改 外边的传递之前的num的值
	sum += i;
	compute_sum2(i + 1,sum);
}


//================================
//将以上三个函数，改写成递归，调用自己
void compute_sum(int i, int &sum) {
	if (i > 10) {
		return; //每个递归都要有结束条件，否则会内存耗尽
	}
	sum += i; //将i累加至sum
	compute_sum(i+1, sum); //i递增后，递归。调用自己
}

int main() {
	int sum = 0;
	//compute_sum1(1,sum); //注意是引用的方式传入的，直接在num变量上运算了
	compute_sum(1, sum);

	printf("sum = %d\n", sum);
	
	system("pause");
	return 0;
}