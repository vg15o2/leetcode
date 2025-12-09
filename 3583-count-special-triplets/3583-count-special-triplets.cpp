class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        long long MOD = 1e9 + 7;
        int n = nums.size();
    
        int freq_array_size = 2 * 100000 + 1;
        
        vector<long long> left_counts(freq_array_size, 0);
        vector<long long> right_counts(freq_array_size, 0);
        
        for (int num : nums) {
            right_counts[num] += 1;
        }
        
        long long total_triplets = 0;
        
        for (int val_j : nums) {
            right_counts[val_j] -= 1;
            
            int target_val = 2 * val_j;
            
            long long count_i = left_counts[target_val];
            long long count_k = right_counts[target_val];
                
            long long term = count_i * count_k;
            total_triplets = (total_triplets + term) % MOD;
            
            left_counts[val_j] += 1;
        }
        
        return (int)total_triplets;
    }
};