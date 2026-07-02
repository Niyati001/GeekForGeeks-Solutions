class Solution {
  public:
    void sortedInsert(stack<int>& st, int x){
        if(st.empty() || st.top()<= x) {
            st.push(x);
            return;
        }
        int temp= st.top();
        st.pop();
        
        sortedInsert(st, x);
        st.push(temp);
    }
  
    void sortStack(stack<int> &st) {
        if(st.empty()) return;
        
        // store top element and pop
        int temp= st.top();
        st.pop();
        
        // sort remaining elements
        sortStack(st);
        
        // push temp back 
        sortedInsert(st, temp);
        
    }
};
