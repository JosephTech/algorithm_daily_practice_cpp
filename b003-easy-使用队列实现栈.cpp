/*
���һ��ջ��֧�ֻ�����ջ���������ջ�ڲ��洢���ݵĽṹΪ���У����еķ���ֻ��
����push��peek(front)��pop��size��empty�ȱ�׼�Ķ��з���

1��push() ��Ԫ��xѹ��ջ��
2��pop()  �������Ƴ���ջ��Ԫ��
3��top()  ����ջ��Ԫ��
4��empty() �ж�ջ�Ƿ�Ϊ��
*/
#include <stdio.h>
#include <queue>

class MyStack {
public:
	MyStack() { //���캯��
	}
	void push(int x) { 
		std::queue<int> temp_queue; // ��ʱ���С� ���øö��н��� ��������������ǰ�x���ڶ���ͷ��
		temp_queue.push(x); // ���� ��ʱ����ͷ
		while ( !_data.empty()) {  // ����
			temp_queue.push(_data.front()); // �Ͱ�_dataͷ �Ƶ� ��ʱ����
			_data.pop(); // ����_dataͷ
		}
		//����ʱ���У������ŵ� _data��
		while (!temp_queue.empty()) { // ����
			_data.push(temp_queue.front());  // �Ͱ� ��ʱ����ͷ �Ƶ� _data
			temp_queue.pop(); //���� ��ʱ����ͷ
		}
	}

	int pop() {
		int x = _data.front(); // ȡ��ջ��Ԫ�أ���ȡ������ͷ��Ԫ��
		_data.pop(); // ��������ͷ��Ԫ��
		return x; // ���ض���ͷ��Ԫ��x��  ��Ϊջ��Ԫ��
	}
	int top() {
		return _data.front(); // ���ض���ͷ����  ��Ϊ����ջ��Ԫ��
	}
	bool empty() {
		return _data.empty();
	}
private:
	std::queue<int> _data; // _data��ߴ���� ջ�洢Ԫ�ص�˳��
	// ����Ԫ����ӵ�_data_queue��ͷ������
};


int main() {
	MyStack S;
	S.push(1);
	S.push(2);
	S.push(3);
	S.push(4);
	printf("S.top = %d\n", S.top()); // 4
	S.pop();
	printf("S.top = %d\n", S.top()); // 3
	S.push(5);
	printf("S.top = %d\n", S.top()); // 5
	system("pause");
	return 0;
}
