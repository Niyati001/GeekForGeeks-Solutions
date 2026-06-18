class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        int n= mat.size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        for(int i=0; i<n; i++){
            pq.push({mat[i][0], i, 0});
        }
        vector<int> ans;
        while(!pq.empty()){
            auto curr= pq.top();
            pq.pop();
            
            int val= curr[0];
            int row= curr[1];
            int col= curr[2];
            
            ans.push_back(val);
            
            if(col+1< mat[row].size()){
                pq.push({mat[row][col+1], row, col+1});
            }
        }
        return ans;
    }
};