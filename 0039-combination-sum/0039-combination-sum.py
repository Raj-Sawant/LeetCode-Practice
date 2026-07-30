class Solution(object):
    def combinationSum(self, candidates, target):
        res = []
        candidates.sort()
        
        def backtrack(start, remaining, path):
            if remaining == 0:
                res.append(path[:])
                return
            
            for i in range(start, len(candidates)):
                if candidates[i] > remaining:
                    break
                path.append(candidates[i])
                backtrack(i, remaining - candidates[i], path)
                path.pop()
        
        backtrack(0, target, [])
        return res