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
	int mySqrt(int x) {
		if (x == 0)return 0;
		int64_t l = 1, r = x;
		int64_t mid = (l + r) / 2;
		while (l+1 < r) {
			int64_t product = mid * mid;
			if (product > x) {
				r = mid;
			}
			else {
				l = mid;
			}
			mid =(((int64_t)l + (int64_t)r) / 2);
		}
		return l;
	}
};
int main() {
	Solution s;
	for (int i = 1; i < 100; i++)
	{
		std::cout << s.mySqrt(2147395599)<<" "<< i <<std::endl;
	}
	return 0;
}