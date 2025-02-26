## 1749 Maximum Absolute Sum of Any Subarray

### Problem Statement
Given an integer array `nums`, the **absolute sum** of a subarray `[nums[l], nums[l+1], ..., nums[r-1], nums[r]]` is `abs(nums[l] + nums[l+1] + ... + nums[r-1] + nums[r])`.

Return the maximum absolute sum of any (possibly empty) subarray of `nums`.

### Optimized Approach
We can solve this problem in **O(n) time complexity** using **Kadane’s Algorithm**. We maintain two running sums:
- `max_sum`: Tracks the maximum subarray sum.
- `min_sum`: Tracks the minimum subarray sum.

The result is the maximum absolute value between `max_sum` and `min_sum`.

### C++ Solution
```cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum = 0, min_sum = 0, curr_max = 0, curr_min = 0;
        
        for (int num : nums) {
            curr_max = max(num, curr_max + num);
            max_sum = max(max_sum, curr_max);
            
            curr_min = min(num, curr_min + num);
            min_sum = min(min_sum, curr_min);
        }
        
        return max(abs(max_sum), abs(min_sum));
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, -3, 2, 3, -4};
    cout << "Output: " << sol.maxAbsoluteSum(nums1) << endl; // Output: 5
    
    vector<int> nums2 = {2, -5, 1, -4, 3, -2};
    cout << "Output: " << sol.maxAbsoluteSum(nums2) << endl; // Output: 8
    
    return 0;
}
```

### Explanation
1. **Iterate** through `nums` while maintaining:
   - `curr_max`: Maximum sum subarray ending at current index.
   - `curr_min`: Minimum sum subarray ending at current index.
2. **Update** `max_sum` and `min_sum` based on `curr_max` and `curr_min`.
3. **Return** `max(abs(max_sum), abs(min_sum))` to get the maximum absolute sum.

### Complexity Analysis
- **Time Complexity:** `O(n)`, since we traverse the array once.
- **Space Complexity:** `O(1)`, as we use only a few variables.

### Edge Cases Considered
✔ Single element array.
✔ All positive or all negative numbers.
✔ Large constraints.

### Alternative Approach
Using **prefix sums** and computing maximum/minimum prefix sum differences is possible but has `O(n^2)` complexity in brute force, making Kadane’s Algorithm the optimal choice.
