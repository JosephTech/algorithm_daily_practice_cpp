/*
将链表中的节点的数据域val的值 添加到vector中
使用递归
*/

#include <iostream> // pause用
#include <vector>  //vector用

struct ListNode { //结构体，默认public权限
	int val; //数据域
	ListNode *next; //地址域
	//构造函数
	ListNode(int x): val(x),next(NULL) {} //NULL防止赋空
};

void add_to_vector(ListNode *head, std::vector<int> &vec) { //传入链表头节点指针head。 传入向量vec
	if (head == NULL) { //递归结束。  也可以写成 !head
		return;
	}
	vec.push_back(head->val); // 每次递归，vec添加一个元素
	add_to_vector(head->next, vec); // 传入链表下一个节点的地址。 递归调用
}

int main() {
	// 构建 （实例化、连接）
	ListNode a(10);
	ListNode b(20);
	ListNode c(30);
	ListNode d(40);
	ListNode e(50);

	a.next = &b;
	b.next = &c;
	c.next = &d; 
	d.next = &e;//e.next默认构造是NULL

	std::vector<int> vec; //初始化一个vec
	
	add_to_vector(&a, vec); //将链表的数据域 添加到 vec中

	// 打印
	for (int i = 0; i < vec.size(); i++) {
		printf("[%d]", vec[i]);
	}
	printf("\n");


	system("pause");
	return 0;
}