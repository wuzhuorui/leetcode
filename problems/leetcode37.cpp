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
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/
#include<map>
	using std::map;
	class Solution {
	public:
		void solveSudoku(vector<vector<char>>& board) {
			this->init(board);
			dfs(board, 0, 0);
			return;
		}
		bool dfs(vector<vector<char>>& board, int r, int c)
		{
			if (board[r][c] != '.') {
				auto p = this->next(r, c);
				r = p.first;
				c = p.second;
				if (r == 9) {
					return true;
				}
				return dfs(board, r, c);
			}
			for (int i = 0; i < 9; i++)
			{
				int k = r / 3 * 3 + c / 3;
				if (!use1[r][i] && !use2[c][i] && !use3[k][i]) {
					use1[r][i] = use2[c][i] = use3[k][i] = true;
					auto nrc = next(r, c);
					board[r][c] = '0' + i + 1;
					if (nrc.first == 9)return true;
					if (dfs(board, nrc.first, nrc.second)) {
						return true;
					}
					board[r][c] = '.';
					use1[r][i] = use2[c][i] = use3[k][i] = false;
				}
			}
			return false;
		}
		std::pair<int, int> next(int r, int c) {
			c++;
			if (c >= 9) { r++; c = 0; }
			return std::make_pair(r, c);
		}
		void init(vector<vector<char>>& board) {
			for (int i = 0; i < 9; i++)
				for (int j = 0; j < 9; j++)
					use1[i][j] = use2[i][j] = use3[i][j] = false;
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++) {
					if (board[i][j] != '.') {
						int num = board[i][j] - '0' - 1;
						int k = i / 3 * 3 + j / 3;
						use1[i][num] = use2[j][num] = use3[k][num] = true;
					}
				}
			}
		}
		bool use1[9][9] = { false };
		bool use2[9][9] = { false };
		bool use3[9][9] = { false };
	};
int main()
{
	Solution s;
	vector<vector<char>> i;
	i.resize(9);
	for (auto& elems : i)
	{
		elems.resize(9);
		for (auto& ee : elems)
			ee = '.';
	}
	i[0][2] = '9';
	i[0][3] = '7';
	i[0][4] = '4';
	i[0][5] = '8';

	i[1][0] = '7';

	i[2][1] = '2';
	i[2][3] = '1';
	i[2][5] = '9';

	i[3][2] = '7';
	i[3][6] = '2';
	i[3][7] = '4';

	i[4][1] = '6';
	i[4][2] = '4';
	i[4][4] = '1';
	i[4][6] = '5';
	i[4][7] = '9';

	i[5][1] = '9';
	i[5][2] = '8';
	i[5][6] = '3';

	i[6][3] = '8';
	i[6][5] = '3';
	i[6][7] = '2';

	i[7][8] = '6';


	i[8][3] = '2';
	i[8][4] = '7';
	i[8][5] = '5';
	i[8][6] = '9';
	s.solveSudoku(i);
	//std::cout<<s.searchInsert(i, 0);
	return 0;
}