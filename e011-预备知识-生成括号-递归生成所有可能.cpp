/*
n�����ţ�ʹ�õݹ��������п���
*/

#include <iostream> //pause�õ�
#include <string> // string�õ�
#include <vector> // �����õ�

void generate(std::string item, 
				int n,
				std::vector<std::string> &result) { //����string�� ��������n,  result����������
	if (item.size() == 2*n) { //�ݹ������ �ַ����ĳ���== 2n
		result.push_back(item); //�������ˣ��ͷŵ�result��
		return;
	}
	generate(item + "(", n, result); //�ַ���ƴ�ӡ� �ò�������ѡ�����Ż���������
	generate(item + ")", n, result);
	//�˴��û��ݷ�Ҳ����
}

int main() {
	std::vector<std::string> result; //�������飬�����Ž��

	generate("", 2, result); // �ݹ���á�������ַ�����2�����ţ����vector

	//��ӡ
	for (int i = 0; i < result.size(); i++) {
		printf("%s\n", result[i].c_str()); 
		//c_str()��������һ��ָ������c�ַ�����ָ��,
		//���ݺ�string��ı��������һ����,
		//ͨ��string���c_str()�����ܹ���string����ת����c�е��ַ�������ʽ
	}
	// ע�⣺����c�ַ�����ʽ��������ȷ��ӡ����֪��Ϊɶ
	system("pause");
	return 0;
}