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
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
[1,1,2],
[1,2,1],
[2,1,1]
]
*/

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ans;
		std::sort(nums.begin(), nums.end());
		permuteImp(ans, 0, nums);
		return std::move(ans);
	}
private:
	void permuteImp(vector<vector<int>>& ans, int beg, vector<int>& nums) {
		if (beg == nums.size() - 1) {
			ans.push_back(nums);
			return;
		}
		for (int i = beg; i < nums.size(); i++)
		{
			std::swap(nums[i], nums[beg]);
			permuteImp(ans, beg + 1, nums);
			while (i + 1 < nums.size() && nums[i+1] == nums[beg])i++;
		}
		for (int i = beg + 1; i < nums.size(); i++) {
			std::swap(nums[i], nums[i - 1]);
		}
	}
};
int main()
{
	Solution s;
	vector<int> i({1,1,2,2});
	s.permuteUnique(i);
		return 0;
}