class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        // code here
        unordered_set<int> st(arr.begin(), arr.end());
        int longest=0;;
        
        for(int x: st){
            if(st.find(x-1)== st.end()){
                int curr=x;
                int len=1;
                
                while(st.find(curr+1)!= st.end()){
                    curr++;
                    len++;
                }
                longest= max(longest, len);
            }
        }
        return longest;
    }
};