/*
Ԥ��֪ʶ
ջ(ջ����ջ��)��  �Ƚ����  �����Ա�
�ѣ���ͷ����  �Ƚ��ȳ�  �����Ա�

push����
pop����
*/
/*
s.push()   ѹ��ջ��
s.pop()    ����ջ��
s.empty()  �ж�ջ�Ƿ�Ϊ��
s.size()   ջ�洢��Ԫ�ظ���
s.top()    ȡ��ջ��
*/
#include <stdio.h>
#include <stack>
int main() {
	std::stack<int> s;
	if (s.empty()) {
		printf("s is empty \n"); //? �����仰
	}
	s.push(5);
	s.push(6);
	s.push(10);//?
	printf("s.top = %d\n", s.top()); // 10

	s.pop();
	s.pop();//?
	printf("s.top = %d\n", s.top()); // 5
	printf("s.size = %d\n", s.size()); // 1

	system("pause");
	return 0;
}