#include<iostream>
#include<vector>  // std::vector ������
#include<unordered_map>  // ��ϣ��
using namespace std;

class Solution {
public:
	int fourSumCount(vector<int> &A, vector<int> &B, 
					vector<int> &C, vector<int> &D) {  // ����
		unordered_map<int, int> CD_map;  // key��cd�ĺͣ�value�Ǽ���
		for (int i = 0; i < C.size(); i++)
			for (int j = 0; j < D.size(); j++)
				CD_map[C[i] + D[j]]++;  // c++�У�����map��key, ֵĬ��0��
		int res = 0;
		for (int i = 0; i < A.size(); i++)
			for (int j = 0; j < B.size(); j++)
				if (CD_map.find(0 - A[i] - B[j]) != CD_map.end())  // �����ҵ�������
					res += CD_map[0 - A[i] - B[j]];  // +0��Ӱ���������Բ��ÿ��� valueΪ0��ô����
		return res;
	}
};

int main() {
	vector<int> A = {-3, -5 }, B = {3, 1}, C = {1,2}, D = {5, 2};
	Solution solve;  // ʵ����
	int res = solve.fourSumCount(A, B, C, D);

	printf("res = %d\n", res);

	system("pause");
	return 0;
}