class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        // Find the first positive number index using binary search
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int posCount = n - left;  // Count of positive numbers

        // Find the last negative number index using binary search
        left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int negCount = right + 1; // Count of negative numbers

        return max(posCount, negCount);
    }
};