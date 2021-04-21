/*
�ο���
C++ ��c_str()���÷����
https://blog.csdn.net/Nine_CC/article/details/107094769
*/
/*
֮ǰ�� ���� set��ʽ�ģ�ֻ���ǳ���û�У�
1��stl map��ӳ�� ��ʽ�ģ������һ��strӳ���һ��int
2��ListNode{}��΢��һ�¾Ϳ����Լ����� mapӳ��
*/
#include <iostream>  // pause
#include <map>  // std::map
#include <string>

struct ListNode {  // ʹ������ ���� ӳ�䡣  ���ַ���key��ӳ��Ϊ����val
	std::string key;
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {};  // ���캯��
};

int main() {  // ʹ��stl map
	std::map<std::string, int> hash_map;
	std::string str1 = "abc";
	std::string str2 = "def";
	std::string str3 = "xyz";
	hash_map[str1] = 1;
	hash_map[str2] = 3;
	hash_map[str3] = 66;
	if (hash_map.find(str1) != hash_map.end() ) {  // �ҵ���
		printf("�ҵ���hash_map[%s] = %d\n", str1.c_str(), hash_map[str1]);
	}
	std::map<std::string, int> ::iterator it;  // ÿ��stl����  ���Լ��ĵ������� it���Ǹ�ָ�����
	for (it = hash_map.begin(); it != hash_map.end(); it++) {
		printf("hash_map[%s] = %d\n", it->first.c_str(), it->second);  // ת��Ϊ �ַ���
	}

	system("pause");
	return 0;
}