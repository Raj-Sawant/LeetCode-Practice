class Solution:
    def canConstruct(self, ransomNote, magazine):
        mag_counts = {}
        for char in magazine:
            mag_counts[char] = mag_counts.get(char, 0) + 1
        
        for char in ransomNote:
            if mag_counts.get(char, 0) == 0:
                return False
            mag_counts[char] -= 1
        
        return True