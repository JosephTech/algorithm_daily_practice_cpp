/*
N�ʺ��Ǽ������ѧ�� ��Ϊ���� ������֮һ�� 
������׷�ݵ�1848�꣬�ɹ����������������˹����ɪ�����8�ʺ�����

��N���ʺ�ڷ��� N * N �������У����಻�ɹ������ж����ְڷŷ�ʽ��
ÿ�ְڷŷ�ʽ�����������ģ�

���ʺ���Թ�����ġ����ġ�б�� ��������
*/
/*
����n�ʺ�����н����ÿ�������һ�����̣�ÿ�����̾�ʹ���ַ���������ʾ��

std::vector<std::vector<std::string>> solveNueens (int n) {}

����vectorװһ��������
�ڲ��vecctoװһ����string,�����̵�ÿ��
*/
/*
˼����
	�����Ʒ��ûʺ󣬸������̵Ĺ���
*/
/*
���÷������飺
(x-1, y-1)	(x-1, y)  (x-1, y+1)
(x,y-1)		(x,y)	  (x, y+1)
(x+1, y-1)	(x+1,y)	  (x+1,y+1)

��ע�⣺�������ϵ��һ����x   ��y��

�������飺
						�ϡ��¡����ҡ����ϡ����ϡ����¡�����
static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1}
static const int dy[] = {0,  0, -1, 1, -1, 1, -1, 1}

����8�����򣬷ֱ�����N-1�����루��Ϊ���������N-1�����ͳ��������ˣ���ֻҪ�������߽�
(����ÿ�������1���쵽N-1)
mark[][] = 1
*/
/*
N�ʺ����⣬����N * N�����̣�ÿ�ж�Ҫ���ã���ֻ�ܷ���1���ʺ�
���õݹ�����̵�ÿһ�з��ûʺ󣬷���ʱ������˳��Ѱ�ҿ��Է��ûʺ���У�
�����Է��ûʺ󣬽��ʺ���ø�λ�ã�������mark������飬�ݹ������һ�еĻʺ���ã�
���ôεݹ�����󣬻ָ�mark���飬��������һ�����ܷŻʺ���С�
���ݹ�������N�е�N���ʺ���ã��򽫸ý�����沢����
*/

#include <vector>
#include <iostream>
#include <string>

class Solution {
public:
	std::vector<std::vector<std::string>> solveNQueen(int n) { //������n���ʺ�
		std::vector<std::string> location; // �ʺ�Q����� �����У���������Ԫ����*
		std::vector<std::vector<std::string>> result; // ��Ž������ߺü������󣬴���ͬ�Ľⷨ���Żʺ�ķ�����
		std::vector<std::vector<int>> mark; //����mark��������Χ����0������λ����1
		for (int i = 0; i < n; i++) {
			mark.push_back((std::vector<int> ())); //������ push_back��ȥ
			for (int j = 0; j < n; j++) {
				mark[i].push_back(0); //mark������ 0
			}
			location.push_back(""); // ����location����
			location[i].append(n,'*'); // n��*���ɵ��ַ�����ע�⣺appendҪ�õ�����''
		}
		generate(0, n, mark, location, result);
		return result;
	}

private: //д���ڵ��õĺ���
	void put_down_the_queen(int x, 
							int y, 
							std::vector<std::vector<int>> &mark) { //��һ���ʺ󣬰�mark������Χ��1
		static const int dx[] = {-1,1, 0,0,-1,-1, 1, 1}; //�������顣 �ϡ��¡����ҡ����ϡ����ϡ����¡�����
		static const int dy[] = {0, 0,-1,1,-1, 1,-1, 1}; // һ��const����static���Σ��������� put_down_the_queen���ü��Σ���ֻ��һ��dx��һ��dy
		mark[x][y] = 1; //[x][y]λ��Ϊ�ʺ󣬱��Ϊ1
		for (int i = 1; i < mark.size(); i++) { //j����8������i����ÿ����������1~mark.size()-1�Ρ� ��4�ʺ�����3��
			for (int j = 0; j < 8; j++) { //8�������ǳ���
				int new_x = x + i * dx[j];
				int new_y = y + i * dy[j];
				if (new_x >= 0 && new_x < mark.size()
					&& new_y >= 0 && new_y < mark.size()) 
				{
					mark[new_x][new_y] = 1; //�����������ڣ�������Χ���Ϊ1
				}
			}
		}
	}
	void generate(	int k, //�ڼ��η�Queen,���ڼ��У�i=0��n ��������n��
					int n, //n���ʺ�
					std::vector<std::vector<int>> &mark,
					std::vector<std::string> &location,
					std::vector<std::vector<std::string>> &result ) {
		if (k == n) { //��������
			result.push_back(location); //��ӵ������
			return;
		}
		//�����ǹ�����Χ�����
		for (int i = 0; i < n; i++) { //i����ڼ��У�����Ҳ�ǻ��ݵڼ���
			if (mark[k][i] == 0) { // ����������λ�ã����Է��ûʺ�
				std::vector<std::vector<int>> tmp_mark = mark; //��¼���ݾ���
				location[k][i] = 'Q';
				put_down_the_queen(k, i,mark);
				generate(k+1, n, mark, location, result); //ע�⣬��һ��Ҫk+1
				//�ϱߵ�·û��ͨ�����ݣ�������һ��
				mark = tmp_mark;
				location[k][i] = '*';
			}
		}
	}
};


int main() {
	//ʵ���������ú���
	Solution solve;
	int n = 4;
	std::vector<std::vector<std::string>> result = solve.solveNQueen(n);

	//��ӡ
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("%s\n",result[i][j].c_str());
		}
		printf("\n");
	}

	system("pause");
	return 0;
}