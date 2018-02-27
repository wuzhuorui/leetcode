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
/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
]

*/
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++)
		{
			int v = nums[i];
			if (v == i + 1) {
				continue;
			}
			else {
				int newpos = v - 1;
				if (newpos > 0 && newpos < nums.size() && (newpos+1 !=nums[newpos]))
				{
					std::swap(nums[i], nums[newpos]);
					i--;
				}
			}
		}
		if(nums.size() == 0)return 1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != i + 1) {
				return i + 1;
			}
		}
		return nums.size();
	}
};
int main()
{
	Solution s;
	vector<int> i({ 3,4,-1,1 });
	s.firstMissingPositive(i);
	return 0;
}