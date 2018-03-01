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
	string addBinary(string a, string b) {
		if (a == "" && b == "")return "";
		string ans;
		int la = a.size() - 1;
		int lb = b.size() - 1;
		int add = 0;
		while (la >= 0 && lb >= 0) {
			int num = a[la] + b[lb] - '0' - '0' + add;
			add = num / 2;
			num = num % 2;
			ans.push_back('0' + num);
			la--;
			lb--;
		}
		while (la >= 0) {
			int num = a[la] - '0' + add;
			add = num / 2;
			num = num % 2;
			ans.push_back('0' + num);
			la--;
		}
		while (lb >= 0) {
			int num = b[lb] - '0' + add;
			add = num / 2;
			num = num % 2;
			ans.push_back('0' + num);
			lb--;
		}
		if (add == 1)ans.push_back('1');
		if (ans.back() == '0' && ans.size()>1)ans.pop_back();
		std::reverse(ans.begin(), ans.end());
		return ans;
	}
};
int main() {
	Solution s;

}