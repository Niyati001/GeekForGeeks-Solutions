class Solution {
  public:
    struct cmp{
        bool operator()(vector<int>&a, vector<int>& b){
            return a[0]> b[0];
        }
    };
    
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int count=0;
        
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        
        for(int i=0; i<mat.size(); i++){
            if(!mat[i].empty())
                pq.push({mat[i][0], i, 0});
        }
        
        while(!pq.empty()){
            auto t= pq.top();
            pq.pop();
            count++;
            
            int value= t[0];
            int row= t[1];
            int col= t[2];
            
            if(col+ 1< mat[row].size()){
                pq.push({mat[row][col+1], row, col+1});
            }
            
            if(count== k)
               return value;
        }
        return -1;
    }
};
