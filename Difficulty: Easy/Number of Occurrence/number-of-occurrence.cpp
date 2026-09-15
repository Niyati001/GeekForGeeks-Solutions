class Solution {
public:
    int firstOccurrence(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                ans = mid;
                right = mid - 1;       // search left
            }
            else if (arr[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }

    int lastOccurrence(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                ans = mid;
                left = mid + 1;        // search right
            }
            else if (arr[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }

    int countFreq(vector<int>& arr, int target) {
        int first = firstOccurrence(arr, target);

        // Target not present
        if (first == -1)
            return 0;

        int last = lastOccurrence(arr, target);

        return last - first + 1;
    }
};