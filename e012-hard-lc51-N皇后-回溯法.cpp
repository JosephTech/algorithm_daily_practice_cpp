/*
N皇后是计算机科学中 最为经典 的问题之一， 
该问题追溯到1848年，由国际西洋棋棋手马克斯·贝瑟尔提出8皇后问题

将N个皇后摆放在 N * N 的棋牌中，互相不可攻击，有多少种摆放方式，
每种摆放方式具体是怎样的？

（皇后可以攻击横的、竖的、斜的 三个方向）
*/
/*
传出n皇后的所有结果，每个结果是一个棋盘，每个棋盘均使用字符串向量表示。

std::vector<std::vector<std::string>> solveNueens (int n) {}

外层的vector装一个个棋盘
内层的veccto装一行行string,即棋盘的每行
*/
/*
思考：
	如何设计放置皇后，更新棋盘的过程
*/
/*
设置方向数组：
(x-1, y-1)	(x-1, y)  (x-1, y+1)
(x,y-1)		(x,y)	  (x, y+1)
(x+1, y-1)	(x+1,y)	  (x+1,y+1)

【注意：这个坐标系不一样↓x   →y】

方向数组：
						上、下、左、右、左上、右上、左下、右下
static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1}
static const int dy[] = {0,  0, -1, 1, -1, 1, -1, 1}

在这8个方向，分别延伸N-1个距离（因为，最多再走N-1步，就超出棋盘了），只要不超出边界
(即，每个方向从1延伸到N-1)
mark[][] = 1
*/
/*
N皇后问题，对于N * N的棋盘，每行都要放置，且只能放置1个皇后。
利用递归对棋盘的每一行放置皇后，放置时，按列顺序寻找可以放置皇后的列，
若可以放置皇后，将皇后放置该位置，并更新mark标记数组，递归进行下一行的皇后放置；
当该次递归结束后，恢复mark数组，并尝试下一个可能放皇后的列。
当递归可以完成N行的N个皇后放置，则将该结果保存并返回
*/

#include <vector>
#include <iostream>
#include <string>

class Solution {
public:
	std::vector<std::vector<std::string>> solveNQueen(int n) { //传入了n个皇后
		std::vector<std::string> location; // 皇后Q在这个 矩阵中，矩阵其他元素是*
		std::vector<std::vector<std::string>> result; // 存放结果，里边好几个矩阵，代表不同的解法（放皇后的方法）
		std::vector<std::vector<int>> mark; //矩阵mark，攻击范围填上0，其他位置填1
		for (int i = 0; i < n; i++) {
			mark.push_back((std::vector<int> ())); //匿名？ push_back进去
			for (int j = 0; j < n; j++) {
				mark[i].push_back(0); //mark矩阵填 0
			}
			location.push_back(""); // 构造location矩阵
			location[i].append(n,'*'); // n个*构成的字符串。注意：append要用单引号''
		}
		generate(0, n, mark, location, result);
		return result;
	}

private: //写类内调用的函数
	void put_down_the_queen(int x, 
							int y, 
							std::vector<std::vector<int>> &mark) { //放一个皇后，把mark攻击范围置1
		static const int dx[] = {-1,1, 0,0,-1,-1, 1, 1}; //方向数组。 上、下、左、右、左上、右上、左下、右下
		static const int dy[] = {0, 0,-1,1,-1, 1,-1, 1}; // 一般const都用static修饰，这样不管 put_down_the_queen调用几次，都只有一个dx和一个dy
		mark[x][y] = 1; //[x][y]位置为皇后，标记为1
		for (int i = 1; i < mark.size(); i++) { //j代表8个方向，i代表每个方向延伸1~mark.size()-1次。 如4皇后延伸3次
			for (int j = 0; j < 8; j++) { //8个方向是常量
				int new_x = x + i * dx[j];
				int new_y = y + i * dy[j];
				if (new_x >= 0 && new_x < mark.size()
					&& new_y >= 0 && new_y < mark.size()) 
				{
					mark[new_x][new_y] = 1; //若仍在棋盘内，攻击范围标记为1
				}
			}
		}
	}
	void generate(	int k, //第几次放Queen,即第几行，i=0到n （不包括n）
					int n, //n个皇后
					std::vector<std::vector<int>> &mark,
					std::vector<std::string> &location,
					std::vector<std::vector<std::string>> &result ) {
		if (k == n) { //结束条件
			result.push_back(location); //添加到结果中
			return;
		}
		//若不是攻击范围则添加
		for (int i = 0; i < n; i++) { //i代表第几列，回溯也是回溯第几列
			if (mark[k][i] == 0) { // 不被攻击的位置，可以放置皇后
				std::vector<std::vector<int>> tmp_mark = mark; //记录回溯镜像
				location[k][i] = 'Q';
				put_down_the_queen(k, i,mark);
				generate(k+1, n, mark, location, result); //注意，下一行要k+1
				//上边的路没走通，回溯，进行下一列
				mark = tmp_mark;
				location[k][i] = '*';
			}
		}
	}
};


int main() {
	//实例化、调用函数
	Solution solve;
	int n = 4;
	std::vector<std::vector<std::string>> result = solve.solveNQueen(n);

	//打印
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("%s\n",result[i][j].c_str());
		}
		printf("\n");
	}

	system("pause");
	return 0;
}