/*
题目：
统计字符串中，每个字符出现的数量，打印

使用main函数即可
使用自带数组即可（不使用std::vector）
*/
#include <iostream>  // pause
#include <string>

int main() {
	int hash_map[128] = {0};  // 0~127的数组，全是0
	std::string str = "abfakjsodfiasfhas";
	for (int i = 0; i < str.size(); i++) {
		hash_map[str[i]] += 1;  // 计数  a97，b98...
	}
	for (int i = 0; i < 128; i++) {  // 注意：数组没有.size()，所以直接写128
		if (hash_map[i] > 0){  // 有的话，再打印
			printf("[%c][%d]:有%d个\n", i, i, hash_map[i]);  // 强转字符型，太秀了
		}
	}

	system("pause");
	return 0;
}
