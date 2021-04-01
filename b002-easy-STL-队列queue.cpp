/*
Ԥ��֪ʶ��
STL queue����
*/
/*
Q.empty()  �ж϶����Ƿ�Ϊ��
Q.front()  ���ض���ͷ��Ԫ��
Q.back()   ���ض���β��Ԫ��
Q.pop()		������ͷԪ��
Q.push()   ѹ����β
Q.size()   ���ض��� ����Ԫ�صĸ���
*/

#include <stdio.h>
#include <queue>
int main() {
	std::queue<int> Q; // �½�һ��Q����
	if (Q.empty()) {
		printf("Q is empty! \n");
	}
	Q.push(5); //?
	Q.push(6);
	Q.push(10);
	printf("Q.front = %d\n", Q.front()); //5
	Q.pop();
	Q.pop();//?
	printf("Q.front = %d\n", Q.front()); //10
	Q.push(1); //?
	printf("Q.back = %d\n", Q.back()); //1
	printf("Q.size = %d\n", Q.size()); //2


	system("pause");
	return 0;
}