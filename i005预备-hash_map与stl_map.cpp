/*
参考：
C++ 中c_str()的用法详解
https://blog.csdn.net/Nine_CC/article/details/107094769
*/
/*
之前的 都是 set形式的（只考虑出现没有）
1、stl map是映射 形式的，例如把一个str映射成一个int
2、ListNode{}稍微改一下就可以自己构造 map映射
*/
#include <iostream>  // pause
#include <map>  // std::map
#include <string>

struct ListNode {  // 使用链表 构建 映射。  将字符串key，映射为整数val
	std::string key;
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {};  // 构造函数
};

int main() {  // 使用stl map
	std::map<std::string, int> hash_map;
	std::string str1 = "abc";
	std::string str2 = "def";
	std::string str3 = "xyz";
	hash_map[str1] = 1;
	hash_map[str2] = 3;
	hash_map[str3] = 66;
	if (hash_map.find(str1) != hash_map.end() ) {  // 找到了
		printf("找到了hash_map[%s] = %d\n", str1.c_str(), hash_map[str1]);
	}
	std::map<std::string, int> ::iterator it;  // 每个stl容器  有自己的迭代器。 it就是个指针罢了
	for (it = hash_map.begin(); it != hash_map.end(); it++) {
		printf("hash_map[%s] = %d\n", it->first.c_str(), it->second);  // 转化为 字符串
	}

	system("pause");
	return 0;
}