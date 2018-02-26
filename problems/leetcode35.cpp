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
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

*/
#include<map>
using std::map;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.size() == 0)return 0;
		int l = 0;
		int r = nums.size() - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (nums[mid] < target)l = mid + 1;
			else if (nums[mid] > target)r = mid - 1;
			else
				return mid;
		}
		return l;
	}
};
int main()
{
	Solution s;
	vector<int> i({ 1,3,5,6 });
	std::cout<<s.searchInsert(i, 0);
	return 0;
}