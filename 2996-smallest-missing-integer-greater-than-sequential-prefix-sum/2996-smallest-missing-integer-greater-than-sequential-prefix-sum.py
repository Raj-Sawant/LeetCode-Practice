class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        prefix_sum = nums[0]
        i = 1
        while i < len(nums) and nums[i] == nums[i-1] + 1:
            prefix_sum += nums[i]
            i += 1

        num_set = set(nums)

        missing = prefix_sum
        while missing in num_set:
            missing += 1

        return missing