class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        stack<int> st;
        int maxArea=0;
        int n= arr.size();
        
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || arr[i]< arr[st.top()])){
                int height= arr[st.top()];
                st.pop();
                
                int width;
                
                if(st.empty()){
                    width=i;
                }
                else{
                    width= i -st.top()-1;
                }
                maxArea= max(maxArea, height*width);
            }
            st.push(i);
        }
        return maxArea;
    }
};
