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
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/
#include<map>
using std::map;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int l = 0;
		int r = nums.size() - 1;
		int aimpos = -1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (nums[mid] < target) {
				l = mid + 1;
			}
			else if (nums[mid] > target)
			{
				r = mid - 1;
			}
			else
			{
				aimpos = mid;
				break;
			}
		}
		if (aimpos != -1)
		{
			int ansl = aimpos, ansr = aimpos;
			while (ansl > 0 && nums[ansl - 1] == nums[ansl])ansl--;
			while (ansr + 1 < nums.size() && nums[ansr] == nums[ansr + 1])ansr++;
			return vector<int>({ ansl,ansr });
		}
		return vector<int>({ -1,-1});
	}
};
int main()
{
	Solution s;
	vector<int> i({ 5,7,7,8,8,10});
	s.searchRange(i,8);
	return 0;
}