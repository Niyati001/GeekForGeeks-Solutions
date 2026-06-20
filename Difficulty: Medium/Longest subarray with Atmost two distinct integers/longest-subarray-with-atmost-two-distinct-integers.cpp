class Solution {
  public:
    int totalElements(vector<int> &arr) {
        unordered_map<int, int> mp;
        int left=0;
        int ans=0;
        int k=2;
        
        for(int right=0; right<arr.size(); right++){
            mp[arr[right]]++;
            
            while(mp.size()>k){
                mp[arr[left]]--;
                
                if(mp[arr[left]]==0)
                    mp.erase(arr[left]);
                left++;
            }
            ans= max(ans, right-left+1);
        }
        return ans;
    }
};