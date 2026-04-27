class Node {
public:
    int val;
    Node* next;
    Node(int data){
        val = data;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;
    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int get(int index) {
        if(size <= index){
            return -1;
        }
        Node* cur_node = head;
        for(int i=0;i<index;i++){
            cur_node = cur_node->next;
        }
        return cur_node->val;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            tail = newNode;
        } else{
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);
        if(!tail){
            head = newNode;
            tail = newNode;
        } else{
            tail->next = newNode;
            tail = tail->next;
        }
        size++;
    }

    bool remove(int index) {
        if(size <= index){
            return false;
        }
        if(index == 0){
            if(size == 1){
                head = NULL;
                tail = NULL;
            } else{
                head = head->next;
            }
        } else {
            Node* cur_node = head;
            for(int i=0;i<index-1;i++){
                cur_node = cur_node->next;
            }
            cur_node->next = cur_node->next->next;
            if(index == size-1){
                tail = cur_node;
            }
        }
        size--;
        return true;
    }

    vector<int> getValues() {
        vector<int>vals;
        Node* newNode = head;
        while(newNode){
            vals.push_back(newNode->val);
            newNode = newNode->next;
        }
        return vals;
    }
};
