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

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		std::sort(intervals.begin(), intervals.end(), [](const Interval&l, const Interval& r) {
			return l.start < r.start; });
		vector<Interval> ans;
		for (auto& elems : intervals) {
			if (ans.empty()) {
				ans.push_back(elems);
			}
			else {
				Interval& interval = ans.back();
				if (elems.start <= interval.end) {
					interval.end = elems.end > interval.end?elems.end:interval.end;
				}
				else {
					ans.push_back(elems);
				}
			}
		}
		return ans;
	}
};
int main()
{
	Solution s;
	vector<int> i({ 2,3 });
	vector<vector<int>> ii;
	ii.push_back(i);
	s.spiralOrder(ii);
	return 0;
}