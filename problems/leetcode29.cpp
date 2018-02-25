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

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Seen this question in a real interview before?

*/


class Solution {
public:
		int divide(int dividend, int divisor) {
			if (divisor == 0)return 0x7fffffff;
			long long a = abs((long long)dividend);
			long long b = abs((long long)divisor);

			long long ans = 0;

			long long cur_div = b;
			long long  X = 1;
			while (cur_div <= a)
			{
				a -= cur_div;
				ans += X;
				cur_div = cur_div << 1;
				X = X << 1;
				while (cur_div > a && X != 1)
				{
					X = X >> 1;
					cur_div =cur_div >> 1;
				}
			}
			if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
			{
				if (ans <= 0x7fffffff)
					return static_cast<int>(ans);
				else
					return 0x7fffffff;
			}
			else
			{
				return static_cast<int>(-ans);
			}
		}
};
int main()
{
	Solution s;
	std::cout<<s.divide(0x80000000	,-1);
	return 0;
}