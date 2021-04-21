/*
������ �����ͻ
�� ��ϣ���� �����ͬ�Ľڵ㣬������ͬһ����������
*/
/*
���룺  ͷ�巨
*/
/*
����value��	����  ��t[hash_key]Ϊͷָ��ĵ����������Ƿ�==value
(����true  ��  false)
*/
#include <iostream>  // pause
#include <vector>

struct ListNode{  // ��ϣ�� ��ֵ���ǵ�����
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {};  // ���캯��
};

int hash_func(int num, int table_len) {
	return num % table_len;  // ��
}

void insert(ListNode *hash_map[], ListNode *node, int table_len) {  // ע�� ������ǽڵ�
	int hash_key = hash_func(node->val, table_len);  // ע����node->val
	node->next = hash_map[hash_key];  // ͷ�巨�� ���λ�þ��Ǹ��ڵ�
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



int main() {  // ����
	const int TABLE_LEN = 11;  // һ��ȡ������hash���ϡ��
	ListNode *hash_map[TABLE_LEN] = { 0 };  // ��ô���0��ʼ�� ListNode
	int nums[] = { 1, 2, 3, 5, 700, 400, 200, 500, 600, 800, 5, 66, 88 };
	std::vector<ListNode *> node_vec;  // ����node_vec
	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {  // ���� ��Ȼ û��vector����
		node_vec.push_back(new ListNode(nums[i]));  // ע�� �ǽڵ㣬���ǽڵ�ָ��
	}
	for (int i = 0; i < node_vec.size(); i++) {  // ȫ ����
		insert(hash_map, node_vec[i], TABLE_LEN);  // Ϊɶ�������ã�  Ϊɶ��������Ҳ�ܲ��룿��Ϊ�������ֻ�ǻ���ָ�룬
	}
	printf("hash table: \n");
	for (int i = 0; i < TABLE_LEN; i++) {  // ���� ��ϣ�� ÿ��������
		printf("[%d]:", i);
		ListNode *head = hash_map[i];  // ͷ�ڵ�ָ��
		while (head) {
			printf("---%d", head->val);
			head = head->next;
		}
		printf("\n");
	}
	printf("�ҵ�%dû��[%d]\n", 88, search_func(88, hash_map, TABLE_LEN));
	printf("�ҵ�%dû��[%d]\n", 6000, search_func(6000, hash_map, TABLE_LEN));

	// �ͷŶ�������
	for (int i = 0; i < node_vec.size(); i++) {
		delete node_vec[i];  // ��Ϊ����ǽڵ��ַ�������ģ��� ֱ��ɾ�˾��У����ù�����֮�� ���������� ��ô���ӵġ�
	}

	system("pause");
	return 0;
}

