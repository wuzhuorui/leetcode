#include<vector>
using std::vector;
#include<algorithm>
#include<memory>
using std::shared_ptr;
#include<string>
using std::string;
#include<stack>
using std::stack;
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
Seen this question in a real interview before?

*/

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		if (n == 0)return ans;
		make(ans, n, n, "");
		return ans;
	}
	void make(vector<string>& ans, int left, int right, string s)
	{
		if (left == 0 && right == 0)
		{
			ans.push_back(s);
			return;
		}
		if (left >= right)
			make(ans, left - 1, right, s + "(");
		else
		{
			if (left > 0)
				make(ans, left - 1, right, s + "(");
			make(ans,left, right - 1, s + ")");
		}
	}
};
int main()
{
	Solution s;
	vector<string> ans = s.generateParenthesis(3);
	return 0;
}