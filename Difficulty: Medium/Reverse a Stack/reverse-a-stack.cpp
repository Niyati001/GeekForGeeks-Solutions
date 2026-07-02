class Solution {
  public:
    void insertBottom(stack<int>&st, int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        
        int temp= st.top();
        st.pop();
        
        insertBottom(st, x);
        
        st.push(temp);
        
    }
  
    void reverseStack(stack<int> &st) {
        if(st.empty()) return;
        
        int temp= st.top();
        st.pop();
        
        reverseStack(st);
        insertBottom(st, temp);
        
    }
};