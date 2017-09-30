#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <functional>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	// readble solution; 
	ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
		ListNode cache(0); 
		ListNode *back = &cache; 
		int quo = 0; 

		for (; l1 && l2; l1 = l1->next, l2 = l2->next) {
			int  sum = l1->val + l2->val + quo; 
			quo = sum / 10;
			back->next = new ListNode(sum % 10);
			back = back->next; 
		}

		for (ListNode *nback = l1 ? l1 : l2; nback; nback = nback->next) {
			int sum = nback->val + quo;
			quo = sum / 10;
			back->next = new ListNode(sum % 10);
			back = back->next;
		}

		if (quo) {
			back->next = new ListNode(quo);
			back = back->next;
		}

		return cache.next; 
	}

	// concise solution 
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode cache(0);
		ListNode *back = &cache;
		int quo = 0;

		while (l1 || l2 || quo) {
			int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + quo; 
			quo = sum / 10; 
			back->next = new ListNode(sum % 10);
			back = back->next;
			l1 = l1 ? l1->next : l1; 
			l2 = l2 ? l2->next : l2; 
		}

		return cache.next; 
	}
};

/************************* instring_sorting_linked_list *************************/
ListNode* insertionSortList(ListNode* head)
{
    ListNode *new_head = new ListNode(0);
    new_head->next = head;
    ListNode *pre = new_head, *cur = head;

    while(cur)
    {
        if(cur->next && cur->next->val < cur->val)
        {
            while(pre->next && pre->next->val < cur->next->val)
            {
                pre = pre->next;
            }
            ListNode *tmp = pre->next;
            pre->next = cur->next; // insert cur->next after pre;
            cur->next = cur->next->next;
            pre->next->next = tmp;
            pre = new_head; // move pre back to new_head;
        }
        else
        {
            cur = cur->next;
        }
    } // iterative solution; 


    ListNode *res = new_head->next;
    delete new_head;
    return res; // return head is wrong for it's changed;
}

ListNode* insertionSortList(ListNode* head)
{
    ListNode trunk(INT_MIN);
    ListNode *pre, *cur;

    while(head)
    {
        pre = &trunk;
        cur = head->next;
        while(pre->next&&pre->next->val < head->val)
        {
            pre = pre->next;
        }
        head->next = pre->next;
        pre->next = head;
        head = cur;
    }

    return trunk->next;
} // iterative solution; 

ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr || head->next == NULL)
        return head;
    ListNode *h = insertionSortList(head->next);
    if (head->val <= h->val) {  // first case
        head->next = h;
        return head;
    }
    ListNode *node = h;   // second case
    while (node->next && head->val > node->next->val)
        node = node->next;
    head->next = node->next;
    node->next = head;
    return h;
} // recursive solution; 
/************************* instring_sorting_linked_list *************************/



int main(int argc, char *argv[])
{
	ListNode ln1(2), ln2(3), ln3(4), ln4(9), ln5(5), ln6(4), ln7(6); 
	ln1.next = &ln2, ln2.next = &ln3, ln3.next = &ln4; 
	ln5.next = &ln6, ln6.next = &ln7;
	ListNode *head1 = &ln1, *head2 = &ln5; 

	Solution slt; 
	ListNode *result = slt.addTwoNumbers(head1, head2);
	for (ListNode *temp = result; temp; temp = temp->next) cout << temp->val << " "; 

	system("pause"); 
	return 0; 
}