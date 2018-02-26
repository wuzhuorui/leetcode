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
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/
#include<map>
using std::map;
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int iuse1[9][9] = { 0 }, iuse2[9][9] = { 0 }, iuse3[9][9] = { 0 };
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					int num = board[i][j] - '0' - 1;
					int k = i / 3 * 3 + j / 3;
					if (iuse1[i][num] || iuse2[j][num] || iuse3[k][num])return false;
					iuse1[i][num] = iuse2[j][num] = iuse3[k][num] = 1;
				}
			}
		}
		return true;
	}
};
int main()
{
	Solution s;
	vector<int> i({ 1,3,5,6 });
	//std::cout<<s.searchInsert(i, 0);
	return 0;
}