#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int disEqual(vector<pair<int, int>> &points) {  // 传入n个点, 每个点的坐标x,y
		int res = 0;
		for (int i = 0; i < points.size(); i++) {  // 取每个点i作为枢纽，
			unordered_map<int, int> record_map;  // key是距离， value是计数。 这时候开辟，会自动释放
			for (int j = 0; j < points.size(); j++)  // 算距离，不开根号，保存在hash map中
				if (i != j)  // 不能和自己求距离
					record_map[get_dis(points[i], points[j])]++;

			unordered_map<int, int> ::iterator iter;
			for (iter = record_map.begin(); iter != record_map.end(); iter++)
				if (iter->second >= 2)  // 这行不写也一样，1-1=0
					res += (iter->second) * (iter->second - 1);  // 3*2=6种组合，2*1=2种组合
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

	Solution solve;  // 实例化
	printf("res = %d\n", solve.disEqual(points));

	system("pause");
	return 0;
}