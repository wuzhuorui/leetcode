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

class Solution {
public:
	int climbStairs(int n) {
		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		dp[0] = 1;
		for (int i = 2; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}
};
int main() {
	Solution s;
	for (int i = 1; i < 100; i++)
	{
		std::cout << s.mySqrt(2147395599)<<" "<< i <<std::endl;
	}
	return 0;
}