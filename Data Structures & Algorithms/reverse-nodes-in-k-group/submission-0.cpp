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
        ListNode *tail = head->next;
        ListNode *reverseHead = reverseLL(head->next);
        tail->next = head;
        head->next = NULL;
        return reverseHead;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || !head){
            return head;
        }
        ListNode *node = head;
        int i = 1;
        while(node->next && i < k){
            node = node->next;
            i++;
        }
        if(i >= k){
            ListNode *nextHead = node->next;
            node->next = NULL;
            ListNode *resHead = reverseLL(head);
            head->next = reverseKGroup(nextHead, k);
            return resHead;
        } else{
            return head;
        }
    }
};