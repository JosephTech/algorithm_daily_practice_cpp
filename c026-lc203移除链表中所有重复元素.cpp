/*
��Ŀ��ɾ��valueΪ����ֵ�����нڵ�
*/

#include <iostream>  // pause
using namespace std;

struct ListNode {
	int val;  // ��ַ��
	ListNode *next;  // ָ����
	ListNode(int x): val(x), next(NULL) {}  // ���캯��
};

class Solution {
public:
	ListNode *removeElements(ListNode *head, int value) {  // ɾ������==value�Ľڵ�
		ListNode *dummyHead = new ListNode(0);  // 0Ҳ�У�-1Ҳ�У���������������� ������
		dummyHead->next = head;  // ����ͷ
		ListNode *cur = dummyHead;
		while (cur->next != NULL) {  // С���ɣ�ֱ���ж� cur->next==value����Ծ����
			if (cur->next->val == value) {  // ��cur��NULL,��value�ȣ���һֱ�ߣ��ߵ�null����!=value
				//ListNode* delNode = cur->next;  // �ȼ�¼
				cur->next = cur->next->next;  // ������
				//delete delNode;  // ��ɾ����c++��Ҫ�ֶ��ͷ��ڴ档 
				// ���vs2015�����ֶ��ͷ��ڴ��ˣ��������Լ�ɾ�� �ڵ�
			}
			else
				cur = cur->next;
		} // �ߵ�β����cur->next==NULL,����whileѭ��
		ListNode *ret_node = dummyHead->next;
		delete dummyHead;
		return ret_node;  // ���ɾ���ˣ�dummyHead->next����NULL,����NULL,
		// ������� ��headҲ��NULL���򷵻ص�Ҳ��NULL
	}
};

int main() {
	ListNode a(50), b(50), c(20), d(50), e(50), f(60), g(50), h(50);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &h;
	

	Solution solve;  //ʵ����
	ListNode *head = solve.removeElements(&a, 50);

	while (head) {
		printf("%d\n", head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}

