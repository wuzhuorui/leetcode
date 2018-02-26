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
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
[7],
[2, 2, 3]
]

*/
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		std::sort(candidates.begin(), candidates.end());
		vector<vector<int>> ans;
		vector<int> c;
		dp(candidates, target, c, ans,candidates.begin());
		return ans;
	}
	void dp(vector<int>& candidates, int target,vector<int>& cur, vector<vector<int>>& ans,vector<int>::iterator begp) {
		if (target == 0) {
			ans.push_back(cur);
			return;
		}
		for (auto beg = begp; beg != candidates.end(); beg++) {
			if (*beg <= target) {
				cur.push_back(*beg);
				dp(candidates, target - *beg, cur, ans, begp);
				cur.pop_back();
			}
		}
	}
};
int main()
{
	Solution s;
	vector<vector<char>> i;
	//std::cout<<s.searchInsert(i, 0);
	return 0;
}