class Solution:
    def maxProduct(self, n):
        digits = str(n)
        
        if len(digits) < 2:
            return 0
        
        max1 = max2 = -1
        
        for digit in digits:
            d = int(digit)
            if d > max1:
                max2 = max1
                max1 = d
            elif d > max2:
                max2 = d
        
        return max1 * max2