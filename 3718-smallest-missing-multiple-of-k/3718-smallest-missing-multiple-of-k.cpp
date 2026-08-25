#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        int multiple = k;
        while (numSet.count(multiple)) {
            multiple += k;
        }
        
        return multiple;
    }
};