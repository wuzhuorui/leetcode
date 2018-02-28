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
/*
Implement pow(x, n).


Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
*/
class Solution {
public:
	int totalNQueens(int n) {
		nq = n;
		vector<vector<string>> ans;
		vector<string> cur(nq);
		for (auto& elems : cur) {
			elems.resize(nq, '.');
		}
		solveNQueensImp(ans, cur, 0);
		return ans.size();
	}
	void solveNQueensImp(vector<vector<string>>& ans, vector<string>& cur, int row) {
		if (row == nq) {
			ans.push_back(cur);
			return;
		}
		for (int i = 0; i < nq; i++) {
			if (canplace(cur, row, i)) {
				cur[row][i] = 'Q';
				solveNQueensImp(ans, cur, row + 1);
				cur[row][i] = '.';
			}
		}
	}
private:
	bool canplace(vector<string>& queens,int x,int y) {
		for (int i = 0; i < nq; i++) {
			if (queens[i][y] == 'Q')return false;
		}
		for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
			if (queens[i][j] == 'Q')return false;
		}
		for (int i = x - 1, j = y + 1; i >= 0 && j < nq; i--, j++) {
			if (queens[i][j] == 'Q')return false;
		}
		return true;
	}
	int nq;
};
int main()
{
	Solution s;
	vector<int> i({1,1,2,2});
	return 0;
}