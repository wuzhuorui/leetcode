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
	int maxSubArray(vector<int>& nums) {
		for (int i = 1; i < nums.size(); i++) {
			int newsum = nums[i] + nums[i - 1];
			if ((newsum > nums[i - 1] && newsum > nums[i])|| newsum > nums[i]) {
				nums[i] = newsum;
			}
		}
		findmax f = std::for_each(nums.begin(), nums.end(), findmax());
		return f.maxnum;
	}
	class findmax{
	public:
		findmax() :maxnum(INT_MIN) {};
		int maxnum;
		int operator()(int& l) {
			if (l > maxnum) {
				maxnum = l;
			}
			return maxnum;
		}
	};
};
int main()
{
	Solution s;
	vector<int> i({ -2,1,-3,4,-1,2,1,-5,4 });
	s.maxSubArray(i);
	return 0;
}