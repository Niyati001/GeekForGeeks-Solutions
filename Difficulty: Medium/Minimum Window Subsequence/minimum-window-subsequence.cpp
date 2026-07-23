class Solution {
public:
    string minWindow(string& s1, string& s2) {

        int n = s1.size();
        int m = s2.size();

        int bestLen = INT_MAX;
        int start = -1;

        int i = 0;

        while(i < n) {

            int j = 0;

            // Forward scan: find s2 as subsequence
            while(i < n) {

                if(s1[i] == s2[j])
                    j++;

                if(j == m)
                    break;

                i++;
            }


            // No subsequence found
            if(j < m)
                break;


            // i is at the end of the window
            int end = i;


            // Backward scan: minimize window
            j = m - 1;

            while(j >= 0) {

                if(s1[end] == s2[j])
                    j--;

                end--;
            }


            int windowStart = end + 1;


            // Update answer
            if(i - windowStart + 1 < bestLen) {

                bestLen = i - windowStart + 1;
                start = windowStart;
            }


            // Start next search
            i = windowStart + 1;
        }


        if(start == -1)
            return "";


        return s1.substr(start, bestLen);
    }
};