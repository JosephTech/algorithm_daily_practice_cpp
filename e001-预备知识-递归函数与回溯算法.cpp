/*
Ԥ��֪ʶ��
	�ݹ麯������
*/

//#include <stdio.h> // printf
#include <iostream>

void compute_sum3(int i, int &sum) { // i= 3�� ��sum�ټ���3
	sum += i;
}

void compute_sum2(int i, int &sum) { // i = 2, ��sum�ټ���2
	sum += i;
	compute_sum3(i + 1, sum);
}

void compute_sum1(int i, int &sum) { // i = 1, ��sum�ټ���1 
	//���õķ�ʽ���룬�����޸� ��ߵĴ���֮ǰ��num��ֵ
	sum += i;
	compute_sum2(i + 1,sum);
}


//================================
//������������������д�ɵݹ飬�����Լ�
void compute_sum(int i, int &sum) {
	if (i > 10) {
		return; //ÿ���ݹ鶼Ҫ�н���������������ڴ�ľ�
	}
	sum += i; //��i�ۼ���sum
	compute_sum(i+1, sum); //i�����󣬵ݹ顣�����Լ�
}

int main() {
	int sum = 0;
	//compute_sum1(1,sum); //ע�������õķ�ʽ����ģ�ֱ����num������������
	compute_sum(1, sum);

	printf("sum = %d\n", sum);
	
	system("pause");
	return 0;
}