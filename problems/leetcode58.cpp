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
	int lengthOfLastWord(string s) {
		std::reverse(s.begin(), s.end());
		auto beg = s.begin();
		while (*beg == ' ')beg++;
		auto first = beg;
		while (beg != s.end() && *beg != ' ')beg++;
		return beg - first;
	}
};
int main()
{
	Solution s;
	s.lengthOfLastWord("Today is a nice day");
	return 0;
}