class Solution {
  public:
    void replaceWithRank(vector<int>& arr) {
        int n= arr.size();
        
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({arr[i], i});
        }
        
        sort(v.begin(), v.end());
        for(int rank=0; rank<n; rank++){
            arr[v[rank].second]= rank;
        }
    }
};