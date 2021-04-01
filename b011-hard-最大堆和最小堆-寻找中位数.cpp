/*
寻找中位数：
	用堆有一个经典的解法
	用二叉树也有一个经典的解法
*/
/*
题目：
	设计一个数据结构，该数据结构动态维护一组数据，且支持如下操作：
		1、添加元素： void addNum(int num),将整形num添加至数据结构中
		2、返回数据的中位数： double findMedium(), 返回其维护数据的中位数
	中位数的定义：
		1、若数据个数为奇数，则中位数是该组数排序后 中间的数。 例如[1、2、3] -》2
		2、若数据个数为偶数，则中位数是该组数排序后，中建两个数的平均值。 [1, 2, 3, 4] -> 2.5
*/

/*
//数据结构
class MedianFinder{
public:
	MedianFinder(){
	}
	// 向数据结构中 添加整型
	void addNum(int num){
	}
	// 返回(数据结构中维护的)中位数
	double findMedian(){
	}
};
*/
/*
最直观的方法：
	存储结构使用数组，每次 添加元素 或 查找中位数时，对数组排序，再计算结果
时间复杂度：
	?1、若添加元素时排序， addNum复杂度是O(n)， findMedian复杂度是O(1)
	?2、若查询中位数时排序，addNum复杂度是O(1),findMedian复杂度O(nlogn)

?若 添加元素 或 查询中位数是随机操作，共n次操作，按上述思想，整体复杂度最佳为O(n^2)。即O(n*n)
*/
/*
思路：
	动态维护 一个最大堆 和 一个最小堆， 最大堆存储一半数据，最小堆存储一半数据，
	维持 最大堆的堆顶，比最小堆的堆顶 小。
	（想象 最大堆是一个正三角， 最小堆是一个倒三角）
	数据是偶数个 时，中位数是 两个堆顶的平均值
	数据是奇数个 时，中位数是 多的堆 的堆顶
*/

#include <queue>
#include <stdio.h>
#include <functional>

// 数据结构
class MedianFinder {
public:
	// 构造函数
	MedianFinder() {
	}
	// 添加元素（动态维护堆）
	void addNum(int num) {
		// 空，压进去，return
		if (big_queue.empty()) {
			big_queue.push(num);
			return;
		}
		// 情况一，size等
		if (big_queue.size() == small_queue.size()) {
			if (num < big_queue.top()) {
				big_queue.push(num);
			}
			else {
				small_queue.push(num);
			}
		}
		// 情况二，最大堆size大
		else if (big_queue.size() > small_queue.size()) {
			if (num > big_queue.top()) {
				small_queue.push(num);
			}
			else {
				small_queue.push(big_queue.top());
				big_queue.pop();
				big_queue.push(num);
			}
		}
		// 情况三，最大堆size小
		else if (big_queue.size() < small_queue.size()) {
			if (num < small_queue.top()) {
				big_queue.push(num);
			}
			else {
				big_queue.push(small_queue.top());
				small_queue.pop();
				small_queue.push(num);
			}
		}
	}
	// 返回中位数
	double findMedian() { // 双精度浮点
		// size等， 取top 平均
		if (big_queue.size() == small_queue.size()) {
			//return((big_queue.top() + small_queue.top()) / 2);  //不强转换，就报错了

			double big_top = (double)big_queue.top(); //强转
			double small_top = (double)small_queue.top(); //强转
			return ((big_top + small_top) / 2);
		}
		// 谁大取谁
		else if (big_queue.size() > small_queue.size()) {
			return big_queue.top();
		}
		return small_queue.top();
	}
private:
	std::priority_queue<int, std::vector<int>, std::less<int>> big_queue; // 最大堆
	std::priority_queue<int, std::vector<int>, std::greater<int>> small_queue; // 最小堆
};

int main() {
	int a = 2;
	int b = 3;
	//double c = (a+b)/2; //隐式转换，不对
	double c = ((double)(a + b)) / 2; //强转，对
	printf("c = %lf\n", c); // %f是浮点型 %lf是双精度浮点型

	//测试代码
	MedianFinder M; //实例化
	int test[] = { 6, 10, 1, 7, 99, 4, 33 }; //整型数组test[]
	for (int i = 0; i < sizeof(test) / sizeof(test[0]); i++) {
		M.addNum(test[i]);
		printf("%lf\n", M.findMedian());
	}

	system("pause");
	return 0;
}