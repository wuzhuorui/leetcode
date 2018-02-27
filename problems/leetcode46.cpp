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
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]
*/

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		permuteImp(ans, 0, nums);
		return std::move(ans);
	}
private:
	void permuteImp(vector<vector<int>>& ans, int beg, vector<int>& nums) {
		if (beg == nums.size() - 1) {
			ans.push_back(nums);
		}
		for (int i = beg; i < nums.size(); i++)
		{
			std::swap(nums[i], nums[beg]);
			permuteImp(ans, beg + 1, nums);
			std::swap(nums[i], nums[beg]);
		}
	}
};
int main()
{
	Solution s;
	vector<int> i({ 0,2,0 });
		return 0;
}