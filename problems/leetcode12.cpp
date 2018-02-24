#include<iostream>
#include<vector>
using std::vector;
#include<algorithm>
#include<string>
using std::string;
/*

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Seen this question in a real interview before?
*/
class Solution {
public:
	string intToRoman(int num) {
		const char* c[4][10] = {
			{ "","I","II","III","IV","V","VI","VII","VIII","IX" },
		{ "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" },
		{ "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" },
		{ "","M","MM","MMM" }
		};
		string roman;
		roman.append(c[3][num / 1000 % 10]);
		roman.append(c[2][num / 100 % 10]);
		roman.append(c[1][num / 10 % 10]);
		roman.append(c[0][num % 10]);

		return roman;
	}
};

int main()
{
	Solution s;
	std::cout<<s.intToRoman(3999);
	system("pause");
	return 0;
}