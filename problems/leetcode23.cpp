#include<vector>
using std::vector;
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


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class cmp
{
public:
	bool operator ()(const ListNode* l, const ListNode* r)const
	{
		return (l)->val > (r)->val;
	}
};
class Solution {
public:
	ListNode * mergeKLists(vector<ListNode*>& lists) {

		priority_queue<ListNode*, vector<ListNode*>,cmp> p;
		ListNode* ans = new ListNode(0);
		ListNode* head = ans;
		for (auto elems : lists)
		{
			if (elems != nullptr)
			p.push(elems);
		}
		while (!p.empty())
		{
			ans->next = p.top();
			p.pop();
			ans = ans->next;
			if (ans->next)
				p.push(ans->next);
		}
		ans = head->next;
		delete head;
		return ans;
	}
};
int main()
{
	Solution s;
	vector<ListNode*> v{new ListNode(1),new ListNode(0)};
	s.mergeKLists(v);
	return 0;
}