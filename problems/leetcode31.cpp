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

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1


*/
#include<map>
using std::map;
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i = nums.size() - 1;
		int tail = i;
		while (i > 0 && nums[i - 1] >= nums[i]) { i--; }
		for (int j = i; j < tail; j++, tail--) {
			std::swap(nums[tail], nums[j]);
		}
		if (i != 0) {
			for (int j = i; j < nums.size(); j++) {
				if (nums[j] > nums[i-1])
				{
					std::swap(nums[i-1], nums[j]);
					break;
				}
			}
		}
	}
};
int main()
{
	Solution s;
	vector<int> i({ 1,3,2 });
	s.nextPermutation(i);
	return 0;
}