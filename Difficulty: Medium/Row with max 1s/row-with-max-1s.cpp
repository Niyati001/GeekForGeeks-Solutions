// User function template for C++
class Solution {
  public:
    int lowerBound(vector<int> &arr){
        int low=0;
        int high= arr.size()-1;
        int ans=arr.size();
        
        while(low<= high){
            int mid= low+ (high-low)/2;
            
            if(arr[mid]== 1){
                ans=mid;
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return ans;
    }
    
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n= arr.size();
        int m= arr[0].size();
        
        int count_max=0;
        int index=-1;
        
        for(int i=0; i<n; i++){
            int cnt_ones= m- lowerBound(arr[i]);
            if(cnt_ones>count_max){
                count_max= cnt_ones;
                index=i;
            }
        }
        return index;
    }
};