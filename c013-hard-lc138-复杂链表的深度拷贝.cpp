/*
leetCode 138. Copy List with Random Pointer
已知一个复杂的链表，节点中有一个指向本链接表任意某个节点的随机指针（也可能为空），
求这个链表的深度拷贝

就是说，每个节点有俩指针，其中一个指向next，另一个乱指（或空）
*/
#include <iostream>
#include <map>
#include <vector>

// 数据结构
struct RandomListNode {
	int label;
	RandomListNode * next, *random;
	//构造函数
	RandomListNode(int x):label(x), next(NULL), random(NULL) {}
};

class Solution 
{
public:
	RandomListNode *copyRandomList(RandomListNode *head) // 传入老链表的头
	{
		std::map<RandomListNode *, int> node_map; //新建map映射。 key是节点地址，value节点序号
		std::vector<RandomListNode *> node_vec; // 新建vector, 里边存新节点，在堆区

		RandomListNode * ptr = head;
		int i = 0; //节点号
		while (ptr) {
			node_vec.push_back(new RandomListNode(ptr->label)); //在堆区 构建新链表，逐个节点赋值
			node_map[ptr] = i; //构建map映射， 老链表的 地址和序号对应
			ptr = ptr->next; // 遍历。即下一个变成当前
			i++;
		}
		node_vec.push_back(0); //再放进去一个元素，防止一会连空了
		i = 0; //复用，再遍历一遍
		ptr = head; // 复用，再遍历一遍
		while (ptr) {
			node_vec[i]->next = node_vec[i + 1]; // 逐个连上新链表，next指针域
			if (ptr->random) { //老链表 的random指针域 不为空，就连新链表的random指针域
				int id = node_map[ptr->random];  //根据random指向的地址，得到节点序号
				node_vec[i]->random = node_vec[id]; //连上新链表的 random地址域
			}
			i++;
			ptr = ptr->next; // 下一个节点，变成当前
		}
		return node_vec[0]; // 新链表第0个节点的地址
	}
};

int main() {
	// 构建链表节点
	RandomListNode a(10);
	RandomListNode b(20);
	RandomListNode c(30);
	RandomListNode d(40);
	RandomListNode e(50);

	// 连接next指针域
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	//连接random指针域
	a.random = &c;
	b.random = &d;
	c.random = &c;
	d.random = NULL;
	e.random = &d;

	Solution solve;
	RandomListNode * new_head = solve.copyRandomList(&a); //传入老头，return新头

	//打印label数据域和  random地址域
	while (new_head) {
		//打印label
		printf("数据域label = %d  ", new_head->label);

		//打印random
		if (new_head->random) {
			printf("random地址域 = %d  ", ((*new_head).random)->label); //解出来节点，.得到random指针域。再用箭头取也行
			printf("random指针域 = %d\n", new_head->random->label); // 箭头取出来也行
			// 总结： 对象用·取东西。 
			// *是对象的指针，用箭头取 
		}
		else {
			printf("NULL\n");
		}
		new_head = new_head->next; //移动指针
	}

	system("pause");
	return 0; 
}