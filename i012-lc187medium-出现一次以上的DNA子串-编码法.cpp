/*
λ���㷨��
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int g_hash_map[1048576] = { 0 };  // 2^21-1ȫ�����顣 ��ϣ̫���ˣ�����ȫ�֣��������ڴ��У����������������

string changeToDNA(int dna_int) {
	static const char ch_map[] = {'A', 'C', 'G', 'T'};  // 0 1 2 3
	string str;
	for (int i = 0; i < 10; i++) {  // ��Ϊ0��ʱ��
		str += ch_map[dna_int & 3];  // λ���㣬��λ�룬 ȥ����λ
		dna_int = dna_int >> 2;  // һ��Ҫ���¸�ֵ =
	}
	return str;
}

class Solution {
public:
	vector<string> substringDNA(string str) {  //
		vector<string> result;
		if (str.length() < 10)
			return result;  // �쳣
		for (int i = 0; i < sizeof(g_hash_map) / sizeof(g_hash_map[0]); i++) {  // ��� ȫ�ֱ�����ʼ��
			g_hash_map[i] = 0;
		}
		int char_map[128] = {0};  // �ַ���ϣ���� �ַ���ֵ ����0123
		char_map['A'] = 0;
		char_map['C'] = 1;
		char_map['G'] = 2;
		char_map['T'] = 3;
		int key = 0;
		for (int i = 9; i >= 0; i--)
			key = (key << 2) + char_map[str[i]];  // ��4�� ���ӡ� С��ģʽ
		g_hash_map[key] = 1;  // ��һ�����ַ��� ����
		for (int i = 10; i < str.length(); i++) {  // �����ַ���������
			key = key >> 2; // ����4 ��������λ���ճ���ͷ����  һ��Ҫ���¸�ֵ =
			key = key | (char_map[str[i]] << 18);  // ��2^18, ��λ��  �����Ƿŵ�ͷ�����൱�ڼ��ϣ�
			g_hash_map[key]++;
		}
		for (int i = 0; i < sizeof(g_hash_map) / sizeof(g_hash_map[0]); i++) {
			if (g_hash_map[i] > 1) {  // ���ظ�
				result.push_back(changeToDNA(i));  // i��DNA�ı���
			}
		}
		return result;
	}

};

int main() {
	string str = "AAAAACCCCCAAAAAACCCCCCAAAAAGGGTTT";
	Solution solve; // ʵ����
	vector<string> result = solve.substringDNA(str);
	for (int i = 0; i < result.size(); i++)
		printf("%s\n", result[i].c_str());  // ǿת�ַ���


	system("pause");
	return 0;
}