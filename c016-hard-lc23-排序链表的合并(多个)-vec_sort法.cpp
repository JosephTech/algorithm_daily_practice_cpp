/*
˼·2��
	��k*n���ڵ�ŵ�vetcor�У��ٽ�vector�����ٽ��ڵ�˳��������

����k������ƽ��ÿ��������n���ڵ㣬
ʱ�临�Ӷȣ�  
	��Ϊ��������Ÿ��ӶȾ���nlogn�� һ��kN���ڵ㣬
	kN���ڵ�˳��������ʱ�临�Ӷ���kN
	���ԣ�
	kN*logkN + kN
	=O(kN*logkN)

	����k=100,n=10000ʱ
	logkN = 20��С��k
	��
	kNlogkN < k^2 * N
	�ȱ�������
*/

#include <iostream>
#include <vector>
#include <algorithm>

// ����-���ݽṹ
struct ListNode {
	int val;
	ListNode *next;
	// ���캯��
	ListNode(int x): val(x), next(NULL) {}
};

//�ȽϺ���
bool cmp(const ListNode *a, const ListNode *b) // constȷ��  ������������
{
	return a->val < b->val;
}


class Solution {
public:
	ListNode *mergeKLists(std::vector<ListNode *> &lists) { //�������ã����⿽������
		std::vector<ListNode *> node_vec;
		//ȫ��vector��
		for (unsigned int i = 0; i < lists.size(); i++) {
			ListNode *head = lists[i]; //ȡ��ͷ��ָ�룬��Ϊhead
			while (head) {
				node_vec.push_back(head);
				head = head->next; // ����������   ��ӵ�vector��
			}
		}
		// node_vecû��Ԫ�أ��ͷ���NULL��  �о���һ���Ƿϻ������Բ�д
		if (node_vec.size() == 0) {
			return NULL;
		}
		//sort�������ϡ�����β�͡�����
		std::sort(node_vec.begin(), node_vec.end(), cmp);
		for (unsigned int i = 1; i < node_vec.size(); i++) {
			node_vec[i - 1]->next = node_vec[i];
		}
		node_vec[node_vec.size() - 1]->next = NULL;
		return node_vec[0];
	}
};


int main() {
	ListNode a(10);
	ListNode b(40);
	ListNode c(70);
	a.next = &b;
	b.next = &c;

	ListNode e(20);
	ListNode f(80);
	e.next = &f;

	ListNode g(5);
	ListNode h(30);
	ListNode i(90);
	g.next = &h;
	h.next = &i;

	std::vector<ListNode *> node_vec;
	node_vec.push_back(&a);
	node_vec.push_back(&e);
	node_vec.push_back(&g);

	Solution solve;
	ListNode *head = solve.mergeKLists(node_vec);

	//��ӡ
	while (head) {
		printf("%d  ", head->val);
		head = head->next; //�ƶ�ָ��
	}
	printf("\n");

	system("pause");
	return 0;
}
