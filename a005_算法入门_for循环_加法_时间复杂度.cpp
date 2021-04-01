/*
时间复杂度：
	一般将“算法的执行次数作为时间复杂度的度量标准”
*/
void example(int n) {
	int sum = 0;						//运行1次  
	int total = 0;						//运行1次
	for (int i = 0; i <= n; i++) {	//运行n+1次，最后一次判定(n+1)和n谁大
		int sum = sum + i;				//运行n次, 因为在循环里，i从1到n
		for (int j = 1; j <= n; j++) {	//运行n*(n+1)次， 外圈n，内圈(n+1),同理，最后一次判定n和(n+1)谁大
			total = total + i*j;		//运行n*n次， i从1到n， j也是从1到n
		}
	}
}
/*
总计时间复杂度
	T(n) = 2n^2 + 3n + 3
	当n极大时，取极限
取最高次幂
	O(n) = n^2
*/
