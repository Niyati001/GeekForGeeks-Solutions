class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        int n= arr.size()-1;
        priority_queue<int> pq;
        
        for(int a: arr){
            pq.push(a);
            if(pq.size()> k){
                pq.pop();
            }
        }
        
        return pq.top();
    }
};