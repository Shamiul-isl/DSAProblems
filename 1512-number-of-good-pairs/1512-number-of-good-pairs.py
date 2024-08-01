class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:        
        pairCount = 0
        # TODO: Write your code here
        seen = {}
        for i in range(len(nums)):
            if nums[i] in seen:
                seen[nums[i]].append(i)
            else:
                seen[nums[i]] = [i]

        for key in seen.keys():
            curLen = len(seen[key])
            for index in range(curLen):
                pairCount += (curLen - (index + 1))

        return pairCount
