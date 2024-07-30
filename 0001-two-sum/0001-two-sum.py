class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        i = 0
        for num in nums:
            if num in seen.keys():
                seen[num].append(i)
            else:
                seen[num] = [i]
            i += 1
        
        i = 0
        while (i < len(nums) - 1):
            cur = target - nums[i]
            if cur in seen.keys():
                if cur == nums[i] and len(seen[cur]) > 1:
                    return [seen[cur][0], seen[cur][1]]
                elif cur != nums[i]:
                    return [i, seen[cur][0]]
            
            i += 1