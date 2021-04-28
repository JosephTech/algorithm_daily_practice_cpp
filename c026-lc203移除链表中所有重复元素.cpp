/*
题目：删除value为给定值的所有节点
*/

#include <iostream>  // pause
using namespace std;

struct ListNode {
	int val;  // 地址域
	ListNode *next;  // 指针域
	ListNode(int x): val(x), next(NULL) {}  // 构造函数
};

class Solution {
public:
	ListNode *removeElements(ListNode *head, int value) {  // 删除所有==value的节点
		ListNode *dummyHead = new ListNode(0);  // 0也行，-1也行，反正不会访问它的 数据域
		dummyHead->next = head;  // 连上头
		ListNode *cur = dummyHead;
		while (cur->next != NULL) {  // 小技巧：直接判断 cur->next==value，跳跃连接
			if (cur->next->val == value) {  // 当cur不NULL,且value等，就一直走，走到null或者!=value
				//ListNode* delNode = cur->next;  // 先记录
				cur->next = cur->next->next;  // 再连接
				//delete delNode;  // 再删除。c++需要手动释放内存。 
				// 这个vs2015不用手动释放内存了，编译器自己删了 节点
			}
			else
				cur = cur->next;
		} // 走到尾部，cur->next==NULL,结束while循环
		ListNode *ret_node = dummyHead->next;
		delete dummyHead;
		return ret_node;  // 如果删完了，dummyHead->next就是NULL,返回NULL,
		// 如果传入 的head也是NULL，则返回的也是NULL
	}
};

int main() {
	ListNode a(50), b(50), c(20), d(50), e(50), f(60), g(50), h(50);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &h;
	

	Solution solve;  //实例化
	ListNode *head = solve.removeElements(&a, 50);

	while (head) {
		printf("%d\n", head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}

