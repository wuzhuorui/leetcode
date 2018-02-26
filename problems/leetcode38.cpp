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
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"

*/
class Solution {
public:
	string countAndSay(int n) {
		if (n == 0)return "";
		string s = "1";
		while (--n) {
			string nn = "";
			for (int i = 0; i < s.size(); i++)
			{
				int count = 1;
				while (i + 1 < s.size() && s[i] == s[i + 1])i++, count++;
				nn.push_back('0' + count);
				nn.push_back(s[i]);
			}
			s.swap(nn);
		}
		return s;
	}
};
int main()
{
	Solution s;
	vector<vector<char>> i;
	i.resize(9);
	for (auto& elems : i)
	{
		elems.resize(9);
		for (auto& ee : elems)
			ee = '.';
	}
	std::cout<<s.countAndSay(4);
	//std::cout<<s.searchInsert(i, 0);
	return 0;
}