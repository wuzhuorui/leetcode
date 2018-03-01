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

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode * rotateRight(ListNode* head, int k) {
		if (head == nullptr)return head;
		ListNode* slow;
		ListNode* fast;
		if (k == 0)return head;
		slow = fast = head;
		int count = 0;
		while (k--) {
			if (fast == nullptr) { 
				fast = head; 
				k = k % count;
			}
			fast = fast->next;
			count++;
		};
		if (fast == nullptr)return head;
		while (fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next;
		}
		ListNode* ans = slow->next;
		slow->next = fast->next;
		fast->next = head;
		return ans;
	}
};
int main() {
	Solution s;
	s.generateMatrix(4);

}