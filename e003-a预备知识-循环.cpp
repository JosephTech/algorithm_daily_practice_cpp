/*
��Ŀ��
	��������nums = [1, 2, 3]��
	ʹ��forѭ��
	���Ӽ�[1]�� [1,2]�� [1,2,3]��ӵ��µ�����result��
*/
#include <iostream> //pause��
#include <vector>

int main() {
	int nums[] = { 1, 2, 3 }; //����
	std::vector<int> item; // �ڲ�����  ���Ӽ��� ��vector��ʽ�洢��
	std::vector<std::vector<int>> result; //������� �����ս������vector��ʽ�洢��

	for (int i = 0; i < 3; i++) {
		item.push_back(nums[i]);
		result.push_back(item);
	}

	//��ӡresult
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) { //ע��д��result[i].size()
			printf("[%d]", result[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
