class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int left=0;
        int  right= arr.size()-1;
        
        int ans=0;
        
        while(left< right){
            int width= right- left;
            int h= min(arr[left], arr[right]);
            
            int area= width*h;
            
            ans= max(ans, area);
            
            if(arr[left]< arr[right])
                left++;
            else
                right--;
        }
        return ans;
    }
};