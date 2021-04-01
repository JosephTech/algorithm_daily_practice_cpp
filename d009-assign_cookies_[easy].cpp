#include <iostream>  // pause, cout
#include <vector>
#include <algorithm>  // std::sort


int findContentChildrenNum(std::vector<int> &children,
							std::vector<int> &cookies) {  // 传入引用，防止拷贝构造
	std::sort(children.begin(), children.end());
	std::sort(cookies.begin(), cookies.end());
	int child = 0, cookie = 0;
	while (child < children.size() && cookie < cookies.size()) { // 第0、1child
		if (children[child] <= cookies[cookie]) ++child;  //child是当前孩子，若满足换下一个孩子
		++cookie;  // 否则， 换下一个糖 
	}
	return child; //返回当前正在查找的孩子。 若全部满足，就是最后一个。 若没有满足child2，则满足数量就是2（即满足了0和1）
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