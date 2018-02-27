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
	string multiply(string num1, string num2) {
		string s(num1.size() + num2.size() + 1, '0');
		for (int p1 = num1.size() - 1; p1 >= 0; p1--)
		{
			int carry = 0;
			for (int p2 = num2.size() - 1; p2 >= 0; p2--)
			{
				int add = (num1[p1] - '0')*(num2[p2] - '0') + carry+(s[p1+p2+2]-'0');
				carry = add / 10;
				add = add % 10;
				s[p1 + p2+2] = add + '0';
			}
			s[p1+1] = carry + '0';
		}
		string::size_type pos = s.find_first_not_of('0');
		if (pos == string::npos)return "0";
		return s.substr(pos, s.size() - pos);
	}
};
int main()
{
	Solution s;
	vector<int> i({ 0,2,0 });
	std::cout<<s.multiply("123","13");
		return 0;
}