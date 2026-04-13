class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int n= mat.size();
        int m=  mat[0].size();
        int low= INT_MAX;
        int high= INT_MIN;
        
        
        for(int i=0; i<n; i++){
            low= min(low, mat[i][0]);
            high= max(high, mat[i][m-1]);
        }
        int req= (n*m)/2;
        
        while(low<= high){
            int mid= low+ (high-low)/2;
            int count=0;
            
            for(int i=0; i<n; i++){
                count+= upper_bound(mat[i].begin(), mat[i].end(), mid)- mat[i].begin();
            }
            if(count<= req){
                low= mid+1;
            }
            else{
                high= mid-1;
            }
        }
        return low;
    }
};
