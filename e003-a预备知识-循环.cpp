/*
题目：
	给定数组nums = [1, 2, 3]，
	使用for循环
	将子集[1]、 [1,2]、 [1,2,3]添加到新的数组result中
*/
#include <iostream> //pause用
#include <vector>

int main() {
	int nums[] = { 1, 2, 3 }; //数组
	std::vector<int> item; // 内层数组  （子集， 以vector方式存储）
	std::vector<std::vector<int>> result; //外层数据 （最终结果，以vector方式存储）

	for (int i = 0; i < 3; i++) {
		item.push_back(nums[i]);
		result.push_back(item);
	}

	//打印result
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) { //注意写法result[i].size()
			printf("[%d]", result[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
