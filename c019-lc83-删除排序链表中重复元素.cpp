/*
LeetCode精选100题——第83题——删除排序链表中的重复元素
https://blog.csdn.net/weixin_43338519/article/details/102516371?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-0&spm=1001.2101.3001.4242
*/

/*
删除排序链表中的重复元素，使得每个元素只出现一次
例如：
	1 -> 1 -> 2
	1 -> 2
例如：
	1 -> 1 -> 2 -> 3 -> 3
	1 -> 2 -> 3
*/
/*
思路：
	若下一个与当前相同， 连接下下一个 就行了
*/

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}  // 构造函数
};


class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {  // duplicates:复制品
		ListNode *curr = head;  // 让curr移动，代码更标准
		while (curr->next) {  // 当next不空的时候
			if (curr->next->val == curr->val) {  // 当前值==下一个值，则连上 下下个
				curr->next = curr->next->next;
			}
			else {
				curr = curr->next;  // 注意，value不等时候，才移动curr到下一个
			}
		}
		return head;
	}
};


int main() {
	ListNode a(1), b(1), c(1), d(2), e(2), f(3);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;

	Solution solve;
	ListNode *head = solve.deleteDuplicates(&a);

	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");

	system("pause");
	return 0;
}