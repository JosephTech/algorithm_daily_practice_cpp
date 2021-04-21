/*
题目：
将整型 映射到0~9
将字符传 映射到0~9
打印出来，发现发生冲突
*/
#include <iostream>  // pause
#include <string>  // std::string

int int_func(int num, int table_len) {  // 返回key
	return num % table_len;
}


int str_func(std::string str, int table_len) {  // 返回key
	int key = 0;
	for (int i = 0; i < str.size(); i++) {
		key += str[i];  // 自动转整型
	}
	return key % table_len;
}


int main() {
	int hash_map[10] = { 0 };  // 全0的哈希表
	int table_len = 10;
	hash_map[int_func(90005, table_len)] += 1;
	hash_map[int_func(5, table_len)] += 1;
	hash_map[str_func("abc", table_len)] += 1;
	hash_map[str_func("bac", table_len)] += 1;

	// 打印
	for (int i = 0; i < table_len; i++) {
		printf("hash_map[%d] = %d\n", i, hash_map[i]);
	}

	system("pause");
	return 0;
}
/*
key相同，发生冲突，相当于生日碰撞（李永乐老师讲的）
*/