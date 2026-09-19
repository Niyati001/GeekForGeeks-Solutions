class Solution {
public:

    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> left;

        priority_queue<int, vector<int>, greater<int>> right;

        vector<double> ans;

        for(int num : arr) {
            if(left.empty() || num <= left.top()) {
                left.push(num);
            }
            else {
                right.push(num);
            }

            if(left.size() > right.size() + 1) {
                right.push(left.top());
                left.pop();
            }
            else if(right.size() > left.size() + 1) {
                left.push(right.top());
                right.pop();
            }

            // Find median
            if(left.size() == right.size()) {
                double median =
                    (left.top() + right.top()) / 2.0;

                ans.push_back(median);
            }
            else if(left.size() > right.size()) {
                ans.push_back(left.top());
            }
            else {
                ans.push_back(right.top());
            }
        }

        return ans;
    }
};