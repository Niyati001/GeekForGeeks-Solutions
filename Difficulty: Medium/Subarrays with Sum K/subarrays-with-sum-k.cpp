class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        
        int sum=0;
        int count=0;
        
        mp[0]= 1;
        
        for(int num: arr){
            sum+= num;
            
            if(mp.find(sum-k)!= mp.end()){
                count+= mp[sum-k];
            }
            
            mp[sum]++;
        }
        return count;
    }
};