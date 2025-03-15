class Solution {
 public:
  int minCapability(std::vector<int>& nums, int k) {
    int l = *std::min_element(nums.begin(), nums.end()); // Using standard library to find the minimum
    int r = *std::max_element(nums.begin(), nums.end()); // Using standard library to find the maximum

    while (l < r) {
      const int m = l + (r - l) / 2;  // To prevent overflow
      if (numStolenHouses(nums, m) >= k)
        r = m;  // If we can steal enough houses, try a smaller capacity
      else
        l = m + 1;  // Otherwise, increase capacity
    }

    return l;
  }

 private:
  int numStolenHouses(const std::vector<int>& nums, int capacity) {
    int stolenHouses = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] <= capacity) {
        ++stolenHouses;
        i++;  // Skip the next house since you can't steal two consecutive houses
      }
    }
    return stolenHouses;
  }
};