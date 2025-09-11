class Solution {
public:
    string sortVowels(string s) {
        vector<int> count(128, 0);  // O(1) space
        
        // Count vowels
        for (char c : s) {
            if (isVowel(c)) count[c]++;
        }
        
        // Reconstruct with sorted vowels
        string vowels = "AEIOUaeiou";
        int vowelIdx = 0;
        
        for (char& c : s) {
            if (isVowel(c)) {
                while (count[vowels[vowelIdx]] == 0) vowelIdx++;
                c = vowels[vowelIdx];
                count[vowels[vowelIdx]]--;
            }
        }
        return s;
    }
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};    