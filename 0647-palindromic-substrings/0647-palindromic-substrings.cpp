class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            count += expandAroundCenter(s, i, i);
            
            count += expandAroundCenter(s, i, i + 1);
        }
        
        return count;
    }
    
private:
    int expandAroundCenter(string& s, int left, int right) {
        int count = 0;
        int n = s.length();
        
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        
        return count;
    }
};