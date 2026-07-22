class Solution:
    def myAtoi(self, s):
        s = s.lstrip()
        
        if not s:
            return 0
        
        sign = 1
        idx = 0
        if s[0] == '-':
            sign = -1
            idx = 1
        elif s[0] == '+':
            idx = 1
        
        result = 0
        for i in range(idx, len(s)):
            if not s[i].isdigit():
                break
            result = result * 10 + int(s[i])
        
        result = sign * result

        if result < -2147483648:
            return -2147483648
        if result > 2147483647:
            return 2147483647
            
        return result