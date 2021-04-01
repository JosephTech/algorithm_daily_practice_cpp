/*
���η� �õݹ�ʵ�ּ򵥣���Ҳ���Ըĳɷǵݹ�if else��

���ݷ� �õݹ�ʵ�ּ򵥣������Ѹĳɷǵݹ�If else��

�鲢����merge sort
*/
/*

��Ŀ��
	��֪�������������飬������������ϲ�Ϊһ���������顣

���磺	
	���� array_A = [2, 5, 8, 10]
		 array_B = [1, 3, 5, 7, 30, 50]
	�鲢�����
		[1, 2, 3, 5, 5, 7, 8, 20, 30, 50]
*/
#include <iostream> //pause�õ�
#include <vector> 

void merge_sort_two_vec(std::vector<int> &subvec1,
						std::vector<int> &subvec2,
						std::vector<int> &resultVec) { //�������ã�ֱ���޸�ԭֵ�����⿽������
	int i = 0; //subvec1�ĵ�i��Ԫ��
	int j = 0; //subvec2�ĵ�j��Ԫ��
	while (i < subvec1.size() && j < subvec2.size()) { //˭С��˭�� ��ȷ�subvec1
		if (subvec1[i] <= subvec2[j]) {
			resultVec.push_back(subvec1[i]);
			i++;
		}
		else {
			resultVec.push_back(subvec2[j]);
			j++;
		}
	}
	//ʣ˭��˭
	for (; i < subvec1.size(); i++) { //ע�⣬�����;���㣬����ʡ��
		resultVec.push_back(subvec1[i]);
	}
	for (; j < subvec2.size(); j++) {
		resultVec.push_back(subvec2[j]);
	}
}

int main() {
	int test1[] = { 2, 5, 8, 20 };
	int test2[] = { 1, 3, 5, 7, 30, 50 };

	// ����
	std::vector<int> sub_vec1;
	std::vector<int> sub_vec2;
	std::vector<int> vec;

	// ����
	for (int i = 0; i < 4; i++) { //ע����С�ڡ� 0 1 2 3
		sub_vec1.push_back(test1[i]);
	}
	for (int i = 0; i < 6; i++) {
		sub_vec2.push_back(test2[i]);
	}
	//���ú���
	merge_sort_two_vec(sub_vec1, sub_vec2, vec);

	//��ӡ
	for (int i = 0; i < vec.size(); i++) {
		printf("[%d]", vec[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}