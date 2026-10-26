class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.length() < 2) return "";
        
        int lower = 0, upper = 0;
        for (char c : s) {
            if (islower(c)) {
                lower |= (1 << (c - 'a'));
            } else {
                upper |= (1 << (c - 'A'));
            }
        }
        
        for (int i = 0; i < s.length(); i++) {
            char c = tolower(s[i]);
            int bit = 1 << (c - 'a');
            
            if (((lower & bit) == 0) || ((upper & bit) == 0)) {
                string left = longestNiceSubstring(s.substr(0, i));
                string right = longestNiceSubstring(s.substr(i + 1));
                
                return left.length() >= right.length() ? left : right;
            }
        }
        
        return s;
    }
};