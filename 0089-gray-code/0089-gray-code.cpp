class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.reserve(1 << n);  
        result.push_back(0);
        
        for (int i = 0; i < n; i++) {
            int size = result.size();
            int bit = 1 << i;  
            
            for (int j = size - 1; j >= 0; j--) {
                result.push_back(result[j] | bit);
            }
        }
        
        return result;
    }
};