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
	vector<vector<int>> generateMatrix(int n) {
		if (n == 0)return vector<vector<int>>();
		vector<vector<int>> ans(n);
		for (auto& elems : ans)elems.resize(n);
		DIRICTION dn = DIRICTION::right;
		int x = 0, y = 0;
		int size = n * n;
		int data = 1;
		while (size--) {
			ans[x][y] = data++;
			switch (dn)
			{
			case Solution::right:
				y++;
				if (y == n || ans[x][y] !=0) {
					dn = nextdir(dn);
					x++; y--;
				}break;
			case Solution::down:
				x++;
				if (x == n || ans[x][y] != 0) {
					dn = nextdir(dn);
					x--;
					y--;
				}
				break;
			case Solution::left:
				y--;
				if (y < 0 || ans[x][y] != 0) {
					dn = nextdir(dn);
					x--;
					y++;
				}
				break;
			case Solution::up:
				x--;
				if (x < 0 || ans[x][y] != 0) {
					dn = nextdir(dn);
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
		left = 2,
		up = 3,
	};
	DIRICTION nextdir(DIRICTION n) {
		return DIRICTION((n + 1) % 4);
	}
};

int main() {
	Solution s;
	s.generateMatrix(4);

}