/*
��arr[n]�������У���˳�����x���������±�i�����û�ҵ����򷵻�-1
*/
#include <iostream>
#include <vector>

int findx(int x, std::vector<int> arr) {
	int length = arr.size();
	for (int i = 0; i < length; i++) {
		if (arr[i] == x) {
			return i;
		}
	}
	return -1;
}

/*
n = length
��������ִ��n��
��������ִ��1��

������ʷֲ����ȣ�ƽ��ִ�д��� (1+n)/2

�������ֵ��  ÿ�����˸��ʣ��ۼ�
*/