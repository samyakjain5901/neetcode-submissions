class KthLargest {
    priority_queue<int,vector<int>,greater<int>>pq;
    int idx;
public:
    KthLargest(int k, vector<int>& nums) {
        idx = k;
        for(auto ele: nums){
            pq.push(ele);
            if(pq.size() > k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > idx){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */