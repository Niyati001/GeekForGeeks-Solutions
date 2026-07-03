class Solution {
  public:
    int minCost(vector<int>& height) {
        int n= height.size();
        
        int prev2= 0;
        int prev= abs(height[1]- height[0]);
        
        for(int i=2; i<n; i++){
            int oneJump= prev+ abs(height[i]- height[i-1]);
            int twoJump= prev2+ abs(height[i]- height[i-2]);
            
            int curr= min(oneJump, twoJump);
            
            prev2= prev;
            prev= curr;
        }
        return (n==1)? 0: prev;
    }
};