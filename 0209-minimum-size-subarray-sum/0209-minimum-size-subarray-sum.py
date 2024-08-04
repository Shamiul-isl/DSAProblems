class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        smallest = 0
        windowStart, windowEnd = 0, 0
        curSum = nums[windowEnd]

        while windowEnd < len(nums):

            if curSum < target:
                windowEnd += 1
                if windowEnd < len(nums):
                    curSum += nums[windowEnd]
            elif curSum >= target:
                if smallest == 0:
                    smallest = windowEnd - windowStart + 1
                else:
                    smallest = min(smallest, windowEnd - windowStart + 1)
                curSum -= nums[windowStart]
                windowStart += 1

        return smallest