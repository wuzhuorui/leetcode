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
	 int uniquePaths(int m, int n) {
		 vector<int> dp(n,0);
		 dp[0] = 1;
		 for (int i = 0; i < m; i++) {
			 for (int j = 1; j < n; j++)
				 dp[j] = dp[j] + dp[j - 1];
		 }
		 return dp[n - 1];
	 };
	 int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		 int m = obstacleGrid.size();
		 int n = obstacleGrid[0].size();
		 vector<int> dp(n, 0);
		 dp[0] = 1;
		 for (int i = 0; i < m; i++) {
			 if (obstacleGrid[i][0] == 1)
				 dp[0] = 0;
			 for (int j = 1; j < n; j++)
			 {
				 dp[j] = dp[j] + dp[j - 1];
				 if (obstacleGrid[i][j] == 1)
					 dp[j] = 0;
			 }
		 }
		 return dp[n - 1];
	 }
 };
int main() {
	Solution s;
	s.generateMatrix(4);

}