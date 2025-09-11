class Solution {
public:
    string sortVowels(string s) {        
        vector<int> count(128, 0);  
        
        for (char c : s) {
            if (isVowel(c)) {
                count[c]++;
            }
        }
        
        string vowels = "AEIOUaeiou";
        int vowelIdx = 0;
        
        for (char& c : s) {
            if (isVowel(c)) {
                
                while (vowelIdx < vowels.length() && count[vowels[vowelIdx]] == 0) {
                    vowelIdx++;
                }
                c = vowels[vowelIdx];
                count[vowels[vowelIdx]]--;
            }
        }
        
        return s;
    }
    
private:
    inline bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};