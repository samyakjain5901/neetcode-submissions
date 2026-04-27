class Node {
    public:
        Node *next, *prev;
        int key, val;

        Node(int k, int value){
            key = k;
            val = value;
            next = NULL;
            prev = NULL;
        }
};

class LRUCache {
    Node *head, *tail;
    unordered_map<int,Node*>lookup;
    int size, cap;

    void deleteNode(Node *node){
        if(node->next && node->prev){
            node->prev->next = node->next;
            node->next->prev = node->prev;
            
        } else if(node->next){
            head = node->next;
            head->prev = NULL;
        } else if(node->prev){
            tail = node->prev;
            tail->next = NULL;
        } else{
            head = tail = NULL;
        }
        node->next = node->prev = NULL;
        delete node;
    }

    void addNode(Node *node){
        if(!head){
            head = node;
            tail = node;
        } else {
            head->prev = node;
            node->next = head;
            head = node;
        }
    }

public:
    LRUCache(int capacity) {
        head = NULL;
        tail = NULL;
        size = 0;
        cap = capacity;
    }
    
    int get(int key) {
        if(lookup.count(key) > 0){
            int value = lookup[key]->val;
            Node *node = new Node(key, value);
            deleteNode(lookup[key]);
            addNode(node);
            lookup[key] = node;
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(lookup.count(key) == 0 && size == cap){
            lookup.erase(tail->key);
            deleteNode(tail);
            size--;
        } else if(lookup.count(key) > 0){
            deleteNode(lookup[key]);
            lookup.erase(key);
            size--;
        }
        Node *node = new Node(key, value);
        addNode(node);
        size++;
        lookup[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */