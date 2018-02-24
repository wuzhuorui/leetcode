#include<vector>
using std::vector;
#include<algorithm>
#include<memory>
using std::shared_ptr;
/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		ListNode* beforehead(new ListNode(0));
		beforehead->next = head;
		ListNode* fastmove = head;
		while (n--)fastmove = fastmove->next;
		ListNode* curmove = beforehead;
		while (fastmove != nullptr) {
			fastmove = fastmove->next;
			curmove = curmove->next;
		}
		ListNode* delnode = curmove->next;
		curmove->next = delnode->next;
		delete delnode;
		return beforehead->next;
	}
};

int main()
{
	Solution s;
	return 0;
}