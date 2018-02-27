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
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
["ate", "eat","tea"],
["nat","tan"],
["bat"]
]
Note: All inputs will be in lower-case.
*/
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		std::unordered_map<string, vector<string>> ump;
		for (auto& elems : strs) {
			string s = elems;
			std::sort(s.begin(), s.end());
			ump[s].push_back(elems);
		}
		vector<vector<string>> ans;
		for (auto& elems : ump) {
			ans.push_back(elems.second);
		}
		return ans;
	}
};
int main()
{
	Solution s;
	vector<int> i({1,1,2,2});
		return 0;
}