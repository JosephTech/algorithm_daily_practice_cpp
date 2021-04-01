/*
STL set���� ��ʹ�� 
*/

#include <iostream> // system("pause")Ҫ��
#include <set>

int main() {
	//����test_set
	std::set<int> test_set;

	//���鳤��
	const int A_LEN = 7; // ������д
	const int B_LEN = 8;

	//����
	int a[A_LEN] = {5, 1, 4, 8, 10, 1, 3 };
	int b[B_LEN] = {2, 7, 6, 3, 1, 6, 0, 1};

	//��a���뵽 test_set
	for (int i = 0; i < A_LEN; i++) 
	{
		test_set.insert(a[i]);
	}

	// ��ӡ�ظ�Ԫ��
	for (int i = 0; i < B_LEN; i++)
	{
		if (test_set.find(b[i]) != test_set.end()) //find�ҵ�, �᷵��һ��ֵ��δ�ҵ� ����test.end() 
		{
			printf("b[%d] = %d is in array a \n", i, b[i]);
		}
	}

	system("pause");
	return 0;
}