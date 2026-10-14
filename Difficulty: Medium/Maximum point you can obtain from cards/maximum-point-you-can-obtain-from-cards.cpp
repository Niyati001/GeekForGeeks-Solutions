class Solution {
  public:
    int maxScore(vector<int>& cardPoints, int k) {
        // code here.
        int n= cardPoints.size();
        int total=0;
        
        for(int x: cardPoints)
            total+=x;
            
        if(k==n) return total;
        
        int windowSize= n-k;
        int windowSum=0;
        
        for(int i=0; i<windowSize; i++)
            windowSum+= cardPoints[i];
            
        int minSum= windowSum;
        
        for(int i= windowSize; i<n; i++){
            windowSum+= cardPoints[i];
            windowSum-= cardPoints[i- windowSize];
            
            minSum= min(minSum, windowSum);
        }
        return total- minSum;
    }
};
