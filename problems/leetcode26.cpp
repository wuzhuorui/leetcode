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
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 0)return 0;
		int place_pos = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] != nums[i - 1]) {
				nums[place_pos++] = nums[i];
			}
		}
		return place_pos;
	}
};
int main()
{
	Solution s;

	return 0;
}