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
void setZeroes(vector<vector<int> > &matrix) {
	int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

	for (int i = 0; i < rows; i++) {
		if (matrix[i][0] == 0) col0 = 0;
		for (int j = 1; j < cols; j++)
			if (matrix[i][j] == 0)
				matrix[i][0] = matrix[0][j] = 0;
	}

	for (int i = rows - 1; i >= 0; i--) {
		for (int j = cols - 1; j >= 1; j--)
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		if (col0 == 0) matrix[i][0] = 0;
	}
}
int main()
{
	Solution a;
	vector<int> v({ 1,2,3,4,5,6 });
	a.minDistance("sea","eat");
	return 0;
}