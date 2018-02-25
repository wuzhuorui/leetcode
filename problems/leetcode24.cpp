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
	ListNode * swapPairs(ListNode* head) {
		if (!head)return nullptr;
		ListNode* a = head;
		ListNode* b = a ? a->next : nullptr;
		ListNode* res = b ? b : a;
		ListNode* pre = nullptr;
		while (a && b)
		{
			a->next = b->next;
			b->next = a;
			if (pre)pre->next = b;
			pre = a;
			a = a->next;
			if (a)b = a->next;
		}
		return res;
	}
};
int main()
{
	Solution s;
	return 0;
}