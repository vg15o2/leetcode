class Solution {
public:
    int maxFreqSum(std::string s) {
        std::unordered_map<char, int> freq;
        std::string vowels = "aeiou";
        
        // Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        int maxVowelFreq = 0;
        int maxConsonantFreq = 0;

        for (auto& [ch, count] : freq) {
            if (vowels.find(ch) != std::string::npos) {
                maxVowelFreq = std::max(maxVowelFreq, count);
            } else {
                maxConsonantFreq = std::max(maxConsonantFreq, count);
            }
        }

        return maxVowelFreq + maxConsonantFreq;
    }
};