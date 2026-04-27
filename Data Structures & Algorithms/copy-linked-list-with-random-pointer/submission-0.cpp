/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    Node* copyRandomList_helper(Node* head, unordered_map<Node*,Node*>& node_ref){
        if(!head) return NULL;
        Node* nextNode = copyRandomList_helper(head->next, node_ref);
        if(node_ref.count(head) == 0){
            node_ref[head] = new Node(head->val);
        }
        Node* newHead = node_ref[head];
        newHead->next = nextNode;
        if(head->random){
            if(node_ref.count(head->random) == 0){
                node_ref[head->random] = new Node(head->random->val);
            }
            newHead->random = node_ref[head->random];
        }
        return newHead;
    }
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>node_ref;
        return copyRandomList_helper(head, node_ref);
    }
};