class Solution {
  public:
    bool canPlace(vector<int>& arr, int k, int dist){
        int cows=1;
        int lastPosition= arr[0];
        
        for(int i=1; i<arr.size(); i++){
            if(arr[i]- lastPosition>= dist){
                cows++;
                lastPosition= arr[i];
            }
            if(cows>= k)
                return true;
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        
        int left=1;
        int right= arr.back()- arr.front();
        
        int ans=0;
        
        while(left<= right){
            int mid= left+ (right- left)/2;
            
            if(canPlace(arr,k, mid)){
                ans= mid;
                left= mid+1;
            }
            else
                right= mid-1;
        }
        return ans;
    }
};