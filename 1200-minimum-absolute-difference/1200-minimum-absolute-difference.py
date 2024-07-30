class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        absDiff = math.inf
        ret = []
        
        for i in range(len(arr) - 1):
            diff = abs(arr[i+1] - arr[i])
            if diff < absDiff:
                absDiff = diff
        
        for i in range(len(arr) - 1):
            diff = abs(arr[i+1] - arr[i])
            if diff == absDiff:
                ret.append([arr[i], arr[i+1]])
        
        return ret
        