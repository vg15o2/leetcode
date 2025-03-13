class Solution {
public:
    bool isZeroArrayPossible(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0); // Difference array
        
        // Apply first k queries using the difference array
        for (int i = 0; i < k; ++i) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            diff[l] -= val;
            diff[r + 1] += val;
        }
        
        // Compute the updated nums array
        int currDecrement = 0;
        for (int i = 0; i < n; ++i) {
            currDecrement += diff[i];
            if (nums[i] + currDecrement > 0) {
                return false; // If any element remains positive, return false
            }
        }
        return true;
    }
    
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0, right = queries.size(), ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isZeroArrayPossible(nums, queries, mid)) {
                ans = mid;
                right = mid - 1; // Try for smaller k
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};