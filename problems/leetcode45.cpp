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
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/

class Solution {
public:
	int jump(vector<int>& nums) {
		int beg = 0, end = 0;
		int times = 0;
		while (end < nums.size()-1) {
			int maxr = end;
			for (int i = beg; i <= end; i++)
			{
				int r = i + nums[i];
				maxr = std::max(maxr, r);
			}
			beg = end + 1;
			end = maxr;
			times++;
		}
		return times;
	}
};
int main()
{
	Solution s;
	vector<int> i({ 0,2,0 });
	std::cout<<s.isMatch("a","a*");
		return 0;
}