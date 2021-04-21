/*
拉链法 解决冲突
将 哈希函数 结果相同的节点，连接在同一个单链表中
*/
/*
插入：  头插法
*/
/*
查找value：	遍历  以t[hash_key]为头指针的单链表，查找是否==value
(返回true  和  false)
*/
#include <iostream>  // pause
#include <vector>

struct ListNode{  // 哈希表 的值就是单链表
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {};  // 构造函数
};

int hash_func(int num, int table_len) {
	return num % table_len;  // 键
}

void insert(ListNode *hash_map[], ListNode *node, int table_len) {  // 注意 插入的是节点
	int hash_key = hash_func(node->val, table_len);  // 注意是node->val
	node->next = hash_map[hash_key];  // 头插法， 这个位置就是个节点
	hash_map[hash_key]= node;
}

bool search_func(int target, ListNode *hash_map[], int table_len) {
	int hash_key = hash_func(target, table_len);
	ListNode *head = hash_map[hash_key];
	while (head) {
		if (head->val == target) {
			return true;
		}
		head = head->next;
	}
	return false;
}



int main() {  // 测试
	const int TABLE_LEN = 11;  // 一般取质数，hash表更稀疏
	ListNode *hash_map[TABLE_LEN] = { 0 };  // 这么多个0初始化 ListNode
	int nums[] = { 1, 2, 3, 5, 700, 400, 200, 500, 600, 800, 5, 66, 88 };
	std::vector<ListNode *> node_vec;  // 构建node_vec
	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {  // 数组 果然 没有vector好用
		node_vec.push_back(new ListNode(nums[i]));  // 注意 是节点，不是节点指针
	}
	for (int i = 0; i < node_vec.size(); i++) {  // 全 插入
		insert(hash_map, node_vec[i], TABLE_LEN);  // 为啥不用引用？  为啥不用引用也能插入？因为这个函数只是换了指针，
	}
	printf("hash table: \n");
	for (int i = 0; i < TABLE_LEN; i++) {  // 访问 哈希表 每个单链表
		printf("[%d]:", i);
		ListNode *head = hash_map[i];  // 头节点指针
		while (head) {
			printf("---%d", head->val);
			head = head->next;
		}
		printf("\n");
	}
	printf("找到%d没：[%d]\n", 88, search_func(88, hash_map, TABLE_LEN));
	printf("找到%d没：[%d]\n", 6000, search_func(6000, hash_map, TABLE_LEN));

	// 释放堆区数据
	for (int i = 0; i < node_vec.size(); i++) {
		delete node_vec[i];  // 因为存的是节点地址（堆区的）， 直接删了就行，不用管它们之间 在拉链法中 怎么连接的。
	}

	system("pause");
	return 0;
}

