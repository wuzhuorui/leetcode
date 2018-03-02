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
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int l = 0;
		int r = nums.size() - 1;
		for (int i = l; i <= r; i++) {
			if (nums[i] > 1) {
				std::swap(nums[i--], nums[r--]);
			}
			else if (nums[i] < 1){
				std::swap(nums[i], nums[l++]);
			}
		}
	}
};
int main()
{
	Solution a;
	vector<int> v({ 1,2,3,4,5,6 });
	a.minDistance("sea","eat");
	return 0;
}