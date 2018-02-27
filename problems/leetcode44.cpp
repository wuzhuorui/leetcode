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
/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false
*/

class Solution {
public:
	bool isMatch(string s, string p) {
		dp.resize(s.size()+1);
		for (auto& elems : dp)elems.resize(p.size()+1,-1);
		return isMatchImp(s, p, 0, 0);
	}
private:
	vector<vector<int>> dp;
	bool isMatchImp(const string& s, const string&p, int si, int pi)
	{
		if (dp[si][pi] != -1)return dp[si][pi] == 1;
		if (si == s.size() && pi == p.size()) { 
			dp[si][pi] = 1;
			return true; 
		};
		if ((si != s.size()) && (pi == p.size())) {
			dp[si][pi] = 0;
			return false; }
		if ((si == s.size()) && (pi != p.size())) {
			while (pi < p.size() && p[pi] == '*')pi++;
			if (pi == p.size()) { 
				dp[si][pi] = 1;
				return true; }
			else { 
				dp[si][pi] = 0;
				return false;
			}
		}

		if (s[si] == p[pi] || p[pi]=='?') {
			bool res =  isMatchImp(s, p, si + 1, pi + 1);
			dp[si][pi] = res ? 1 : 0;
			return dp[si][pi];
		}
		else if (p[pi]=='*'){
			while (pi + 1 < p.size() && p[pi + 1] == '*')pi++;
			for (int nsi = si; nsi <= s.size(); nsi++)
			{
				bool res = isMatchImp(s, p, nsi, pi + 1);
				if (res) { 
					dp[si][pi] = 1;
					return res; }
			}
			dp[si][pi] = 0;
			return false;
		}
		else {
			dp[si][pi] = 0;
			return false;
		}
	}
};
int main()
{
	Solution s;
	vector<int> i({ 0,2,0 });
	std::cout<<s.isMatch("a","a*");
		return 0;
}