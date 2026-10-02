class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_set<char> st;
        int left=0;
        int maxLen=0;
        
        for(int right=0; right< s.size(); right++){
            while(st.find(s[right])!= st.end()){
                st.erase(s[left]);
                left++;
            }
            
            st.insert(s[right]);
            maxLen= max(maxLen, right-left+1);
        }
        return maxLen;
    }
};
