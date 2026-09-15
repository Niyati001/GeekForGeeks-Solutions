class Solution {
public:
    int search(vector<int>& arr, int key) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Found target
            if (arr[mid] == key)
                return mid;

            // Left half is sorted
            if (arr[left] <= arr[mid]) {

                if (arr[left] <= key && key < arr[mid]) {
                    // Target is in left sorted half
                    right = mid - 1;
                }
                else {
                    // Target is in right half
                    left = mid + 1;
                }
            }

            // Right half is sorted
            else {

                if (arr[mid] < key && key <= arr[right]) {
                    // Target is in right sorted half
                    left = mid + 1;
                }
                else {
                    // Target is in left half
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};