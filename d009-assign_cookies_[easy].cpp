#include <iostream>  // pause, cout
#include <vector>
#include <algorithm>  // std::sort


int findContentChildrenNum(std::vector<int> &children,
							std::vector<int> &cookies) {  // �������ã���ֹ��������
	std::sort(children.begin(), children.end());
	std::sort(cookies.begin(), cookies.end());
	int child = 0, cookie = 0;
	while (child < children.size() && cookie < cookies.size()) { // ��0��1child
		if (children[child] <= cookies[cookie]) ++child;  //child�ǵ�ǰ���ӣ������㻻��һ������
		++cookie;  // ���� ����һ���� 
	}
	return child; //���ص�ǰ���ڲ��ҵĺ��ӡ� ��ȫ�����㣬�������һ���� ��û������child2����������������2����������0��1��
}


int main01() {
	std::vector<int> children;
	std::vector<int> cookies;
	children.push_back(2);
	children.push_back(1);

	cookies.push_back(1);
	cookies.push_back(2);
	cookies.push_back(3);

	int num = findContentChildrenNum(children, cookies);

	printf("num = %d\n", num);

	system ("pause");
	return 0;
}