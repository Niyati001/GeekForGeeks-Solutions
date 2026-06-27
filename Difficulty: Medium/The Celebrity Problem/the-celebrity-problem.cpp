class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int cand=0;
        int n= mat.size();
        
        for(int i=1; i< mat.size(); i++){
            if(mat[cand][i])
                cand=i;
        }
        
        // candidate should not know anyone
        for(int i=0; i< n; i++){
            if(i!= cand && mat[cand][i]== 1) return -1;
        }
        
        // everyone should know cand
        for(int i=0; i< n; i++){
            if(i!= cand && mat[i][cand]== 0) return -1; 
        }
        return cand;
    }
};