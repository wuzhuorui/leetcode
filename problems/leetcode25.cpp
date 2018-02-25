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
class Solution {
public:
	ListNode * reverseKGroup(ListNode* head, int k) {
		ListNode* cur = head;
		ListNode* ans,*tail = findNext(cur, k);
		ans = tail;
		if (!ans)return head;
		while (tail)
		{
			ListNode* pre = tail->next;
			ListNode* end = tail->next;
			ListNode* itehead = cur;
			while (cur != end)
			{
				ListNode* newcur = cur->next;
				cur->next = pre;
				pre = cur;
				cur = newcur;
			}
			tail = findNext(cur, k);
			if (tail)
				itehead->next = tail;
		}
		return ans;
	}
	ListNode* findNext(ListNode* node, int k)
	{
		ListNode* next = node;
		while (next && k > 1)
		{
			next = next->next;
			k--;
		}
		return next;
	}
};
int main()
{
	Solution s;
	ListNode a(1);
	ListNode b(2);
	a.next = &b;
	ListNode c(3);
	b.next = &c;
	ListNode d(4);
	c.next = &d;
	ListNode e(5);
	d.next = &e;
	s.reverseKGroup(&a,2);
	return 0;
}