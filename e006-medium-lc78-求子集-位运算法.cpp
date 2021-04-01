/* 全集：
0 = 000
1 = 001
2 = 010
3 = 011
4 = 100
5 = 101
6 = 110
7 = 111
*/
/*
位代表有没有：
	用001代表有A，即有nums[0]
	用010代表有B, 即有nums[1]
	用100代表有C，即有nums[2]

0 与 A B C求and 得[]
1 与 A B C求and 得[A]
2 与 A B C求and 得[B]
3 与 A B C求and 得[B] [A]
4 与 A B C求and 得[C]
5 与 A B C求and 得[C][A]
6 与 A B C求and 得[C][B]
7 与 A B C求and 得[C][C][A]

注意：是位运算  一个&
...
*/
#include <iostream>
#include <vector>

class Solutionl {
public:
	std::vector<std::vector<int>> subSet(std::vector<int> &nums) {
		std::vector<std::vector<int>> result; //存储最终结果，里边放的是数组
		int all_set = 1 << nums.size(); // 1左移3位  变成1000 = 8
		for (int i = 0; i < all_set; i++) { //外圈循环0 1 2 3 4 5 6 7
			std::vector<int> item; //初始化item，接下来往里边放
			for (int j = 0; j < nums.size(); j++){ // 内圈循环，A B C
				if (i & (1 << j)) { //i分别与A、 B 、C求and。  1左移0位； 1左移1位；  1左移2位
					item.push_back(nums[j]); //注意： 是位运算，一个&
				}
			}
			result.push_back(item);
		}
		return result;
	}
};

int main() {
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	Solution solve;
	std::vector<std::vector<int>> result = solve.subSet(nums);

	//打印结果
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("[%d]",result[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}





















