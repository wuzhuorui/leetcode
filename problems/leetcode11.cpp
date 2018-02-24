#include<iostream>
#include<vector>
using std::vector;
#include<algorithm>
/*

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Seen this question in a real interview before?
*/
class Solution {
public:
	int maxArea(vector<int>& height) {
		auto beg = height.cbegin();
		auto end = --height.cend();
		int ans = 0;
		while (beg < end)
		{
			int contains = (end - beg)*std::min(*beg, *end);
			ans = contains > ans ? contains: ans;
			*beg < *end ? beg++ : end--;
		}
		return ans;
	}
};

int main()
{
	Solution s;
	vector<int>  v = vector<int>{ 1,2,3,4,5 };
	std::cout<<s.maxArea(v);
	system("pause");
	return 0;
}