#include<iostream>
#include<vector>
using std::vector;
#include<algorithm>
#include<string>
using std::string;
#include<set>
using std::set;
#include<numeric>
/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Seen this question in a real interview before?
*/
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3) {
			return std::accumulate(nums.begin(), nums.end(), 0);
		}
		std::sort(nums.begin(), nums.end());
		int dif = INT_MAX;
		int ans = 0;
		for (int cur_pos = 0; cur_pos < nums.size()-2; cur_pos++)
		{
			int first_num = nums[cur_pos];
			int left = cur_pos + 1;
			int right = nums.size() - 1;
			while (left < right)
			{
				int add = first_num + nums[left] + nums[right];
				(add < target) ? left++ : right--;
				if (abs(add - target) < dif)
				{
					dif = abs(add - target);
					ans = add;
				}
			}
		}
		return ans;
	}
};

int main()
{
	Solution s;
	vector<int> in({ 1,1,1,0});
	s.threeSumClosest(in,100);
	system("pause");
	return 0;
}