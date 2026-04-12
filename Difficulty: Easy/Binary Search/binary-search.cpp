class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        int s=0;
        int e= arr.size()-1;
        int ans=-1;

        while(s<=e){
            int mid= s+ (e-s)/2;
            if(arr[mid]== k){
                ans= mid;
                e= mid-1;
            }
            
            else if(arr[mid]> k){
                e= mid-1;
            }
            else{
                s= mid+1;
            }
        }
        return ans;
    }
};