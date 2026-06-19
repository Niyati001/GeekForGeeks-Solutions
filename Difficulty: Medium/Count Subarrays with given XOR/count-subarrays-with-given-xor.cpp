class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        mp[0]=1;
        
        long count=0;
        int xr=0;
        
        for(int num: arr){
            xr^= num;
            int need= xr^k;
            
            count+= mp[need];
            mp[xr]++;
        }
        return count;
    }
};