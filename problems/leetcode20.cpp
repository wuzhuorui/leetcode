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

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Seen this question in a real interview before?

*/

class Solution {
public:
	bool isValid(string s) {
		stack<char> m_stack;
		for (auto& schar : s)
		{
			if (m_stack.empty())
			{
				if (isright(schar))return false;
				m_stack.push(schar);
			}
			else {
				if (isright(schar)) {
					if (!match(m_stack.top(), schar)) {
						return false;
					}
					else {
						m_stack.pop();
					}
				}
				else
				{
					m_stack.push(schar);
				}
			}
		}
		return m_stack.empty();
	}
	bool isleft(char c)
	{
		return c == '[' || c == '(' || c == '{';
	}
	bool isright(char c)
	{
		return !isleft(c);
	}
	bool match(char l, char r)
	{
		return (l == '[' & r == ']') || (l == '(' & r == ')' || (l == '{' & r == '}'));
	}
};

int main()
{
	Solution s;
	return 0;
}