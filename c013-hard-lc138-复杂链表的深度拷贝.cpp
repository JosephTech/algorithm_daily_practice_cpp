/*
leetCode 138. Copy List with Random Pointer
��֪һ�����ӵ������ڵ�����һ��ָ�����ӱ�����ĳ���ڵ�����ָ�루Ҳ����Ϊ�գ���
������������ȿ���

����˵��ÿ���ڵ�����ָ�룬����һ��ָ��next����һ����ָ����գ�
*/
#include <iostream>
#include <map>
#include <vector>

// ���ݽṹ
struct RandomListNode {
	int label;
	RandomListNode * next, *random;
	//���캯��
	RandomListNode(int x):label(x), next(NULL), random(NULL) {}
};

class Solution 
{
public:
	RandomListNode *copyRandomList(RandomListNode *head) // �����������ͷ
	{
		std::map<RandomListNode *, int> node_map; //�½�mapӳ�䡣 key�ǽڵ��ַ��value�ڵ����
		std::vector<RandomListNode *> node_vec; // �½�vector, ��ߴ��½ڵ㣬�ڶ���

		RandomListNode * ptr = head;
		int i = 0; //�ڵ��
		while (ptr) {
			node_vec.push_back(new RandomListNode(ptr->label)); //�ڶ��� ��������������ڵ㸳ֵ
			node_map[ptr] = i; //����mapӳ�䣬 ������� ��ַ����Ŷ�Ӧ
			ptr = ptr->next; // ����������һ����ɵ�ǰ
			i++;
		}
		node_vec.push_back(0); //�ٷŽ�ȥһ��Ԫ�أ���ֹһ��������
		i = 0; //���ã��ٱ���һ��
		ptr = head; // ���ã��ٱ���һ��
		while (ptr) {
			node_vec[i]->next = node_vec[i + 1]; // �������������nextָ����
			if (ptr->random) { //������ ��randomָ���� ��Ϊ�գ������������randomָ����
				int id = node_map[ptr->random];  //����randomָ��ĵ�ַ���õ��ڵ����
				node_vec[i]->random = node_vec[id]; //����������� random��ַ��
			}
			i++;
			ptr = ptr->next; // ��һ���ڵ㣬��ɵ�ǰ
		}
		return node_vec[0]; // �������0���ڵ�ĵ�ַ
	}
};

int main() {
	// ��������ڵ�
	RandomListNode a(10);
	RandomListNode b(20);
	RandomListNode c(30);
	RandomListNode d(40);
	RandomListNode e(50);

	// ����nextָ����
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	//����randomָ����
	a.random = &c;
	b.random = &d;
	c.random = &c;
	d.random = NULL;
	e.random = &d;

	Solution solve;
	RandomListNode * new_head = solve.copyRandomList(&a); //������ͷ��return��ͷ

	//��ӡlabel�������  random��ַ��
	while (new_head) {
		//��ӡlabel
		printf("������label = %d  ", new_head->label);

		//��ӡrandom
		if (new_head->random) {
			printf("random��ַ�� = %d  ", ((*new_head).random)->label); //������ڵ㣬.�õ�randomָ�������ü�ͷȡҲ��
			printf("randomָ���� = %d\n", new_head->random->label); // ��ͷȡ����Ҳ��
			// �ܽ᣺ �����á�ȡ������ 
			// *�Ƕ����ָ�룬�ü�ͷȡ 
		}
		else {
			printf("NULL\n");
		}
		new_head = new_head->next; //�ƶ�ָ��
	}

	system("pause");
	return 0; 
}