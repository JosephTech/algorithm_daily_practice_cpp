/*
��Ŀ��
ͳ���ַ����У�ÿ���ַ����ֵ���������ӡ

ʹ��main��������
ʹ���Դ����鼴�ɣ���ʹ��std::vector��
*/
#include <iostream>  // pause
#include <string>

int main() {
	int hash_map[128] = {0};  // 0~127�����飬ȫ��0
	std::string str = "abfakjsodfiasfhas";
	for (int i = 0; i < str.size(); i++) {
		hash_map[str[i]] += 1;  // ����  a97��b98...
	}
	for (int i = 0; i < 128; i++) {  // ע�⣺����û��.size()������ֱ��д128
		if (hash_map[i] > 0){  // �еĻ����ٴ�ӡ
			printf("[%c][%d]:��%d��\n", i, i, hash_map[i]);  // ǿת�ַ��ͣ�̫����
		}
	}

	system("pause");
	return 0;
}
