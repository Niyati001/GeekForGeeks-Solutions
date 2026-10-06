class Solution {
  public:
    bool isValid(vector<vector<int>>& mat) {
        // code here
        bool row[9][10]= {};
        bool col[9][10]= {};
        bool box[9][10]= {};
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                int num= mat[i][j];
                
                if(num==0) continue;
                
                int boxIndex= (i/3)* 3+ (j/3);
                
                if(row[i][num] || col[j][num] || box[boxIndex][num])
                    return 0;
                    
                row[i][num]= true;
                col[j][num]= true;
                box[boxIndex][num]= true;
            }
        }
        return 1;
    }
};