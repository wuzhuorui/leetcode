#include<vector>
using std::vector;
#include<iostream>
#include<algorithm>
#include<memory>
using std::shared_ptr;
#include<string>
using std::string;
#include<stack>
using std::stack;
#include<queue>
using std::priority_queue;
#include<unordered_map>
using std::unordered_map;
#include<list>
using std::list;
/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.


*/
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int l = 0, r = 1;
		while (l < r) {
			int maxpos = r - 1;
			for (int i = l; i < r; i++) {
				if (nums[i] + i > maxpos) {
					maxpos = nums[i] + i;
				}
			}
			l = r;
			r = maxpos + 1;
			if (l > nums.size() - 1)r = l - 1;
			r = r > nums.size() ? nums.size() : r;
		}
		return l-1 >= nums.size() - 1;
	}
};
int main()
{
	Solution s;
	vector<int> i({ 2,3 });
	vector<vector<int>> ii;
	ii.push_back(i);
	s.spiralOrder(ii);
	return 0;
}