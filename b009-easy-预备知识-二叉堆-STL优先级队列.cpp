/*
 最大二叉堆，最大值先出的完全二叉树；
 最小二叉堆，最小值先出的完全二叉树；
*/
/*
最小二叉堆、最大二叉堆：
		top()的时间复杂度O(1)
		调整、插入的时间复杂度 log(n)

都满足堆的属性：
		最大堆的左子树堆 是最大堆、右子树堆是最大堆

		最小堆 的 子堆 都是最小堆
*/

// 例题
// STL优先级队列（二叉树）
// 二叉堆， 最小（大）值先出的完全二叉树，也叫作优先级队列
// 在STL中，优先级队列在<queue>头文件中
#include <stdio.h>
#include <queue>
#include <functional> //有了这一句，std::greater才不会报错

int main() {
	std::priority_queue<int> big_heap; // 默认构造最大堆,即从大到小出队。 这里为啥有下划线？
	std::priority_queue<int, std::vector<int>, std::greater<int> > small_heap; //构造最小堆。即从小到大出队
	std::priority_queue<int, std::vector<int>, std::less<int> > big_heap2; // 构造最大堆。 即从从大到小出队

	// 空了,打印一句话
	if (big_heap.empty()) {
		printf("big_heap is empty! \n");
	}
	
	// 整形数组test： 6、 10、 1、 7、 99、 4、 33
	int test[] = { 6, 10, 1, 7, 99 , 4, 33 };

	// for循环，push进去
	for (int i = 0; i < sizeof(test) / sizeof(test[0]); i++) {
		big_heap.push(test[i]);
	}

	//打印top
	printf("二叉堆，最大值先出的完全二叉树(也叫优先级队列)的top = %d\n", big_heap.top());

	// .push(1000)，打印
	big_heap.push(1000); // push操作时，运算复杂度是log(n), 其中n是元素个数
	printf("二叉堆 top = %d\n", big_heap.top());

	// pop仨数
	for (int i = 0; i < 3; i++) {
		big_heap.pop();
	}

	//打印top
	printf("top = %d\n", big_heap.top());

	// 打印size
	printf("size = %d\n", big_heap.size());

	system("pause");
	return 0;
}