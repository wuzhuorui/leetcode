#include<vector>
using std::vector;
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

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Seen this question in a real interview before?

*/


class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int pos = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val)
			{
				nums[pos++] = nums[i];
			}
		}
		return pos;
	}
};
int main()
{
	Solution s;

	return 0;
}