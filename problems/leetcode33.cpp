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
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.


*/
#include<map>
using std::map;
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)return -1;
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int mid = (l + r) / 2;
			if (nums[mid] > nums[r]) l = mid+1;
			else
				r = mid;
		}
		//[0,l),
		if (target <= nums.back())
		{
			r = nums.size() - 1;
		}
		else
		{
			l = 0;
			r = r - 1;
		}

		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (nums[mid] == target)return mid;
			else if (nums[mid] > target)r = mid - 1;
			else l = mid + 1;
		}
		return -1;
	}
};
int main()
{
	Solution s;
	vector<int> i({5,1,3});
	std::cout<<s.search(i,5);
	return 0;
}