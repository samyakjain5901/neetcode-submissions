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
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* head = NULL, *tail = NULL;
        while(l1 && l2){
            if(l1->val <= l2->val){
                if(!head){
                    head = tail = l1;
                } else{
                    tail->next = l1;
                    tail = tail->next;
                }
                l1 = l1->next;
            } else{
                if(!head){
                    head = tail = l2;
                } else{
                    tail->next = l2;
                    tail = tail->next;
                }
                l2 = l2->next;
            }
        }
        if(l1) tail->next = l1;
        if(l2) tail->next = l2;
        return head;
    }

    ListNode* mergeKLists_helper(vector<ListNode*>& lists, int start, int end){
        if(start == end){
            return lists[start];
        }
        ListNode* mergedList = mergeKLists_helper(lists, start+1, end);
        ListNode* resList = merge(lists[start], mergedList);
        return resList;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int start = 0, end = lists.size()-1;
        if(start > end){
            return NULL;
        }
        return mergeKLists_helper(lists, start, end);
    }
};