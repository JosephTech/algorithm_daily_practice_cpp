/*
题目：
给定一个整型数组nums,(不需要用vector存)
使用 哈希表 计数排序

使用main函数即可
*/

/*
该方法，使用于数据特别多，但是数据只 集中在几个值
*/

#include <iostream>  // pause

int main(){
	int nums[10] = {999, 1, 2, 777, 7, 1, 7, 5, 3, 2};  // 10个
	int hash_map[1000] = { 0 };  // 计数
	for (int i = 0; i < 10; i++) {
		hash_map[nums[i]] += 1;  // 注意： 键是数字。值是数量
	}
	for (int i = 0; i < 1000; i++) {
		if (hash_map[i] > 0) {
			for (int j = 0; j < hash_map[i]; j++) {
				printf("%d\n", i);  // 把i打印hash_map[i]次
			}
		}
	}

	system("pause");
	return 0;
}