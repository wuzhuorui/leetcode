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
/*
Implement pow(x, n).


Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
*/
class Solution {
public:
	double myPow(double x, int n) {
		int zf = n >= 0 ? 1 : 0;
		if (n == 0)return 1;
		unsigned nn;
		if (n < 0) nn = -n;
		else nn = n;
		double ans = doPowImp(x, nn);
		if (zf == 0) {
			return 1 / ans;
		}
		return ans;
	}
private:
	double doPowImp(double x, unsigned n) {
		if (n == 1)return x;
		double a = doPowImp(x, n / 2);
		return a * a*(n % 2 == 1 ? x : 1.);
	}
};
int main()
{
	Solution s;
	vector<int> i({1,1,2,2});
	s.myPow(0.44894, -5);
	return 0;
}