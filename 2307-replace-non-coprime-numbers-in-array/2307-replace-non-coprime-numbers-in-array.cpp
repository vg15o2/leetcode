#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        
        for (int x : nums) {
            while (!st.empty()) {
                int g = gcd(st.back(), x);
                if (g == 1) break;
                x = lcm(st.back(), x);
                st.pop_back();
            }
            st.push_back(x);
        }
        
        return st;
    }
    
private:
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
};