#include<iostream>
#include<vector>
using std::vector;
#include<algorithm>
#include<string>
using std::string;
#include<set>
using std::set;
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.
*/
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)return vector<vector<int>>();
		std::sort(nums.begin(), nums.end());//先排序

		vector<vector<int>> ans;
		for (int first = 0; first < nums.size() - 2; first++)
		{
			if (nums[first] > 0) break;
			for (int second = first + 1; second < nums.size() - 1; second++)
			{
				if (nums[first] + nums[second] > 0)break;
				bool find = std::binary_search(nums.begin() + second + 1, nums.end(),-(nums[first] + nums[second]));
				if (find)
				{
					ans.push_back({ nums[first],nums[second],-(nums[first] + nums[second]) });
				}
				while (second + 1 < nums.size() - 1 && nums[second] == nums[second + 1])
					second++; //跳过重复的数
			}
			while (first + 1 < nums.size() - 2 && nums[first] == nums[first + 1])
				first++; //跳过重复的数
		}
		return ans;
	}
};

int main()
{
	Solution s;
	vector<int> in({ 3,0,-2,-1,1,2 });
	s.threeSum(in);
	system("pause");
	return 0;
}