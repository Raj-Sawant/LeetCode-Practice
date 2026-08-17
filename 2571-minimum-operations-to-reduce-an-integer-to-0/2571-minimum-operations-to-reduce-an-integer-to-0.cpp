class Solution {
public:
    int minOperations(int n) {
        int operations = 0;
        
        while (n > 0) {
            if ((n & (n - 1)) == 0) {
                operations++;
                break;
            }
            
            int highestPower = 1 << (31 - __builtin_clz(n));
            
            int nextPower = highestPower << 1;
            
            if (nextPower - n <= n - highestPower) {
                n = nextPower - n;
            } else {
                n = n - highestPower; 
            }
            
            operations++;
        }
        
        return operations;
    }
};