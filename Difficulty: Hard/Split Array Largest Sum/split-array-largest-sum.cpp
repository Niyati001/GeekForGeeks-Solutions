class Solution {
  public:
    bool canSplit(vector<int>& arr, int k, long long limit){
        int parts=1;
        long long currSum=0;
        
        for(int x: arr){
            if(currSum+ x<= limit)
                currSum+= x;
            else{
                parts++;
                currSum=x;
            }
        }
        return parts<=k;
    }
    
    int splitArray(vector<int>& arr, int k) {
        // code here
        long long low= *max_element(arr.begin(), arr.end());
        long long high=0;
        
        for(int x: arr)
            high+=x;
            
        while(low<high){
            long long mid= low+ (high- low)/2;
            
            if(canSplit(arr, k, mid))
                high= mid;
            else
                low= mid+1;
        }
        return low;
    }
};