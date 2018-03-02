#include<vector>
using std::vector;
#include<unordered_map>
using std::unordered_map;
unordered_map<int, int> hash;
#include<string>
using std::string;
#include<stack>
using std::stack;
#include<algorithm>
#include<iostream>
class Solution {
public:
	int minDistance(string word1, string word2) {
		if (word2 == "")return word1.size();
		if (word1 == "")return word2.size();
		vector<int> dp(word1.size()+1, INT_MAX);
		for (int i = 0; i < dp.size(); i++)
			dp[i] = i;
		dp[0] = 0;
		int pre = 0;
		for (int i = 0; i < word2.size(); i++) {
			char c1 = word2[i];
			pre = dp[0];
			dp[0] = i+1;
			for (int j = 0; j < word1.size(); j++) {
				char c2 = word1[j];
				int npre = dp[j + 1];

				dp[j + 1] = std::min(dp[j + 1], pre);
				dp[j + 1] = std::min(dp[j + 1], dp[j]);
				dp[j + 1] += 1;

				if (c2 == c1) {
					dp[j + 1] = std::min(dp[j + 1], pre);
				}

				pre = npre;
			}
		}
		return dp[word1.size()];
	}
};
int main()
{
	Solution a;
	vector<int> v({ 1,2,3,4,5,6 });
	a.minDistance("sea","eat");
	return 0;
}