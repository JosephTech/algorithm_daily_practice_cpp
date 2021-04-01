/*
����������Ľ���

˼·1��
	ʹ��set����
*/

#include <iostream>
#include <set>

struct ListNode {
	int val;
	ListNode * next;

	//���캯��
	ListNode(int x):val(x),next(NULL) {}
};

class Solution {
	ListNode * findIntersectionNode(ListNode *headA, ListNode *headB)
	{
		// ����ڵ�set����
		std::set<ListNode*> node_set;

		// while����A,����ڵ�set������
		while (headA) 
		{
			node_set.insert(headA);
			headA = headA->next;
		}

		// while����B, ���ص�һ����ͬ�Ľڵ�ĵ�ַ
		while (headB)
		{
			// ���ҵ����򷵻ظýڵ�ĵ�ַ
			if (node_set.find(headB) != node_set.end()) //  =end��û�ҵ��������ڣ����ҵ��� 
			{
				return headB;
			}
			headB = headB->next; //������ ��һ����ɵ�ǰ
		}
		// ������Ҳû�ҵ�
		return NULL;
	}
};


int main() 
{

	system("pause");
	return 0;
}