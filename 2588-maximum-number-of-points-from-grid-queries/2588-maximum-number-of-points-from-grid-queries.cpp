class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<int> result(queries.size(), 0);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        vector<pair<int, int>> queryWithIndex;
        
        // Store queries with their original indices
        for (int i = 0; i < queries.size(); i++) {
            queryWithIndex.push_back({queries[i], i});
        }
        sort(queryWithIndex.begin(), queryWithIndex.end()); // Sort queries in ascending order
        
        minHeap.push({grid[0][0], {0, 0}}); // Start from (0,0)
        visited[0][0] = true;
        
        int points = 0;
        int index = 0;

        for (auto& [queryValue, queryIndex] : queryWithIndex) {
            // Expand BFS while the top of the heap has a value < queryValue
            while (!minHeap.empty() && minHeap.top().first < queryValue) {
                auto [value, position] = minHeap.top();
                minHeap.pop();
                points++;

                int r = position.first, c = position.second;
                for (auto& dir : directions) {
                    int nr = r + dir.first, nc = c + dir.second;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                        minHeap.push({grid[nr][nc], {nr, nc}});
                        visited[nr][nc] = true;
                    }
                }
            }
            result[queryIndex] = points;
        }
        
        return result;
    }
};
