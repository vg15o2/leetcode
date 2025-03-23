class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
        // Graph using adjacency list
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            adj[u].emplace_back(v, time);
            adj[v].emplace_back(u, time);
        }
        
        // Min-heap (priority queue) for Dijkstra’s algorithm
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        
        // Start from node 0
        pq.emplace(0, 0);
        dist[0] = 0;
        ways[0] = 1;
        
        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();
            
            if (currDist > dist[node]) continue;
            
            for (auto& [neighbor, time] : adj[node]) {
                long long newDist = currDist + time;
                
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    ways[neighbor] = ways[node];  // Reset count
                    pq.emplace(newDist, neighbor);
                } else if (newDist == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }
        
        return ways[n - 1];
    }
};
