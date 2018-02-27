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
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() <= 0)return 0;
		vector<int> left(height.size());
		vector<int> right(height.size());
		left[0] = height[0];
		right[height.size() - 1] = height[height.size()-1];
		for (int i = 1; i < height.size(); i++)
		{
			left[i] = std::max(left[i - 1], height[i]);
		}
		for (int i = height.size() - 2; i >= 0; i--)
		{
			right[i] = std::max(right[i + 1], height[i]);
		}
		int ans = 0;
		for (int i = 1; i < height.size() - 1; i++)
		{
			int maxheight = std::min(left[i - 1], right[i + 1]);
			int rainheight = maxheight - height[i];
			rainheight = rainheight < 0 ? 0 : rainheight;
			ans += rainheight;
		}
		return ans;
	}
};
int main()
{
	Solution s;
	vector<int> i({ 0,2,0 });
	s.trap(i);
	return 0;
}