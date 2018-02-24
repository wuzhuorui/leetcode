#include<iostream>
#include<vector>
using std::vector;
#include<algorithm>
#include<string>
using std::string;
/*
Write a function to find the longest common prefix string amongst an array of strings.
*/
	class Solution {
	public:
		string longestCommonPrefix(vector<string>& strs) {
			if (strs.size() == 0)return "";
			else if (strs.size() == 1)return strs[0];
			string&& left = std::move(strs[0]);
			for (int i = 1; i < strs.size(); i++)
			{
				left = findcommon(std::move(left),std::move(strs[i]));
			}
			return left;
		}

		string findcommon(string&& left, string&& right)
		{
			int pos = 0;
			while (left[pos] == right[pos] && right[pos]!=0)pos++;
			return left.substr(0, pos);
		}
	};

int main()
{
	Solution s;
	std::cout<<s.longestCommonPrefix();
	system("pause");
	return 0;
}