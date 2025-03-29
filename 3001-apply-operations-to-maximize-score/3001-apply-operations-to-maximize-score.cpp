class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        
        // Calculate prime score for each number
        vector<int> primeScore(n);
        for (int i = 0; i < n; i++) {
            primeScore[i] = countPrimeFactors(nums[i]);
        }
        
        // Find the next greater or equal prime score to the left and right
        vector<int> left(n, -1);
        vector<int> right(n, n);
        
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && primeScore[s.top()] < primeScore[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        
        while (!s.empty()) s.pop();
        
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && primeScore[s.top()] <= primeScore[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        
        // Calculate how many subarrays each element can be the maximum prime score
        vector<pair<int, long long>> contributions;
        for (int i = 0; i < n; i++) {
            long long count = (long long)(i - left[i]) * (right[i] - i);
            contributions.push_back({nums[i], count});
        }
        
        // Sort by value in descending order
        sort(contributions.begin(), contributions.end(), [](const pair<int, long long>& a, const pair<int, long long>& b) {
            return a.first > b.first;
        });
        
        // Greedily choose the elements with highest values
        long long result = 1;
        long long remainingOps = k;
        for (auto& [value, count] : contributions) {
            long long operations = std::min(remainingOps, count);
            // Apply the power efficiently
            result = (result * power(value, operations, MOD)) % MOD;
            remainingOps -= operations;
            if (remainingOps == 0) break;
        }
        
        return result;
    }
    
private:
    // Count the number of distinct prime factors
    int countPrimeFactors(int num) {
        int count = 0;
        
        // Check divisibility by 2
        if (num % 2 == 0) {
            count++;
            while (num % 2 == 0) {
                num /= 2;
            }
        }
        
        // Check for other prime factors
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) {
                count++;
                while (num % i == 0) {
                    num /= i;
                }
            }
        }
        
        // If num > 1, it is a prime number itself
        if (num > 1) {
            count++;
        }
        
        return count;
    }
    
    // Calculate (base^exponent) % mod efficiently
    long long power(long long base, long long exponent, int mod) {
        long long result = 1;
        base = base % mod;
        
        while (exponent > 0) {
            if (exponent & 1) {
                result = (result * base) % mod;
            }
            exponent >>= 1;
            base = (base * base) % mod;
        }
        
        return result;
    }
};