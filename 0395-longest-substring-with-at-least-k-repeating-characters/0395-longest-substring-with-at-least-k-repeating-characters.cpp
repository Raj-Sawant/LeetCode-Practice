class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxLen = 0;
        int n = s.length();
        
        for (int uniqueTarget = 1; uniqueTarget <= 26; uniqueTarget++) {
            int count[26] = {0};
            int left = 0;
            int unique = 0;      
            int atLeastK = 0;    
            
            for (int right = 0; right < n; right++) {
                int idx = s[right] - 'a';
                
                if (count[idx] == 0) unique++;
                count[idx]++;
                if (count[idx] == k) atLeastK++;
                
                while (unique > uniqueTarget) {
                    int leftIdx = s[left] - 'a';
                    if (count[leftIdx] == k) atLeastK--;
                    count[leftIdx]--;
                    if (count[leftIdx] == 0) unique--;
                    left++;
                }
                
                if (unique == atLeastK) {
                    maxLen = max(maxLen, right - left + 1);
                }
            }
        }
        
        return maxLen;
    }
};