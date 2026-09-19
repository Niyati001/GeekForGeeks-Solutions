class Solution {
  public:
    struct cmp{
        bool operator()(vector<int>& a, vector<int>& b){
            return a[0]> b[0];
        }
    };
    
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        
        for(int i=0; i<mat.size(); i++){
            if(!mat[i].empty())
                pq.push({mat[i][0], i, 0});
        }
        
        vector<int> ans;
        
        while(!pq.empty()){
            auto curr= pq.top();
            pq.pop();
            
            int value= curr[0];
            int row= curr[1];
            int col= curr[2];
            
            ans.push_back(value);
            
            if(col+ 1< mat[row].size()){
                pq.push({mat[row][col+1], row, col+1});
            }
        }
        return ans;
    }
};