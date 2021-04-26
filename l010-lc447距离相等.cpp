#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int disEqual(vector<pair<int, int>> &points) {  // ����n����, ÿ���������x,y
		int res = 0;
		for (int i = 0; i < points.size(); i++) {  // ȡÿ����i��Ϊ��Ŧ��
			unordered_map<int, int> record_map;  // key�Ǿ��룬 value�Ǽ����� ��ʱ�򿪱٣����Զ��ͷ�
			for (int j = 0; j < points.size(); j++)  // ����룬�������ţ�������hash map��
				if (i != j)  // ���ܺ��Լ������
					record_map[get_dis(points[i], points[j])]++;

			unordered_map<int, int> ::iterator iter;
			for (iter = record_map.begin(); iter != record_map.end(); iter++)
				if (iter->second >= 2)  // ���в�дҲһ����1-1=0
					res += (iter->second) * (iter->second - 1);  // 3*2=6����ϣ�2*1=2�����
		}
		return res;
	}
private:
	int get_dis(pair<int, int> p1, pair<int, int> p2) {
		return (p2.first - p1.first)*(p2.first - p1.first) 
			+ (p2.second - p1.second)*(p2.second - p1.second);
	}
};


int main() {
	vector<pair<int, int>> points;
	points.push_back(make_pair<int, int> (0, 0));
	points.push_back(make_pair<int, int> (1, 0));
	points.push_back(make_pair<int, int> (2, 0));

	Solution solve;  // ʵ����
	printf("res = %d\n", solve.disEqual(points));

	system("pause");
	return 0;
}