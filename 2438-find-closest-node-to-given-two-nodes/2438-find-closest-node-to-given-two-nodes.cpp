class Solution {
 public:
  int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    const vector<int> dist1 = getDistances(edges, node1);
    const vector<int> dist2 = getDistances(edges, node2);
    
    int ans = -1;
    int minDist = INT_MAX;

    for (int i = 0; i < edges.size(); ++i) {
      if (dist1[i] != -1 && dist2[i] != -1) {
        int maxDist = max(dist1[i], dist2[i]);
        if (maxDist < minDist || (maxDist == minDist && i < ans)) {
          minDist = maxDist;
          ans = i;
        }
      }
    }

    return ans;
  }

 private:
  vector<int> getDistances(const vector<int>& edges, int start) {
    vector<int> dist(edges.size(), -1);
    int d = 0;
    while (start != -1 && dist[start] == -1) {
      dist[start] = d++;
      start = edges[start];
    }
    return dist;
  }
};
