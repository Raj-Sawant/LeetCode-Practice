class Solution:
    def areNumbersAscending(self, s):
        prev = None
        
        for token in s.split():
            if token.isdigit():
                curr = int(token)
                if prev is not None and curr <= prev:
                    return False
                prev = curr
        
        return True