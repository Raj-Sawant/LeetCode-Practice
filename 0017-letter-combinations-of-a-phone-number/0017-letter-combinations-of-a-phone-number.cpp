class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        
        unordered_map<char, string> phoneMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        
        vector<string> result;
        string current;
        
        backtrack(digits, 0, current, result, phoneMap);
        return result;
    }
    
private:
    void backtrack(const string& digits, int index, string& current, 
                   vector<string>& result, const unordered_map<char, string>& phoneMap) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        string letters = phoneMap.at(digits[index]);
        
        for (char letter : letters) {
            current.push_back(letter);        
            backtrack(digits, index + 1, current, result, phoneMap); 
            current.pop_back();                 
        }
    }
};