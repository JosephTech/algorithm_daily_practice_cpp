/*
LeetCode141.Linked List Cycle
leetCode142.Linked List Cycle II
��֪�����п��ܴ��ڻ������л������ػ���ʼ�ڵ㣬���򷵻�NULL
*/
/*
˼·1��ʹ��set�󻷵���ʼ�ڵ�
	1�����������������нڵ��Ӧ��ָ�����set�����������нڵ�ĵ�ַ����set��
	2���ڱ�������ڵ�ǰ����Ҫ��set�в��ң���һ����set�з��ֵĽڵ��ַ���������������
*/
#include <iostream>
#include <set>

// ����ڵ�
struct ListNode {
	int val;
	ListNode *next; //ָ�룬ָ��ListNodeʵ����������->��ʵ����ȡֵ

	// ���캯��
	ListNode(int x):val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * detectCycle(ListNode *head) 
	{
		// ʵ���� set����
		std::set<ListNode*> node_set;

		// ��������insert��setǰ��ʹ��find�ж��Ƿ����
		while (head)
		{
			if (node_set.find(head) != node_set.end())  // û�鵽������end
			{
				return head;
			}
			node_set.insert(head); //����
			head = head->next;
		}
		return NULL;
	}
};


int main() {

	system("pause");
	return 0;
}
