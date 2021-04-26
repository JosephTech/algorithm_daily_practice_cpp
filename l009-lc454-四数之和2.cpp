#include<iostream>
#include<vector>  // std::vector 存数组
#include<unordered_map>  // 哈希表
using namespace std;

class Solution {
public:
	int fourSumCount(vector<int> &A, vector<int> &B, 
					vector<int> &C, vector<int> &D) {  // 引用
		unordered_map<int, int> CD_map;  // key是cd的和，value是计数
		for (int i = 0; i < C.size(); i++)
			for (int j = 0; j < D.size(); j++)
				CD_map[C[i] + D[j]]++;  // c++中，访问map的key, 值默认0了
		int res = 0;
		for (int i = 0; i < A.size(); i++)
			for (int j = 0; j < B.size(); j++)
				if (CD_map.find(0 - A[i] - B[j]) != CD_map.end())  // 若查找到，计数
					res += CD_map[0 - A[i] - B[j]];  // +0不影响结果，所以不用考虑 value为0怎么处理
		return res;
	}
};

int main() {
	vector<int> A = {-3, -5 }, B = {3, 1}, C = {1,2}, D = {5, 2};
	Solution solve;  // 实例化
	int res = solve.fourSumCount(A, B, C, D);

	printf("res = %d\n", res);

	system("pause");
	return 0;
}