#include<vector>
using std::vector;
#include<algorithm>
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		if (nums.size() < 4)return std::move(ans);
		std::sort(nums.begin(), nums.end());
		int numssize = nums.size();
		for (int pos1 = 0; pos1 < numssize-3; pos1++)
		{
			for (int pos2 = pos1 + 1; pos2 < numssize-2; pos2++)
			{
				int sum12 = nums[pos1] + nums[pos2];
				auto left = nums.begin()+pos2+1;
				auto right = nums.end()-1;
				while (left < right)
				{
					int sum = sum12 + *left + *right;
					if (sum == target) { ans.push_back({ nums[pos1],nums[pos2],*left++,*right-- });
						while (left < right && *left == *(left - 1))left++;
						while (left < right && *right == *(right + 1))right--;
					}
					else if (sum < target) { 
						left++;
						while (left < right && *left == *(left - 1))left++;
					}
					else { 
						right--; 
						while (left < right && *right == *(right + 1))right--;
					};
				}
				while (pos2 + 1 < numssize - 2 && nums[pos2] == nums[pos2 + 1])pos2++;
			}
			while (pos1 + 1 < numssize - 3 && nums[pos1] == nums[pos1 + 1])pos1++;
		}
		return ans;
	}
};

int main()
{
	Solution s;
	vector<int> a{1,2,3,4};
	s.fourSum(a,0);
	return 0;
}