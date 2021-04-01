/*
计算递归 的栈空间
*/

int func(int n) { // 计算n的阶乘
	if (n < 0) {
		return -1; // 报错
	}
	else if(n == 0 || n==1) {
		return 1;  // 0的阶乘是1， 1的阶乘是1
	}
	else {
		return n * func(n - 1);
	}
}

/*
复杂度分析：（直接画递归树，数的深度就是栈空间的大小）
	n=5时候，

	5*func(4),
		4*func(3),
			3*func(2), 
				2*func(1), 
					func1

	本次递归的栈空间为5
*/