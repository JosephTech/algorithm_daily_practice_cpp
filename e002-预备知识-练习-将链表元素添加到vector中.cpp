/*
�������еĽڵ��������val��ֵ ��ӵ�vector��
ʹ�õݹ�
*/

#include <iostream> // pause��
#include <vector>  //vector��

struct ListNode { //�ṹ�壬Ĭ��publicȨ��
	int val; //������
	ListNode *next; //��ַ��
	//���캯��
	ListNode(int x): val(x),next(NULL) {} //NULL��ֹ����
};

void add_to_vector(ListNode *head, std::vector<int> &vec) { //��������ͷ�ڵ�ָ��head�� ��������vec
	if (head == NULL) { //�ݹ������  Ҳ����д�� !head
		return;
	}
	vec.push_back(head->val); // ÿ�εݹ飬vec���һ��Ԫ��
	add_to_vector(head->next, vec); // ����������һ���ڵ�ĵ�ַ�� �ݹ����
}

int main() {
	// ���� ��ʵ���������ӣ�
	ListNode a(10);
	ListNode b(20);
	ListNode c(30);
	ListNode d(40);
	ListNode e(50);

	a.next = &b;
	b.next = &c;
	c.next = &d; 
	d.next = &e;//e.nextĬ�Ϲ�����NULL

	std::vector<int> vec; //��ʼ��һ��vec
	
	add_to_vector(&a, vec); //������������� ��ӵ� vec��

	// ��ӡ
	for (int i = 0; i < vec.size(); i++) {
		printf("[%d]", vec[i]);
	}
	printf("\n");


	system("pause");
	return 0;
}