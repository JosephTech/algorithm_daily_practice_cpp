/*
�����㷨��
��һ����ģΪN������ֽ�ΪK����ģ��С�������⣬��Щ�������໥������
����ԭ����������ͬ�� ���������Ľ�󣬽��кϲ���
�Ϳɵõ�ԭ����Ľ⡣

һ�㲽�裺
1���ֽ⣬��Ҫ��������⻮�ֳ����ɹ�ģ��С��ͬ������
2����⣬�������⻮�ֵ��㹻С��ʱ���ýϼ򵥵ķ������
3���ϲ�����ԭ�����Ҫ�󣬽�������Ľ����ϲ� ����ԭ����Ľ�
*/
/*
Ԥ��֪ʶ���鲢�����Ӷȷ���
	����n��Ԫ�أ�n��Ԫ�ع鲢�����ʱ��T(n)
	��ʱ�� = �ֽ�ʱ�� + ���������ʱ�� + �ϲ�ʱ��

	�ֽ�ʱ�䣺����ԭ������Ϊ�����������ʱ�䣬ʱ�临�Ӷ�ΪO(n)
	��������������vectorʱ��ΪO(n); ��ʹ���±꣬����ʹO(1)��

	���������ʱ�䣺����������������ʱ�� 2T(n/2)

	�ϲ�ʱ�䣺������������������鲢��ʱ�䣬����Ϊ����Ԫ����ӣ�������Ԫ�ر���һ�飩���Ӷ�O(n)

T(n) = 
	 = 2T(n/2) + 2*O(n)				//�������������ʱ��,ÿ����ģ��һ�룬ΪT(n/2)��
									// ������⣺��2*O(n)����ߵ�2,������,��������O(n)
	 = O(n) + 2T(n/2)
	 = O(n + 2n/2 + 4n/4 +... + logn*n/logn)							
									// �ŵ�O���
									// 2^k = n������logn = k �� (����logn����2Ϊ�׵�)
									// �������൱��logn��n�����
	 = O(nlogn)						// ������⣺n����������Ե�����������logn�����������֮ǰ�ĳ���O(n)����ʡ��
*/

#include <iostream> //pause�õ�
#include <vector>

void merge_sort_two_vec(std::vector<int> &sub_set1,
						std::vector<int> &sub_set2,
						std::vector<int> &vec) { //�������á� ����vec�Ǳ��κϲ����
	int i = 0; // sub_set1�е�i��Ԫ��
	int j = 0; // sub_sset2�е�i��Ԫ��
	while (i < sub_set1.size() && j < sub_set2.size()) { //������ʱ��
		if (sub_set1[i] <= sub_set2[j]) { //˭С ��˭��ӵ�vec��
			vec.push_back(sub_set1[i]);
			i++;
		}
		else {
			vec.push_back(sub_set2[j]);
			j++;
		}
	}
	// �ĸ�ʣ�£�����ĸ�
	for (; i < sub_set1.size(); i++) {
		vec.push_back(sub_set1[i]);
	}
	for (; j < sub_set2.size(); j++) {
		vec.push_back(sub_set2[j]);
	}
}

void merge_sort(std::vector<int> &vec) { //��������
	if (vec.size() < 2) { //�ݹ���������� ������һ��ݹ�
		return;
	}
	std::vector<int> subset1; //��ǰһ��
	std::vector<int> subset2; //�ź�һ��
	int mid = vec.size() / 2;
	for (int i = 0; i < mid; i++) {//0~mid-1   ǰһ�����subset1
		subset1.push_back(vec[i]);
	}
	for (int i = mid; i < vec.size(); i++) {
		subset2.push_back(vec[i]);
	}
	// �ݹ����
	merge_sort(subset1); //��ǰһ��
	merge_sort(subset2); //�ź�һ��
	vec.clear(); //���vec��׼�������װ�źõ�
	merge_sort_two_vec(subset1, subset2, vec); //�ϲ��ɵ�vec��Ϊ��һ���merge_sort(subset) ���οռ�
												//��Ϊ��������
}

//// �������ݣ��򵥲���
//int main() {
//	std::vector<int> vec;
//	int test[] = { 5, -7, 9, 8, 1, 4, -3, 10, 2, 0 };
//	for (int i = 0; i < 10; i++){
//		vec.push_back(test[i]);
//	}
//
//	// �鲢���򡢴�ӡ
//	merge_sort(vec);
//	for (int i = 0; i < vec.size(); i++) {
//		printf("[%d]", vec[i]);
//	}
//	printf("\n");
//
//	system("pause");
//	return 0;
//}

// �������ݲ���
#include <stdlib.h> // ������������õ�
#include <algorithm> // ����sort���Թ鲢�����Ƿ���ȷ
#include <assert.h>
#include <time.h> //time��Ϊ���������

int main() {
	std::vector<int> vec1;
	std::vector<int> vec2;
	srand(time(NULL));
	for (int i = 0; i < 10000; i++) { //randһ���
		int num = (rand() *  rand()) % 100003; //rand*randȡ���������������һ��
												// ������ ȡ�࣬ ���ø���ɢ�������
		vec1.push_back(num);
		vec2.push_back(num);
	}
	merge_sort(vec1); //���ù鲢����
	std::sort(vec2.begin(), vec2.end()); //����std�Դ�����
	assert(vec1.size() == vec2.size()); //�������鳤����ͬ
	for (int i = 0; i < vec1.size(); i++) { //����ÿ��Ԫ����ͬ
		assert(vec1[i] == vec2[i]);
	}
	//������ͨ����
	system("pause");
	return 0;
}