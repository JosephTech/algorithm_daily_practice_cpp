#include <stdio.h>
#include <string>
//#include <iostream> ��using namespace std  ������cout

int main() {
	std::string s1 = "3";
	int num1 = 0;
	num1 = s1[0] - '0';
	printf( "�ַ���'3' - '0'��ASCII����������֣�%d\n", num1);

	int number = 0;
	std::string s = "12345";
	for (int i = 0; i < s.length(); i++) { //i��0~4
		number = number * 10 + s[i] - '0'; // 1��12�� 123�� 1234�� 12345
	}
	printf("number = %d\n", number);
	system("pause");
	return 0;
}