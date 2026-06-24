class Solution {
  public:
    static bool comp(pair<int, int> &a, pair<int, int> &b){
        return (double)a.first/a.second > (double) b.first/b.second;
    }
    
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n= val.size();
        
        vector<pair<int, int>> arr;
        for(int i=0; i< n; i++){
            arr.push_back({val[i], wt[i]});
        }
        sort(arr.begin(), arr.end(), comp);
        
        double ans=0;
        
        for(int i=0; i<n && capacity>0 ; i++){
            if(arr[i].second<= capacity){
                ans+= arr[i].first;
                capacity-= arr[i].second;
            }
            else{
                ans+= ((double) arr[i].first/ arr[i].second)* capacity;
                break;
            }
        }
        return ans;
    }
};
