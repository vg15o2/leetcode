class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        
        // Create events for sweep line
        vector<vector<int>> start_at(n);
        for (int i = 0; i < m; i++) {
            start_at[queries[i][0]].push_back(i);
        }
        
        priority_queue<pair<int, int>> available; // max heap: (end_pos, query_idx)
        vector<int> diff(n + 1, 0); // difference array for range updates
        int current_decrease = 0;
        int used_queries = 0;
        
        for (int i = 0; i < n; i++) {
            // Update current decrease amount from difference array
            current_decrease += diff[i];
            
            // Add queries that start at position i
            for (int query_idx : start_at[i]) {
                int end_pos = queries[query_idx][1];
                available.push({end_pos, query_idx});
            }
            
            // Check if we need more decreases at position i
            int needed = nums[i] - current_decrease;
            
            // Use queries greedily (prefer those that end later)
            while (needed > 0 && !available.empty()) {
                auto [end_pos, query_idx] = available.top();
                
                // Remove queries that can't cover current position
                if (end_pos < i) {
                    available.pop();
                    continue;
                }
                
                available.pop();
                used_queries++;
                needed--;
                
                // Apply this query's effect using difference array
                diff[i]++;
                diff[end_pos + 1]--;
                current_decrease++;
            }
            
            // If still not enough, return -1
            if (needed > 0) {
                return -1;
            }
        }
        
        return m - used_queries;
    }
};