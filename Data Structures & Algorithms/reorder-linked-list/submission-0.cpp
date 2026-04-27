/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverseLL(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode* interTail = head->next;
        ListNode* revHead = reverseLL(interTail);
        interTail->next = head;
        head->next = NULL;
        return revHead;
    }
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next){
            return;
        }
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* midHead = slow->next;
        slow->next = NULL;
        ListNode* revHead = reverseLL(midHead);
        ListNode* resHead = head, *resTail = head;
        head = head->next;
        while(head && revHead){
            resTail->next = revHead;
            resTail = resTail->next;
            revHead = revHead->next;
            resTail->next = head;
            resTail = resTail->next;
            head = head->next;
        }
        while(revHead){
            resTail->next = revHead;
            resTail = resTail->next;
            revHead = revHead->next;
        }
    }
};