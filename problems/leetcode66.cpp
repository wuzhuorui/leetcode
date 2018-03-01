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
	vector<int> plusOne(vector<int>& digits) {
		for (int i = digits.size() - 1; i >= 0; i--) {
			if (digits[i] == 9) {
				digits[i] = 0;
			}
			else {
				digits[i] += 1;
				return digits;
			}
		}
		vector<int> ans(1, 1);
		ans.insert(ans.end(),digits.begin(), digits.end());
		return ans;
	}
};
int main() {
	Solution s;

}