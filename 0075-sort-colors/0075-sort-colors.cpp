class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int l = 0;                // The next 0 should be placed in l.
    int r = nums.size() - 1;  // The next 2 should be placed in r.

    for (int i = 0; i <= r;)
      if (nums[i] == 0)
        swap(nums[i++], nums[l++]);
      else if (nums[i] == 1)
        ++i;
      else
        swap(nums[i], nums[r--]);
  }
};