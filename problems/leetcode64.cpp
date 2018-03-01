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

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 class Solution {
 public:
	 int minPathSum(vector<vector<int>>& grid) {
		 int m = grid.size();
		 int n = grid[0].size();
		 vector<int> dp(n, INT_MAX);
		 dp[0] = 0;
		 for (int i = 0; i < m; i++)
		 {
			 dp[0] = dp[0] + grid[i][0];
			 for (int j = 1; j < n; j++) {
				 dp[j] =  std::min(dp[j],dp[j-1]) +grid[i][j];
			 }
		 }
		 return dp[n - 1];
	 }
 };
int main() {
	Solution s;
	s.generateMatrix(4);

}