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
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.


*/
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)return vector<int>();
		DIRICTION n = DIRICTION::right;
		vector<vector<bool>> travel(matrix.size());
		for(auto& elems : travel)
		{
			elems.resize(matrix[0].size(), false);
		}
		int x = 0, y = 0;
		int size =matrix.size()*matrix[0].size();
		vector<int> ans;
 		while (size--) {
			ans.push_back(matrix[x][y]);
			travel[x][y] = true;
			switch (n)
			{
			case Solution::right:
				y++;
				if (y == matrix[x].size()|| travel[x][y])  {
					n = nextdir(n);
					x++; y--;
				}break;
			case Solution::down:
				x++;
				if (x == matrix.size()|| travel[x][y] ) {
					n = nextdir(n);
					x--;
					y--;
				}
				break;
			case Solution::left:
				y--;
				if (y < 0|| travel[x][y] ) {
					n = nextdir(n);
					x--;
					y++;
				}
				break;
			case Solution::up:
				x--;
				if (x < 0|| travel[x][y]) {
					n = nextdir(n);
					x++;
					y++;
				}
				break;
			default:
				break;
			}
		}
		return ans;
	}
private:
	enum  DIRICTION
	{
		right = 0,
		down = 1,
		left =2,
		up = 3,
	};
	DIRICTION nextdir(DIRICTION n) {
		return DIRICTION((n + 1) % 4);
	}
};
int main()
{
	Solution s;
	vector<int> i({ 2,3 });
	vector<vector<int>> ii;
	ii.push_back(i);
	s.spiralOrder(ii);
	return 0;
}