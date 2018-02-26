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

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

Seen this question in a real interview before?
*/
#include<map>
using std::map;
class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> st;
		int ans = 0;
		for (int spos = 0; spos < s.size(); spos++) {
			char c = s[spos];
			if (c == '(')
				st.push(spos);
			else {
				if (st.empty())
					st.push(spos);
				else
				{
					char topc = s[st.top()];
					if (topc == '(') {
						if (spos - st.top() + 1 > ans) {
							ans = spos - st.top() + 1;
						}
						st.pop();
					}
					else {
						st.push(spos);
					}
				}
			}
		}
		if (st.empty())return s.size();
		int a = s.size(), b = -1;
		int longth = 0;
		while (!st.empty())
		{
			int b = st.top();
			st.pop();
			longth = std::max(longth, a - b - 1);
			a = b;
		}
		longth = std::max(longth, a-(-1) - 1);
		return longth;
	}
};
int main()
{
	Solution s;
	vector<int> i({ 1,3,2 });
	s.longestValidParentheses("())()())");
	return 0;
}