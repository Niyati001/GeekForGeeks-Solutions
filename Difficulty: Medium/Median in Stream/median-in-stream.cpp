class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;
        
        vector<double> res;
        
        for(int i=0; i<arr.size(); i++){
            left.push(arr[i]);
            
            int temp= left.top();
            left.pop();
            right.push(temp);
            
            
            if(right.size()> left.size()){
                temp= right.top();
                right.pop();
                left.push(temp);
            }
            
            double median;
            
            if(left.size()!= right.size()){
                median= left.top();
            }
            else{
                median= (double)(left.top()+ right.top())/2;
            }
            res.push_back(median);
        }
        return res;
    }
};
