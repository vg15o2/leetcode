class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        int n = words.size();

        vector<int> dp(n, 1); // dp[i] = length of the longest valid subsequence
                              // ending at index i
        vector<int> prev(n, -1); // prev[i] = previous index in the longest
                                 // subsequence ending at i
        // Calculate longest subsequence
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i;
                 j++) { // Only consider previous indices to avoid cycles
                // Check if words[j] can come before words[i]
                if (groups[j] != groups[i] &&
                    words[j].size() == words[i].size()) {
                    // Calculate Hamming distance inline
                    int distance = 0;
                    bool validDistance = true;

                    for (int k = 0; k < words[j].size(); k++) {
                        if (words[j][k] != words[i][k]) {
                            distance++;
                            if (distance > 1) {
                                validDistance = false;
                                break;
                            }
                        }
                    }

                    // If valid and gives a longer subsequence
                    if (validDistance && distance == 1 && dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
        }

        int maxIdx = 0;
        for (int i = 1; i < n; i++) {
            if (dp[i] > dp[maxIdx]) {
                maxIdx = i;
            }
        }

        vector<string> result;
        while (maxIdx != -1) {
            result.push_back(words[maxIdx]);
            maxIdx = prev[maxIdx];
        }

        // Reverse to get the order right
        reverse(result.begin(), result.end());

        return result;
    }
};