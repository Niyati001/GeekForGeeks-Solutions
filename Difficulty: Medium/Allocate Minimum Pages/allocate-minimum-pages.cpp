class Solution {
public:

    bool canAllocate(vector<int>& arr, int k, long long maxPages) {

        int students = 1;
        long long pages = 0;

        for (int book : arr) {

            // Single book itself exceeds the limit
            if (book > maxPages)
                return false;

            if (pages + book <= maxPages) {
                // Give this book to current student
                pages += book;
            }
            else {
                // Give books to next student
                students++;
                pages = book;

                if (students > k)
                    return false;
            }
        }

        return true;
    }

    int findPages(vector<int>& arr, int k) {

        int n = arr.size();

        // Not enough books for every student
        if (k > n)
            return -1;

        long long left = *max_element(arr.begin(), arr.end());

        long long right = 0;
        for (int pages : arr)
            right += pages;

        long long ans = right;

        while (left <= right) {

            long long mid = left + (right - left) / 2;

            if (canAllocate(arr, k, mid)) {
                // Possible → try smaller maximum
                ans = mid;
                right = mid - 1;
            }
            else {
                // Not possible → need a larger maximum
                left = mid + 1;
            }
        }

        return ans;
    }
};