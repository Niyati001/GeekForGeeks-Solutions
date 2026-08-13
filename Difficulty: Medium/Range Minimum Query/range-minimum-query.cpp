class Solution {
  public:
    vector<int> seg;
    
    void build(int node, int low, int high, vector<int>& arr){
        if(low== high){
            seg[node]= arr[low];
            return;
        }
        
        int mid= low+ (high- low)/2;
        
        build(2*node, low, mid, arr);
        build(2*node+1, mid+1, high, arr);
        
        seg[node]= min(seg[2*node], seg[2*node+1]);
    }
    
    int query(int node, int low, int high, int l, int r){
        if(high< l || low> r)
            return INT_MAX;
            
        if(low>=l && r>= high)
            return seg[node];
            
        int mid= low+ (high- low)/2;
        
        int left= query(2*node, low, mid, l, r);
        int right= query(2*node+1, mid+1, high, l , r);
        
        return min(left, right);
    }
    
    vector<int> rangeMinQuery(vector<int>& arr, vector<vector<int>>& queries) {
        int n= arr.size();
        
        seg.resize(4*n);
        
        build(1, 0, n-1, arr);
        
        vector<int> ans;
        
        for(auto q: queries){
            int l= q[0];
            int r= q[1];
            
            ans.push_back(query(1, 0, n-1, l, r));
        }
        return ans;
    }
};