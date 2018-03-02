#include<vector>
using std::vector;
#include<unordered_map>
using std::unordered_map;
unordered_map<int, int> hash;
#include<string>
using std::string;
#include<stack>
using std::stack;
#include<algorithm>
#include<iostream>
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() <= 0)return false;
		int l = 0;
		int r = matrix.size();
		while (l+1 < r) {
			int mid = (l + r) / 2;
			int midnum = matrix[mid][0];
			if (midnum == target) {
				return true;
			}
			else if (midnum < target) {
				l = mid;
			}
			else {
				r = mid;
			}
		}
		return std::binary_search(matrix[l].begin(), matrix[l].end(), target);
	}
};
int main()
{
	Solution a;
	vector<int> v({ 1,2,3,4,5,6 });
	a.minDistance("sea","eat");
	return 0;
}