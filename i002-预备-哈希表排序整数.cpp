/*
��Ŀ��
����һ����������nums,(����Ҫ��vector��)
ʹ�� ��ϣ�� ��������

ʹ��main��������
*/

/*
�÷�����ʹ���������ر�࣬��������ֻ �����ڼ���ֵ
*/

#include <iostream>  // pause

int main(){
	int nums[10] = {999, 1, 2, 777, 7, 1, 7, 5, 3, 2};  // 10��
	int hash_map[1000] = { 0 };  // ����
	for (int i = 0; i < 10; i++) {
		hash_map[nums[i]] += 1;  // ע�⣺ �������֡�ֵ������
	}
	for (int i = 0; i < 1000; i++) {
		if (hash_map[i] > 0) {
			for (int j = 0; j < hash_map[i]; j++) {
				printf("%d\n", i);  // ��i��ӡhash_map[i]��
			}
		}
	}

	system("pause");
	return 0;
}