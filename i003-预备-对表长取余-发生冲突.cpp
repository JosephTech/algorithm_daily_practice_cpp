/*
��Ŀ��
������ ӳ�䵽0~9
���ַ��� ӳ�䵽0~9
��ӡ���������ַ�����ͻ
*/
#include <iostream>  // pause
#include <string>  // std::string

int int_func(int num, int table_len) {  // ����key
	return num % table_len;
}


int str_func(std::string str, int table_len) {  // ����key
	int key = 0;
	for (int i = 0; i < str.size(); i++) {
		key += str[i];  // �Զ�ת����
	}
	return key % table_len;
}


int main() {
	int hash_map[10] = { 0 };  // ȫ0�Ĺ�ϣ��
	int table_len = 10;
	hash_map[int_func(90005, table_len)] += 1;
	hash_map[int_func(5, table_len)] += 1;
	hash_map[str_func("abc", table_len)] += 1;
	hash_map[str_func("bac", table_len)] += 1;

	// ��ӡ
	for (int i = 0; i < table_len; i++) {
		printf("hash_map[%d] = %d\n", i, hash_map[i]);
	}

	system("pause");
	return 0;
}
/*
key��ͬ��������ͻ���൱��������ײ����������ʦ���ģ�
*/