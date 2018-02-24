#include<iostream>
#include<vector>
using std::vector;
#include<algorithm>
#include<string>
using std::string;
#include<set>
using std::set;
#include<numeric>
/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		static const vector<string> map = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		if (digits.size() <= 0)return result;
		result.push_back("");
		for (auto elems : digits)
		{
			vector<string> tmp;

			const string mapstring = map[elems - '0'];
			if (mapstring == "")continue;
			for (auto charelems : mapstring)
			{
				for (auto result_string : result)
				{
					tmp.push_back(result_string+charelems);
				}
			}
			result.swap(tmp);
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> in({ 1,1,1,0 });
	s.letterCombinations("123");
	system("pause");
	return 0;
}