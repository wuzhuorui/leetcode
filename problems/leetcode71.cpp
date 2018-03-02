#include<vector>
using std::vector;
#include<unordered_map>
using std::unordered_map;
unordered_map<int, int> hash;
#include<string>
using std::string;
#include<stack>
using std::stack;
class Solution {
public:
	string simplifyPath(string path) {
		int first = 0;
		int last = 1;
		stack<string> st;
		while (last < path.size()) {
			if (path[last] == '/') {
				last++;
				first++;
				continue;
			}
			while (path[last] != '/' && last < path.size())
			{
				last++;
			}
			string filename = path.substr(first + 1, last - first-1);
			if (filename == "..") {
				if (!st.empty())
				st.pop();
			}
			else if (filename != ".") {
				st.push(filename);
			}
			first = last;
			last = first + 1;
		}
		string ans;
		while (!st.empty()) {
			ans =std::move(st.top())+"/" + ans;
			st.pop();
		}
		ans = "/" + ans;
		if (ans.back() == '/' && ans.size()>1)ans.pop_back();
		return ans;
	}
};
int main()
{
	Solution a;
	vector<int> v({ 1,2,3,4,5,6 });
	a.simplifyPath("/..");
	return 0;
}